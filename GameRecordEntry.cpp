/****************************************************************************

                             GameRecordEntry.cpp

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/GameRecordEntry.cpp#2 $

	$NoKeywords: $

****************************************************************************/

#include "stdafx.h"

#include "GameRecordEntry.h"

#include "GameState.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GameRecordEntry::GameRecordEntry( GameState const & new_state )
	: m_Move( new_state.m_Move ),
	m_Board( new_state.m_Board ),
	m_Value( new_state.m_Value )
//	m_Time( -1 ),
//	m_GeneratedStateCount( -1 ),
//	m_EvaluationCount( -1 ),
//	m_AlphaHitCount( -1 ),
//	m_BetaHitCount( -1 ),
//	m_TTableCheckCount( -1 ),
//	m_TTableHitCount( -1 ),
//	m_TTableUsage( -1 ),
//	m_TTableCollisionCount( -1 )

{
	if ( !new_state.m_Move.IsResignation() )
		m_Stone = m_Board.GetStoneAt( m_Move.m_To );
	else
		m_Stone = STONE_NONE;
}


