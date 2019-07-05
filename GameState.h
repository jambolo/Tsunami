#if !defined( GAMESTATE_H_INCLUDED )
#define GAMESTATE_H_INCLUDED

#pragma once

/****************************************************************************

                                  GameState.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/GameState.h#2 $

	$NoKeywords: $

****************************************************************************/

#include "GoTypes.h"

#include "Board.h"
#include "Move.h"
//#include "SequenceEntry.h"
#include "ZHash.h"

#include <vector>
#include <queue>

class Move;

#define USING_ZORBRIST_HASH
#define USING_PRIORITIZED_MOVE_ORDERING

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class GameState
{
public:
	GameState() {}
	GameState( Board const & board, Move const & move, float value );
	GameState( GameState const & old_state, Move const & move );

//	virtual ~GameState();

	// Reset the game
	void Initialize();

	// Compare states
	bool operator==( GameState const & y ) const;

	// Update the game state with the specified move
	void MakeMove( Move const & move );

	// Returns the hash code for the state
	ZHash GetHashCode() const;

	Board			m_Board;					// The board
	Move			m_Move;						// The move that resulted in this state
	float			m_Value;					// Value of the game
	int				m_Priority;					// Priority of this state (determines sorting order)
//	SequenceEntry	m_ExpectedSequence[ 8 ];	// Sequence expected to follow this state

private:

	// Computes the hash code for this state
	ZHash ComputeHashCode() const;

#if defined( USING_ZORBRIST_HASH )
	ZHash		m_HashCode;							// Hash code for this state
#endif // defined( USING_ZORBRIST_HASH )
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline GameState::GameState( Board const & board, Move const & move, float value )
	: m_Board( board ), m_Move( move ), m_Value( value )
{
#if defined( USING_ZORBRIST_HASH )
	m_HashCode = ComputeHashCode();
#endif // defined( USING_ZORBRIST_HASH )

//	ASSERT( PIECE_INVALID == -1 );
//	memset( m_ExpectedSequence, -1, sizeof m_ExpectedSequence );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline bool GameState::operator==( GameState const & y ) const
{
	// States are the same if the boards are the same because the hash code
	// is redundant and the rest are informational and not part of the state.
	// For speed, test the hashcode first.

#if defined( USING_ZORBRIST_HASH )

	return ( m_HashCode == y.m_HashCode && m_Board == y.m_Board );

#else // defined( USING_ZORBRIST_HASH )

	return ( m_Board == y.m_Board );

#endif // defined( USING_ZORBRIST_HASH )
}




/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline ZHash GameState::GetHashCode() const
{
#if defined( USING_ZORBRIST_HASH )
	return m_HashCode;
#else // defined( USING_ZORBRIST_HASH )
	return ComputeHashCode();
#endif // defined( USING_ZORBRIST_HASH )
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class GameStateVector : public std::vector< GameState > {};

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class GameStateVectorSorter
{
public:
	GameStateVectorSorter( bool highest_first )
		: m_HighestFirst( highest_first )
	{
	}

	bool operator()( GameState const & g0, GameState const & g1 ) const
	{
		bool const	less	= g0.m_Value < g1.m_Value;

#if defined( USING_PRIORITIZED_MOVE_ORDERING )

		return ( ( g0.m_Priority < g1.m_Priority ) ||
			     ( g0.m_Priority == g1.m_Priority && m_HighestFirst == less ) );

#else // defined( USING_PRIORITIZED_MOVE_ORDERING )

		return ( m_HighestFirst == less );

#endif //defined( USING_PRIORITIZED_MOVE_ORDERING )
	}

private:
	bool m_HighestFirst;
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class SortedGameStateVector : public std::priority_queue< GameState, std::vector< GameState >, GameStateVectorSorter >
{
public:
	SortedGameStateVector( bool highest_first );
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline SortedGameStateVector::SortedGameStateVector( bool highest_first )
	: std::priority_queue< GameState,
						   std::vector< GameState >,
						   GameStateVectorSorter >( GameStateVectorSorter( highest_first ) )
{
	int const	MAX_NUMBER_OF_MOVES	= Board::MAX_BOARD_SIZE * Board::MAX_BOARD_SIZE - 1;

	// Reserve enough space to hold the max number of moves that can
	// be generated.

	c.reserve( MAX_NUMBER_OF_MOVES );
}


#endif // !defined( GAMESTATE_H_INCLUDED )
