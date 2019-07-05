#if !defined( GAMERECORDENTRY_H_INCLUDED )
#define GAMERECORDENTRY_H_INCLUDED

#pragma once

/*****************************************************************************

                              GameRecordEntry.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/GameRecordEntry.h#2 $

	$NoKeywords: $

*****************************************************************************/

#include "Board.h"
#include "Move.h"
#include "GoTypes.h"

#include <vector>

class GameState;

class GameRecordEntry
{
public:
	GameRecordEntry() {}
	GameRecordEntry( GameState const & new_state );

	Stone	m_Stone;			// Stone placed
	Move	m_Move;				// The move
	Board	m_Board;			// The resulting board
	float	m_Value;			// Value of the game after this move

	// Analysis data

//	int				m_Time;					// Time in ms
//	int				m_GeneratedStateCount;	// Number of generated states
//	int				m_EvaluationCount;		// Number of static evaluations
//	int				m_AlphaHitCount;		// Number of alpha prunes
//	int				m_BetaHitCount;			// Number of beta prunes
//	int				m_TTableCheckCount;		// Number of T-table checks
//	int				m_TTableHitCount;		// Number of T-table hits
//	int				m_TTableUsage;			// Number of T-table entries in use
//	int				m_TTableCollisionCount;	// Number of T-table collisions
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class GameRecord : public std::vector< GameRecordEntry > {};


#endif // !defined( GAMERECORDENTRY_H_INCLUDED )
