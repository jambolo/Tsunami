/*****************************************************************************

                                 Tsunami.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/Tsunami.cpp#2 $

	$NoKeywords: $

*****************************************************************************/


#include "stdafx.h"

#include "Tsunami.h"

#include "MainFrm.h"
#include "TsunamiDoc.h"
#include "TsunamiView.h"
#include "AboutDialog.h"
#include "GoTypes.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CTsunamiApp theApp;



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/


CTsunamiApp::CTsunamiApp()
	: m_pBlackPlayer( 0 ), m_pWhitePlayer( 0 ), m_pCurrentGame( 0 ), m_pComputerPlayer( 0 )
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

BOOL CTsunamiApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CTsunamiDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CTsunamiView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	// Initialize the random number generator

	srand( time( NULL ) );

	return TRUE;
}
/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

int CTsunamiApp::ExitInstance() 
{
	// Delete the players

	delete m_pWhitePlayer;
	delete m_pBlackPlayer;

	return CWinApp::ExitInstance();
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

BEGIN_MESSAGE_MAP(CTsunamiApp, CWinApp)
	//{{AFX_MSG_MAP(CTsunamiApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Standard file based document commands
//	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
//	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

// App command to run the dialog
void CTsunamiApp::OnAppAbout()
{
	CAboutDialog aboutDlg;
	aboutDlg.DoModal();
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiApp::OnFileNew()
{
	// Load the new game

	CWinApp::OnFileNew();

	// Save a pointer to the new document

	POSITION template_position = GetFirstDocTemplatePosition();
	CDocTemplate * const doc_template = GetNextDocTemplate( template_position );
	POSITION doc_position = doc_template->GetFirstDocPosition();
	m_pCurrentGame = static_cast< CTsunamiDoc * >( doc_template->GetNextDoc( doc_position ) );

	// Set up the players

	delete m_pWhitePlayer;
	delete m_pBlackPlayer;

#if !defined( PROFILING )

	if ( m_pCurrentGame->GetHumanColor() == STONE_WHITE )
	{
		m_pWhitePlayer = new HumanPlayer( STONE_WHITE );
		m_pBlackPlayer = new ComputerPlayer( STONE_BLACK );
		m_pComputerPlayer = static_cast< ComputerPlayer const * >( m_pBlackPlayer );
	}
	else
	{
		m_pBlackPlayer = new HumanPlayer( STONE_BLACK );
		m_pWhitePlayer = new ComputerPlayer( STONE_WHITE );
		m_pComputerPlayer = static_cast< ComputerPlayer const * >( m_pWhitePlayer );
	}

#else // !defined( PROFILING )

	m_pWhitePlayer = new ComputerPlayer( STONE_WHITE );
	m_pBlackPlayer = new ComputerPlayer( STONE_BLACK );
	m_pComputerPlayer = static_cast< ComputerPlayer const * >( m_pBlackPlayer );

#endif // !defined( PROFILING )

	// Start the game

	BOOL ok = m_pMainWnd->PostMessage( WM_NEXTTURN, STONE_WHITE, 0 );
	ASSERT( ok );
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiApp::OnFileOpen() 
{
	// Open a file

	CWinApp::OnFileOpen();

//	if ( m_pCurrentGame->m_WhoseTurn != STONE_INVALID )
//		m_pMainWnd->PostMessage( WM_NEXTTURN, m_pCurrentGame->m_WhoseTurn );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

LRESULT CTsunamiApp::OnNextTurn( WPARAM wParam, LPARAM lParam )
{
	ASSERT_LIMITS( STONE_INVALID, static_cast< int >( wParam ), STONE_BLACK );
	ASSERT( lParam >= 0 );

	Stone const	whose_turn	= static_cast< Stone >( wParam );
	int const		turn		= lParam;

#if defined( PROFILING )

	// If it is past turn 100, then that's long enough, so don't continue

	if ( turn > 50 )
	{
		m_pMainWnd->PostMessage( WM_QUIT );
		return 0;
	}

#endif // defined( PROFILING )

	// If it's nobody's turn, the just return

	if ( whose_turn == STONE_INVALID )
		return 0;


	Player * const this_player = ( whose_turn == STONE_WHITE ) ? m_pWhitePlayer : m_pBlackPlayer;

	// Get this player's move

	GameState const new_state = this_player->MyTurn( m_pCurrentGame->GetGameState() );

	// Update analysis data

//	m_pCurrentGame->m_Time					= this_player->m_Time;
//	m_pCurrentGame->m_Value					= this_player->m_Value;
//	m_pCurrentGame->m_GeneratedStateCount	= this_player->m_GeneratedStateCount;
//	m_pCurrentGame->m_EvaluationCount		= this_player->m_EvaluationCount;
//	m_pCurrentGame->m_WorstValue			= this_player->m_WorstValue;
//	m_pCurrentGame->m_AlphaHitCount			= this_player->m_AlphaHitCount;
//	m_pCurrentGame->m_BetaHitCount			= this_player->m_BetaHitCount;
//	m_pCurrentGame->m_TTableCheckCount		= this_player->m_TTableCheckCount;
//	m_pCurrentGame->m_TTableHitCount		= this_player->m_TTableHitCount;
//	m_pCurrentGame->m_TTableUsage			= this_player->m_TTableUsage;
//	m_pCurrentGame->m_TTableCollisionCount	= this_player->m_TTableCollisionCount;

	// If it is undo, then back up two turns, otherwise play it
	// The game is backed up two turns because only a human player can undo and
	// only after the computer player has gone.

	if ( new_state.m_Move.IsUndo() )
	{
		if ( m_pCurrentGame->GetGameRecord().size() >= 2 )
		{
			// Undo the last two moves

			m_pCurrentGame->UndoMove();
			m_pCurrentGame->UndoMove();

			// Display the current state of the game

			m_pMainWnd->InvalidateRect( NULL );
			m_pMainWnd->UpdateWindow();
		}
		else
		{
			AfxMessageBox( "The beginning of the game has been reached.", MB_OK|MB_ICONEXCLAMATION );
		}

		// Its the this player's turn again

		BOOL const ok = m_pMainWnd->PostMessage( WM_NEXTTURN, whose_turn, turn-2 );
		ASSERT( ok );
	}
	else
	{
		// Play the move

		m_pCurrentGame->PlayMove( new_state );

		// Display the current state of the game

		m_pMainWnd->InvalidateRect( NULL );
		m_pMainWnd->UpdateWindow();

		// If this player didn't resign, then it's the other player's move

		if ( !new_state.m_Move.IsResignation() )
		{
			BOOL const ok = m_pMainWnd->PostMessage( WM_NEXTTURN, 1 - whose_turn, turn+1 );
			ASSERT( ok );
		}
	}

	return 0;
}
