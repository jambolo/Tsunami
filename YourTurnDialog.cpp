/*****************************************************************************

                              YourTurnDialog.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/YourTurnDialog.cpp#2 $

	$NoKeywords: $

*****************************************************************************/

#include "stdafx.h"

#include "YourTurnDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYourTurnDialog dialog


CYourTurnDialog::CYourTurnDialog( CWnd* pParent /*=NULL*/ )
	: CDialog( CYourTurnDialog::IDD, pParent )
{
	//{{AFX_DATA_INIT(CYourTurnDialog)
	m_ToColumn = 0;
	m_ToRow = 0;
	m_MoveType = 0;
	//}}AFX_DATA_INIT
}


void CYourTurnDialog::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange( pDX );
	//{{AFX_DATA_MAP(CYourTurnDialog)
	DDX_Text( pDX, IDC_COLUMN, m_ToColumn );
	DDV_MinMaxInt( pDX, m_ToColumn, 1, 19 );
	DDX_Text( pDX, IDC_ROW, m_ToRow );
	DDV_MinMaxInt( pDX, m_ToRow, 1, 19 );
	DDX_Radio( pDX, IDC_MOVE, m_MoveType );
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP( CYourTurnDialog, CDialog )
	//{{AFX_MSG_MAP(CYourTurnDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYourTurnDialog message handlers
