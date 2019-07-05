/****************************************************************************

                                 GameTree.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/GameTree.cpp#2 $

	$NoKeywords: $

****************************************************************************/

#include "stdafx.h"

#include "GameTree.h"

#include "Move.h"
#include "GoTypes.h"
#include "GameState.h"

#include "Misc/Random.h"

#include <limits>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace
{

int const	NORMAL_DEPTH				= 4;			// Max normal search depth
int const	MAX_DEPTH					= NORMAL_DEPTH;	// Max search depth
float const RESIGN_THRESHOLD			= -100.5f;		// Value at which resigning is recommended


} // anonymous namespace

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GameTree::GameTree()
//	:
//	m_GeneratedStateCount( 0 ),
//	m_EvaluationCount( 0 ),
//	m_AlphaHitCount( 0 ),
//	m_BetaHitCount( 0 )
//#if  defined( USING_TTABLE )
//	,
//	m_TTableCheckCount( 0 ),
//	m_TTableHitCount( 0 ),
//	m_TTableUsage( 0 ),
//	m_TTableCollisionCount( 0 )
//#endif // defined( USING_TTABLE )
{

#if defined( USING_TTABLE )

	m_pTranspositionTable = new TranspositionTable;
	if ( !m_pTranspositionTable )
		throw std::bad_alloc();

#endif // defined( USING_TTABLE )
}
 


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GameTree::~GameTree()
{
#if defined( USING_TTABLE )
	delete m_pTranspositionTable;
#endif // defined( USING_TTABLE )
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GameState GameTree::MyBestMove( GameState const & s0, Stone my_color )
{
	int const depth = 1;					// The depth of this ply

	m_MyColor = my_color;
	m_YourColor = OtherColor( my_color );

	SortedGameStateVector	states( true );

	// Generate a list of all my possible responses to the specified state.

	GenerateStates( &states, s0, true, depth );
	ASSERT( !states.empty() );

	// The GenerateStates function has determined a preliminary value for
	// each state and sorted the states by value in descending order.
	
	// Find the best of the responses...I want to find the highest score

	GameState best_state;
	float best_score = -std::numeric_limits<float>::infinity();
	float worst_score = std::numeric_limits<float>::infinity();

	while ( !states.empty() )
	{
		GameState & s = states.top();

		// Revise the value of the move by searching the tree of all possible responses

		s.m_Value = OpponentAlphaBeta( s, best_score, std::numeric_limits<float>::infinity(), depth+1, NORMAL_DEPTH );

#if defined( USING_TTABLE )

		// Save the value of the state in the T-table

		m_pTranspositionTable->Update( s, MAX_DEPTH - depth );

#endif // defined( USING_TTABLE )

		// If this is the lowest score then save that for analysis

		if ( s.m_Value < worst_score )
			worst_score  = s.m_Value;

		// If this is the highest value so far then remember it (if it is checkmate, then
		// don't bother with the rest)

		if ( s.m_Value > best_score )
		{
			best_score = s.m_Value;
			best_state = s;
		}

		states.pop();
	}

	// If the value of my best move is really bad, then just resign

	if ( best_score < RESIGN_THRESHOLD )
	{
		best_state.m_Move = MOVE_RESIGN;
	}

//	m_WorstValue					 = worst_score;

//#if defined( USING_TTABLE )
//	m_TTableCheckCount				= m_pTranspositionTable->m_CheckCount;
//	m_TTableHitCount				= m_pTranspositionTable->m_HitCount;
//	m_TTableUsage					= m_pTranspositionTable->m_Usage;
//	m_TTableCollisionCount			= m_pTranspositionTable->m_CollisionCount;
//#endif // defined( USING_TTABLE )

	// Return the best move
	
	return best_state;
}


/********************************************************************************************************************/
/*																													*/
/* Find and evaluate all my possible responses to the state s0. The move I	*/
/* will make is the one with the highest value, so that is the value that	*/
/* is returned.																*/
/*																													*/
/********************************************************************************************************************/
 
float GameTree::MeAlphaBeta( GameState const & s0,
							  float alpha, float beta,
							  int depth, int last_ply )
{
	int const	quality	= MAX_DEPTH - depth;	// Quality of values at this depth

	// Generate a list of my possible responses to this state sorted descending
	// by value. They are sorted in descending order hoping that a beta cutoff
	// will occur early.
	// Note: Preliminary values of the generated states are computed by the static
	// evaluation function (SEF).

	SortedGameStateVector	response_list( true );
	GenerateStates( &response_list, s0, true, depth );
	ASSERT( !response_list.empty() );

	// Evaluate each of my responses and find the value of the best one

	GameState best_response;
	float best_score = -std::numeric_limits<float>().max();

	while ( !response_list.empty() )
	{
		GameState &	response	= response_list.top();

		// Get the value of this state by one of three methods:
		//	1. T-Table, if it is there and the quality is high enough
		//	2. static evaluation function, if this is the last ply
		//	3. search

#if defined( USING_TTABLE )

		if ( m_pTranspositionTable->Check( response, quality, &response.m_Value ) )
		{
			// Use the value from the T-table (already set by TranspositionTable::Check)
		}
		else

#endif // defined( USING_TTABLE )

		if ( depth == last_ply )
		{
			// Use the static evaluation function value (already set by GenerateStates)

#if defined( USING_TTABLE )

			// Save the value of the state in the T-table

			m_pTranspositionTable->Update( response, quality );

#endif // defined( USING_TTABLE )

		}
		else
		{
			response.m_Value = OpponentAlphaBeta( response, alpha, beta, depth+1, last_ply );

#if defined( USING_TTABLE )

			// Save the value of the state in the T-table

			m_pTranspositionTable->Update( response, quality );

#endif // defined( USING_TTABLE )

		}

		// Determine if this response's value is the best so far

		if ( response.m_Value > best_score )
		{
			// Save it

			best_score = response.m_Value;
			best_response = response;

			// alpha-beta pruning (beta cutoff check)

			// Here's how it works. I am looking for the highest value, and
			// my opponent is looking for the lowest value. The 'beta' passed
			// in to this function is the value of my opponent's best move
			// found so far. If the value of this response is higher than
			// the beta, then my opponent won't make this move because he can
			// make a move that has a value of beta (which is lower and therefore
			// better for him). So, there is no reason to continue looking
			// since my opponent won't make this move.

			if ( best_score > beta )
			{
				// Record the number of responses pruned by this cutoff

//				m_BetaHitCount += ( response_list.size() - 1 );

				// Beta cutoff

				break;
			}

			// alpha-beta pruning (alpha)

			// Here's how it works. I am looking for the highest value, and
			// my opponent is looking for the lowest value. The 'alpha' passed
			// in to this functionis the value of my best move found so far.
			// If the value of this response is higher, then obviously, this
			// is a better move. The alpha value is passed to my opponent's
			// move evaluator so that if he finds a response to my best
			// response with a lower value, he won't bother continuing because
			// he knows that I already have a better move. So, keep track of the
			// value of my best move so far.

			if ( best_score > alpha )
				alpha = best_score;
		}

		response_list.pop();
	}

	return best_score;
}


/********************************************************************************************************************/
/*																													*/
/* Find and evaluate all my opponent's possible responses to the state s0.	*/
/* The move my opponent will make is the one with the lowest value, so that	*/
/* is the value that is returned.											*/
/*																													*/
/********************************************************************************************************************/
 
float GameTree::OpponentAlphaBeta( GameState const & s0,
									float alpha, float beta,
									int depth, int last_ply )
{
	int const	quality	= MAX_DEPTH - depth;	// Quality of values at this depth

	// Generate a list of my possible responses to this state sorted ascending
	// by value. They are sorted in ascending order hoping that a alpha cutoff
	// will occur early.
	// Note: Preliminary values of the generated states are computed by the static
	// evaluation function (SEF).

	SortedGameStateVector	response_list( false );
	GenerateStates( &response_list, s0, false, depth );
	ASSERT( !response_list.empty() );

	// Find the best of the responses...my opponent chooses the lowest score

	GameState best_state;
	float best_score = std::numeric_limits<float>().max();

	while ( !response_list.empty() )
	{
		GameState & response = response_list.top();

		// Set the value of this state by one of three methods:
		//	1. T-Table, if it is there and the quality is high enough
		//	2. static evaluation function, if this is the last ply
		//	3. search


#if defined( USING_TTABLE )

		if ( m_pTranspositionTable->Check( response, quality, &response.m_Value ) )
		{
			// Use the value from the T-table (already set by TranspositionTable::Check)
		}
		else

#endif // defined( USING_TTABLE )

		if ( depth == last_ply )
		{
			// Use the static evaluation function value (already set by GenerateStates)

#if defined( USING_TTABLE )

			// Save the value of the state in the T-table

			m_pTranspositionTable->Update( response, quality );

#endif // defined( USING_TTABLE )

		}
		else
		{
			response.m_Value = MeAlphaBeta( response, alpha, beta, depth+1, last_ply );

#if defined( USING_TTABLE )

			// Save the value of the state in the T-table

			m_pTranspositionTable->Update( response, quality );

#endif // defined( USING_TTABLE )

		}

		if ( response.m_Value < best_score )
		{
			best_score = response.m_Value;
			best_state = response;

			// alpha-beta pruning (alpha cutoff check)

			// Here's how it works. I am looking for the highest value, and
			// my opponent is looking for the lowest value. The 'alpha' passed
			// in to this function is the value of my best move
			// found so far. If the value of this response is lower than
			// the alpha, then I won't make this move because I can
			// make a move that has a value of alpha (which is higher and therefore
			// better for me). So, there is no reason to continue looking
			// since I won't make this move.

			if ( best_score < alpha )
			{
				// Record the number of responses pruned by this alpha cutoff
//				m_AlphaHitCount += ( response_list.size() - 1 );

				// Alpha cutoff

				break;
			}

			// alpha-beta pruning (beta)

			// Here's how it works. I am looking for the highest value, and
			// my opponent is looking for the lowest value. The 'beta' passed
			// in to this function is the value of my opponent's best move found so far.
			// If the value of this response is lower, then obviously this
			// is a better move. The beta value is passed to my 
			// move evaluator so that if I find a response to his best
			// response with a higher value, I won't bother continuing because
			// I know that he already has a better move. So, keep track of the
			// value of my opponent's best move so far.

			if ( best_score < beta )
				beta = best_score;
		}

		response_list.pop();
	}

	return best_score;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/
 
void GameTree::GenerateStates( SortedGameStateVector* states, GameState const & state, bool my_move, int depth )
{
//	Stone const	current_color	= my_move ? m_MyColor : m_YourColor;
//	Board const &	board			= state.m_Board;
//
//	// For each square on the board, if it contains a piece on the side whose
//	// turn it is, generate all the possible moves for it and add the resulting
//	// game states to game state list.
//
//	Position p( 0, 0 );
//	for ( p.m_Row = 0; p.m_Row < Board::BOARD_SIZE; p.m_Row++ )
//	{
//		for ( p.m_Column = 0; p.m_Column < Board::BOARD_SIZE; p.m_Column++ )
//		{
//			Piece const * const	piece	= board.GetPieceAt( p );
//
//			if ( piece != NO_PIECE && piece->GetColor() == current_color )
//			{
//				MoveVector moves;
//				moves.reserve( 28 );	// Space for 28 moves (max for any piece)
//
//				piece->GeneratePossibleMoves( board, p, &moves );
//
//				// Convert the moves into new states and put the new states
//				// into the state list ( sorted by priority and value )
//
//				for ( MoveVector::iterator m = moves.begin(); m != moves.end(); ++m )
//				{
//					GameState new_state( state, *m );
//					PrioritizeAndEvaluate( &new_state, depth );
//
//					++m_GeneratedStateCount;
//
//					states->push( new_state );
//				}
//			}
//		}
//	}
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void GameTree::PrioritizeAndEvaluate( GameState * pState, int depth )
{
	int const PRIORITY_EVALUATION	= 0;
	int const PRIORITY_TTABLE		= 10;

#if defined( USING_TTABLE )

	// If it is in the transposition table then we don't have to evaluate,
	// just use that value. Note we will take anything out of the T-table
	// because this is at least as good as the static evaluation function.

	if ( m_pTranspositionTable->Check( *pState, 0, &pState->m_Value ) )
	{

#if defined( USING_PRIORITIZED_MOVE_ORDERING )

		// If the quality is high enough, set the priority because T-table
		// look-ups are VERY fast compared to searches.

		if ( m_pTranspositionTable->Check( *pState, MAX_DEPTH - depth, &pState->m_Value ) )
		{
			pState->m_Priority = PRIORITY_TTABLE;
		}

#endif // defined( USING_PRIORITIZED_MOVE_ORDERING )

	}
	else

#endif // defined( USING_TTABLE )

	{

#if defined( USING_PRIORITIZED_MOVE_ORDERING )

		// Evaluation has normal priority
		pState->m_Priority = PRIORITY_EVALUATION;

#endif // defined( USING_PRIORITIZED_MOVE_ORDERING )

		pState->m_Value = Evaluate( *pState );
	}
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

float GameTree::Evaluate( GameState const & state )
{
//	++m_EvaluationCount;
//
//	Board const &	board	= state.m_Board;
	float value = 0.f;
//
//		// Add the value of all the pieces to get the value of game
//
//	Position p( 0, 0 );
//	for ( p.m_Row = 0; p.m_Row < Board::BOARD_SIZE; p.m_Row++ )
//	{
//		for ( p.m_Column = 0; p.m_Column < Board::BOARD_SIZE; p.m_Column++ )
//		{
//			Piece const * piece = board.GetPieceAt( p );
//
//			if ( piece == NO_PIECE )
//			{
//				static int map[8] = { 0, 1, 3, 2, 4, 5, 7, 6 };
//				// Randomize the value slightly so that equivalent moves have different
//				// values and profiling results of ordering methods are more realistic
//				value += map[ ( p.m_Row ^ p.m_Column ) & 7 ] * .00002 - .00001;
//				continue;
//			}
//
//			if ( piece->GetColor() == m_MyColor )
//				value += piece->GetValue();
//			else
//				value -= piece->GetValue();
//		}
//	}
//
//	// If a king is dead, return a special value. It is assumed that a king is
//	// dead if the state's value is greater than 500 because the value of the king is
//	// 1000 and the next closest is the queen, which is 9, so it is assumed impossible
//	// to have a value of 500 without a king being dead.
//
//	if ( value > 500.f )
//		value = MY_CHECKMATE_VALUE;
//	else if ( value < -500.f )
//		value = OPPONENT_CHECKMATE_VALUE;
//
	return value;
}
