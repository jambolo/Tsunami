// NewGameDialog.cpp : implementation file
//

#include "stdafx.h"

#include "NewGameDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewGameDialog dialog


CNewGameDialog::CNewGameDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewGameDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewGameDialog)
	m_HumanColor = 0;
	m_Handicap = 0;
	//}}AFX_DATA_INIT
}


void CNewGameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewGameDialog)
	DDX_Radio(pDX, IDC_COLOR_WHITE, m_HumanColor);
	DDX_Radio(pDX, IDC_HANDICAP_NONE, m_Handicap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewGameDialog, CDialog)
	//{{AFX_MSG_MAP(CNewGameDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewGameDialog message handlers
