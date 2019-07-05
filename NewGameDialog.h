#if !defined( NEWGAMEDIALOG_H_INCLUDED )
#define NEWGAMEDIALOG_H_INCLUDED

#pragma once

/*****************************************************************************

                               NewGameDialog.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/NewGameDialog.h#2 $

	$NoKeywords: $

*****************************************************************************/

#include "resource.h"

class CNewGameDialog : public CDialog
{
// Construction
public:
	CNewGameDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewGameDialog)
	enum { IDD = IDD_NEW_GAME };
	int		m_HumanColor;
	int		m_Handicap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewGameDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewGameDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
//}}AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined( NEWGAMEDIALOG_H_INCLUDED )
