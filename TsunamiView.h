#if !defined( TSUNAMIVIEW_H_INCLUDED )
#define TSUNAMIVIEW_H_INCLUDED

#pragma once

/*****************************************************************************

                                TsunamiView.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/TsunamiView.h#2 $

	$NoKeywords: $

*****************************************************************************/


#include "TsunamiDoc.h"

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CTsunamiView : public CView
{
protected: // create from serialization only
	CTsunamiView();
	DECLARE_DYNCREATE( CTsunamiView )

// Attributes
public:
	CTsunamiDoc * GetDocument();
	CTsunamiDoc const	* GetDocument() const;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTsunamiView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTsunamiView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTsunamiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	void DrawBoard( CDC * dc, CPoint const & xy ) const;
	void DrawStats( CDC * dc, CPoint const & xy ) const;
	void DrawRecord( CDC * dc, CPoint const & xy ) const;
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

#if !defined( _DEBUG )  // debug version in TsunamiView.cpp

inline CTsunamiDoc * CTsunamiView::GetDocument()
{
	return static_cast< CTsunamiDoc * >( m_pDocument );
}

inline CTsunamiDoc const * CTsunamiView::GetDocument() const
{
	return static_cast< CTsunamiDoc * >( m_pDocument );
}

#endif // !defined( _DEBUG )



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/


//{{AFX_INSERT_LOCATION}}
//}}AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined( TSUNAMIVIEW_H_INCLUDED )
