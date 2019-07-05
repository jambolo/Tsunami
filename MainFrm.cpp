/*****************************************************************************

                                 MainFrm.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/MainFrm.cpp#2 $

	$NoKeywords: $

*****************************************************************************/

#include "StdAfx.h"

#include "MainFrm.h"

#include "resource.h"
#include "Tsunami.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CMainFrame::~CMainFrame()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

BOOL CMainFrame::PreCreateWindow( CREATESTRUCT& cs )
{
	if( !CFrameWnd::PreCreateWindow( cs ) )
		return FALSE;

	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump( CDumpContext& dc ) const
{
	CFrameWnd::Dump( dc );
}

#endif //_DEBUG


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

IMPLEMENT_DYNCREATE( CMainFrame, CFrameWnd )

BEGIN_MESSAGE_MAP( CMainFrame, CFrameWnd )
	//{{AFX_MSG_MAP( CMainFrame )
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_MESSAGE( WM_NEXTTURN, OnNextTurn )
END_MESSAGE_MAP()



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

int CMainFrame::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if ( CFrameWnd::OnCreate( lpCreateStruct ) == -1 )
		return -1;

	if ( !m_wndStatusBar.Create( this ) ||
		!m_wndStatusBar.SetIndicators( indicators,
		  sizeof( indicators )/sizeof( UINT ) ) )
	{
		TRACE0( "Failed to create status bar\n" );
		return -1;      // fail to create
	}

	return 0;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

LRESULT CMainFrame::OnNextTurn( WPARAM wParam, LPARAM lParam )
{
	// Just pass on to app

	return static_cast< CTsunamiApp * >( AfxGetApp() )->OnNextTurn( wParam, lParam );
}
