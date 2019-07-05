#if !defined( TSUNAMI_H_INCLUDED )
#define TSUNAMI_H_INCLUDED

#pragma once

/*****************************************************************************

                                  Tsunami.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/Tsunami.h#2 $

	$NoKeywords: $

*****************************************************************************/

#include "resource.h"       // main symbols

#include "GoTypes.h"

class CTsunamiDoc;
class Player;
class ComputerPlayer;

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CTsunamiApp : public CWinApp
{
public:
	CTsunamiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTsunamiApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTsunamiApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	// Handle the next turn
	LRESULT OnNextTurn( WPARAM wParam, LPARAM lParam );

	Player *		m_pWhitePlayer;		// The white player
	Player *		m_pBlackPlayer;		// The black player
	CTsunamiDoc *	m_pCurrentGame;		// The current game

private:

	ComputerPlayer const *	m_pComputerPlayer;	// Keep track of the computer player for analysis
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
//}}AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined( TSUNAMI_H_INCLUDED )
