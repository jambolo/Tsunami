#if !defined( MOVE_H_INCLUDED )
#define MOVE_H_INCLUDED

#pragma once

/****************************************************************************

                                    Move.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/Move.h#2 $

	$NoKeywords: $

****************************************************************************/

#include <vector>

#include "GoTypes.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class Move
{
public:

	// Values for the special moves

	enum SpecialMoveId
	{
		SM_INVALID	= -1,
		SM_RESIGN	= -2,
		SM_UNDO		= -3,
		SM_0		= -4
	};

	Move() {}
	Move( Position const & t );
	Move( SpecialMoveId move );

	// Returns true if this is not a valid move
	bool IsInvalid() const		{ return IsSpecialMove( SM_INVALID ); }

	// Returns true if this move is a resignation
	bool IsResignation() const			{ return IsSpecialMove( SM_RESIGN ); }

	// Returns true if this is an undo
	bool IsUndo() const					{ return IsSpecialMove( SM_UNDO ); }

	// Returns true if this is the starting position
	bool IsStartingPosition() const		{ return IsSpecialMove( SM_0 ); }

	// Data (what the hell...make it public)

//	Stone		m_Color;			// Whose move
	Position	m_Position;			// Where

private:

		// Returns true if this is the specified special move
	bool IsSpecialMove( SpecialMoveId move ) const;
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class MoveVector : public std::vector< Move > {};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline Move::Move( Position const & t )
	: m_Position( t )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline Move::Move( SpecialMoveId move )
{
	m_Position.m_Row = move;

#if defined( _DEBUG )

	// for verification

	m_Position.m_Column = move;

#endif // defined( _DEBUG )
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline bool Move::IsSpecialMove( SpecialMoveId move ) const
{
#if defined( _DEBUG )

	// Verify that the value was set by the constructor and not some other random way

	if ( m_Position.m_Row == move )
	{
		ASSERT( m_Position.m_Column == move );
	}

#endif // defined( _DEBUG )

	return ( m_Position.m_Row == move );
}

/********************************************************************************************************************/
/*																													*/
/* Constants for special moves.												*/
/*																													*/
/********************************************************************************************************************/

// Resignation
extern Move const MOVE_INVALID;

// Resignation
extern Move const MOVE_RESIGN;

// Undo
extern Move const MOVE_UNDO;

// Initial board
extern Move const MOVE_0;



#endif // !defined( MOVE_H_INCLUDED )
