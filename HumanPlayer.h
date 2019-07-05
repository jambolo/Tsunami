#if !defined( HUMANPLAYER_H_INCLUDED )
#define HUMANPLAYER_H_INCLUDED

#pragma once

/****************************************************************************

                                HumanPlayer.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/HumanPlayer.h#2 $

	$NoKeywords: $

****************************************************************************/

#include "Player.h"

#include "GoTypes.h"

class GameState;

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class HumanPlayer : public Player
{
public:
	HumanPlayer( Stone color );
	virtual ~HumanPlayer();

	GameState MyTurn( GameState const & s0 );
};

#endif // !defined( HUMANPLAYER_H_INCLUDED )
