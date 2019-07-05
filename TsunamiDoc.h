#if !defined( TSUNAMIDOC_H_INCLUDED )
#define TSUNAMIDOC_H_INCLUDED

#pragma once

/*****************************************************************************

                                 TsunamiDoc.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/TsunamiDoc.h#2 $

	$NoKeywords: $

*****************************************************************************/

#include "GoTypes.h"
#include "GameState.h"
#include "GameRecordEntry.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CTsunamiDoc : public CDocument
{
	friend class CTsunamiView;

protected: // create from serialization only
	CTsunamiDoc();
	DECLARE_DYNCREATE( CTsunamiDoc )

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTsunamiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize( CArchive& ar );
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTsunamiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump( CDumpContext& dc ) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTsunamiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	Stone GetHumanColor() const					{ return m_HumanColor; }
	GameRecord const & GetGameRecord() const	{ return m_GameRecord; }
	GameState const & GetGameState() const		{ return m_GameState; }

	// Undo the last move
	void UndoMove();

	// Play a move
	void PlayMove( GameState const & new_state );

	// Analysis data for the last move

//	int				m_Time;
//	float			m_Value;
//	int				m_GeneratedStateCount;
//	int				m_EvaluationCount;
//	float			m_WorstValue;
//	int				m_AlphaHitCount;
//	int				m_BetaHitCount;
//	int				m_TTableCheckCount;
//	int				m_TTableHitCount;
//	int				m_TTableUsage;
//	int				m_TTableCollisionCount;

private:
	void Initialize();

	Stone		m_WhoseTurn;	// Whose turn it is
	Stone		m_HumanColor;	// Stone of the human player (here for convenience)
	GameState	m_GameState;	// The game as it currently stands
	GameRecord	m_GameRecord;	// Game record up to the current state
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
//}}AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined( TSUNAMIDOC_H_INCLUDED )
