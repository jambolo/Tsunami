/*****************************************************************************

                                TsunamiDoc.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/TsunamiDoc.cpp#2 $

	$NoKeywords: $

*****************************************************************************/

#include "StdAfx.h"

#include "TsunamiDoc.h"

#include "Tsunami.h"
#include "NewGameDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif






/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CTsunamiDoc::CTsunamiDoc()
{
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CTsunamiDoc::~CTsunamiDoc()
{
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiDoc::Initialize()
{
	// Reset the game

	m_GameState.Initialize();

}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiDoc::DeleteContents()
{
	// Do base class stuff

	CDocument::DeleteContents();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiDoc::Serialize( CArchive& ar )
{
	if ( ar.IsStoring() )
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

#ifdef _DEBUG

void CTsunamiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTsunamiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

#endif //_DEBUG


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

IMPLEMENT_DYNCREATE( CTsunamiDoc, CDocument )

BEGIN_MESSAGE_MAP( CTsunamiDoc, CDocument )
	//{{AFX_MSG_MAP(CTsunamiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

BOOL CTsunamiDoc::OnNewDocument()
{
	if ( !CDocument::OnNewDocument() )
		return FALSE;

#if !defined( PROFILING )

	// Bring up a dialog box to get the human color. When the app first
	// starts, for user convenience, the dialog box is skipped and
	// the values are default.

	static bool the_first_time = true;

	if ( the_first_time )
	{
		// Skip the dialog box this time but never again

		the_first_time = false;
	}
	else
	{
		// Ask for the initial setup

		CNewGameDialog dlg;

		// Set the defaults to the values used last game

		dlg.m_HumanColor = m_HumanColor;

		// Get the setup for this game

		dlg.DoModal();

		ASSERT( dlg.m_HumanColor == STONE_WHITE || dlg.m_HumanColor == STONE_BLACK );
		m_HumanColor = static_cast< Stone >( dlg.m_HumanColor );
	}

#endif // !defined( PROFILING )

	// Do standard initialization

	Initialize();

	return TRUE;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiDoc::UndoMove()
{
	ASSERT( m_GameRecord.size() > 0 );

	// Erase the last record

	m_GameRecord.erase( m_GameRecord.end()-1 );

	// Force the state to the previous value according to the game record. If
	// the game has been undone to the beginning, then reset it instead.

	if ( m_GameRecord.size() > 0 )
	{
		m_GameState = GameState( m_GameRecord.back().m_Board,
								  m_GameRecord.back().m_Move,
								  m_GameRecord.back().m_Value );

		Stone const who_just_moved = m_GameState.m_Board.GetStoneAt( m_GameState.m_Move.m_To );
		m_WhoseTurn = OtherColor( who_just_moved  );
	}
	else
	{
		m_GameState.Initialize();
		m_WhoseTurn = STONE_BLACK;
	}
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiDoc::PlayMove( GameState const & new_state )
{
	// Make the move

	m_GameState = new_state;

	// Document the move

	m_GameRecord.push_back( GameRecordEntry( new_state ) );

	// Figure out who went and whose turn it is now

	if ( new_state.m_Move.IsStartingPosition() )
	{
		m_WhoseTurn = STONE_BLACK;
	}
	else if ( new_state.m_Move.IsResignation() )
	{
		m_WhoseTurn = STONE_INVALID;
	}
	else
	{
		// Figure out who just moved and it's the other color's turn now

		Stone const who_just_moved = new_state.m_Board.GetStoneAt( new_state.m_Move.m_To );
		m_WhoseTurn = OtherColor( who_just_moved );
	}
}
