#if !defined( ABOUTDLG_H_INCLUDED )
#define ABOUTDLG_H_INCLUDED

#pragma once

/*****************************************************************************

                                  AboutDialog.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/AboutDialog.h#2 $

	$NoKeywords: $

*****************************************************************************/

#include "resource.h"



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CAboutDialog : public CDialog
{
public:
	CAboutDialog();

// Dialog Data
	//{{AFX_DATA(CAboutDialog)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDialog)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



#endif // !defined( ABOUTDLG_H_INCLUDED )
