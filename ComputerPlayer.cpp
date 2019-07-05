/****************************************************************************

                              ComputerPlayer.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/ComputerPlayer.cpp#2 $

	$NoKeywords: $

****************************************************************************/

#include "StdAfx.h"

#include "ComputerPlayer.h"

#include "GameState.h"
#include "GameTree.h"
#include "GameState.h"
#include "Board.h"

#include <mmsystem.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

ComputerPlayer::ComputerPlayer( Stone color )
	: Player( color )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

ComputerPlayer::~ComputerPlayer()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GameState ComputerPlayer::MyTurn( GameState const & s0 )
{ 
	CWaitCursor wait_cursor;

	DWORD start_time = timeGetTime();

		// Calculate the best move from here

	GameTree game_tree;
	GameState new_state = game_tree.MyBestMove( s0, m_MyColor );

	DWORD elapsed_time = timeGetTime() - start_time;

	// Update anaylsis data

//	m_Time					= elapsed_time;
//	m_Value					= new_state.m_Value;
//	m_GeneratedStateCount	= game_tree.m_GeneratedStateCount;
//	m_EvaluationCount		= game_tree.m_EvaluationCount;
//	m_WorstValue			= game_tree.m_WorstValue;
//
//	m_AlphaHitCount			= game_tree.m_AlphaHitCount;
//	m_BetaHitCount			= game_tree.m_BetaHitCount;
//
//#if defined( USING_TTABLE )
//
//	m_TTableCheckCount		= game_tree.m_TTableCheckCount;
//	m_TTableHitCount		= game_tree.m_TTableHitCount;
//	m_TTableUsage			= game_tree.m_TTableUsage;
//	m_TTableCollisionCount	= game_tree.m_TTableCollisionCount;
//
//#else // defined( USING_TTABLE )
//
//	m_TTableCheckCount		= -1;
//	m_TTableHitCount		= -1;
//	m_TTableUsage			= -1;
//	m_TTableCollisionCount	= -1;
//
//#endif // defined( USING_TTABLE )

	return new_state;
}

