/****************************************************************************

                               HumanPlayer.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/HumanPlayer.cpp#2 $

	$NoKeywords: $

****************************************************************************/

#include "StdAfx.h"

#include "HumanPlayer.h"

#include "GoTypes.h"
#include "Board.h"
#include "GameState.h"
#include "YourTurnDialog.h"
#include "Move.h"

#include <limits>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif





/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

HumanPlayer::HumanPlayer( Stone color )
	: Player( color )
{
}




/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

HumanPlayer::~HumanPlayer()
{
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GameState HumanPlayer::MyTurn( GameState const & s0 )
{
	Board const &	board	= s0.m_Board;
	Move			move	= MOVE_INVALID;

	// Get a valid move

	CYourTurnDialog dlg;

	while ( move.IsInvalid() )
	{
		int result = dlg.DoModal();

		if ( result == IDOK )
		{
			switch ( dlg.m_MoveType )
			{
			case 1:
			{
				move = MOVE_RESIGN;
				break;
			}
			case 2:
			{
				move = MOVE_UNDO;
				break;
			}
			default:
			{
				Position const to( dlg.m_ToRow, dlg.m_ToColumn );

				if ( board.IsValidPosition( to ) )
				{
//					if ( /*&& piece->IsValidMove( board, from, to )*/ )
					{
						move.m_Position = to;
						break;
					}
				}
			}
			}
		}
	}

//	m_Time					= -1;
//	m_Value					= -std::numeric_limits<float>::infinity();
//	m_GeneratedStateCount	= -1;
//	m_EvaluationCount		= -1;
//	m_WorstValue			= 0.f;
//	m_AlphaHitCount			= -1;
//	m_BetaHitCount			= -1;
//	m_TTableCheckCount		= -1;
//	m_TTableHitCount		= -1;
//	m_TTableUsage			= -1;
//	m_TTableCollisionCount	= -1;

	return GameState( s0, move );
}
