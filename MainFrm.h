#if !defined( MAINFRM_H_INCLUDED )
#define MAINFRM_H_INCLUDED

#pragma once

/*****************************************************************************

                                  MainFrm.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/MainFrm.h#2 $

	$NoKeywords: $

*****************************************************************************/

enum TCustomWindowMessages
{
	WM_NEXTTURN	= WM_APP + 0
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE( CMainFrame )

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL( CMainFrame )
	public:
	virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump( CDumpContext& dc ) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;

// Generated message map functions
protected:
	//{{AFX_MSG( CMainFrame )
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	afx_msg LRESULT OnNextTurn( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
//}}AFX_INSERT_LOCATION
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined( MAINFRM_H_INCLUDED )
