/*****************************************************************************

                                AboutDialog.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/AboutDialog.cpp#2 $

	$NoKeywords: $

*****************************************************************************/

#include "StdAfx.h"

#include "AboutDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CAboutDialog::CAboutDialog() : CDialog( CAboutDialog::IDD )
{
	//{{AFX_DATA_INIT(CAboutDialog)
	//}}AFX_DATA_INIT
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CAboutDialog::DoDataExchange( CDataExchange * pDX )
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDialog)
	//}}AFX_DATA_MAP
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

BEGIN_MESSAGE_MAP( CAboutDialog, CDialog )
	//{{AFX_MSG_MAP(CAboutDialog)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
