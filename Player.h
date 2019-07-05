#if !defined( PLAYER_H_INCLUDED )
#define PLAYER_H_INCLUDED

#pragma once

/****************************************************************************

                                   Player.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/Player.h#2 $

	$NoKeywords: $

****************************************************************************/

#include "GoTypes.h"
#include "GameState.h"

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class Player
{
public:
	Player( Stone color );
	virtual ~Player() {}

	// Get my next move
	virtual GameState MyTurn( GameState const & s0 ) = 0;

	// Analysis data

//	int				m_Time;
//	float			m_Value;
//	int				m_GeneratedStateCount;
//	int				m_EvaluationCount;
//	float			m_WorstValue;
//	int				m_AlphaHitCount;
//	int				m_BetaHitCount;
//	int				m_TTableCheckCount;
//	int				m_TTableHitCount;
//	int				m_TTableUsage;
//	int				m_TTableCollisionCount;

protected:

	Stone m_MyColor;
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline Player::Player( Stone color )
	: m_MyColor( color )
{
}



#endif // !defined( PLAYER_H_INCLUDED )
