#if !defined( YOURTURNDIALOG_H_INCLUDED )
#define YOURTURNDIALOG_H_INCLUDED

#pragma once

/*****************************************************************************

                               YourTurnDialog.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/YourTurnDialog.h#2 $

	$NoKeywords: $

*****************************************************************************/

#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CYourTurnDialog : public CDialog
{
// Construction
public:
	CYourTurnDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(YourTurnDialog)
	enum { IDD = IDD_YOURTURN };
	int		m_ToColumn;
	int		m_ToRow;
	int		m_MoveType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(YourTurnDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(YourTurnDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
//}}AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined( YOURTURNDIALOG_H_INCLUDED )
