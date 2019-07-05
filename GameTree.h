#if !defined( GAMETREE_H_INCLUDED )
#define GAMETREE_H_INCLUDED

#pragma once

/****************************************************************************

                                  GameTree.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/GameTree.h#2 $

	$NoKeywords: $

****************************************************************************/

// Define the following symbol if you want to turn on the transposition table
//#define USING_TTABLE

#include "GoTypes.h"
//#include "Move.h"

//#if defined( USING_TTABLE )
//#include "TranspositionTable.h"
//#endif // defined( USING_TTABLE )

class GameState;
class SortedGameStateVector;
class TranspositionTable;

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class GameTree
{
public:
	GameTree();
//	GameTree( GameTree const & tree );
	~GameTree();

	// Search for my best move and return it
	GameState MyBestMove( GameState const & s0, Stone my_color );

	// Analysis data

//	int				m_GeneratedStateCount;
//	int				m_EvaluationCount;
//	float			m_WorstValue;
//
//	int				m_AlphaHitCount;
//	int				m_BetaHitCount;
//
//#if defined( USING_TTABLE )
//	int				m_TTableCheckCount;
//	int				m_TTableHitCount;
//	int				m_TTableUsage;
//	int				m_TTableCollisionCount;
//#endif // defined( USING_TTABLE )

private:

	// Return the value of my best response to the given state
	float MeAlphaBeta( GameState const & s0, float alpha, float beta, int depth, int last_ply );

	// Return the value of my opponent's best response to the given state
	float OpponentAlphaBeta( GameState const & s0, float alpha, float beta, int depth, int last_ply );

	// Static evaluation function -- return the estimated value of this state
	float Evaluate( GameState const & state );

	// Ordering function
	void GameTree::PrioritizeAndEvaluate( GameState * pState, int depth );

	// Generate a list of all possible states in response to the specified one
	void GenerateStates( SortedGameStateVector * states, GameState const & s0, bool my_move, int depth );

	Stone					m_MyColor;		// My color
	Stone					m_YourColor;	// My opponent's color

#if defined( USING_TTABLE )
	TranspositionTable *	m_pTranspositionTable;
#endif // defined( USING_TTABLE )
};

#endif // !defined( GAMETREE_H_INCLUDED )
