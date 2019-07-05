#if !defined( COMPUTERPLAYER_H_INCLUDED )
#define COMPUTERPLAYER_H_INCLUDED

#pragma once

/****************************************************************************

                               ComputerPlayer.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/ComputerPlayer.h#2 $

	$NoKeywords: $

****************************************************************************/

#include "Player.h"

#include "GoTypes.h"

class GameState;


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class ComputerPlayer : public Player
{
public:
	ComputerPlayer( Stone color );
	virtual ~ComputerPlayer();

	GameState MyTurn( GameState const & s0 );
};


#endif // !defined( COMPUTERPLAYER_H_INCLUDED )
