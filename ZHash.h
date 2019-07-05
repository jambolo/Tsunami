#if !defined( ZHASH_H_INCLUDED )
#define ZHASH_H_INCLUDED

#pragma once

/*****************************************************************************

                                ZHash.h

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/ZHash.h#2 $

	$NoKeywords: $

*****************************************************************************/

#include "Board.h"
#include "GoTypes.h"

// Forward declarations

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class ZHash
{
public:

	// Type of the hash value
	typedef unsigned __int64 Z;

	ZHash( Z z = 0 );

	// Conversion to Z
	operator Z() const									{ return m_Value; }

	bool	operator ==( ZHash const & y ) const;

	// Add a stone. Returns the new value
	ZHash const &	Add( Stone stone, Position const & position );
	ZHash const &	Add( Stone stone, int r, int c );

	// Remove a stone. Returns the new value
	ZHash const &	Remove( Stone stone, Position const & position );
	ZHash const &	Remove( Stone stone, int r, int c );

	// Return true if the value is undefined
	bool	IsUndefined() const;

private:

	class ZValueTable;	// declared below

	Z							m_Value;		// The hash value
	static ZValueTable	const	m_ZValueTable;	// The hash code table

};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class ZHash::ZValueTable
{
public:

	ZValueTable();

	// Get the appropriate value
	Z	GetZValue( Stone stone, int row, int column ) const;

private:

	Z	m_ZValues[ Board::MAX_BOARD_SIZE ][ Board::MAX_BOARD_SIZE ][ NUMBER_OF_COLORS ];
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline ZHash::ZHash( Z z /* = 0 */ )
	: m_Value( z )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline bool ZHash::operator ==( ZHash const & y ) const
{
	return ( m_Value == y.m_Value );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline ZHash const & ZHash::Add( Stone stone, Position const & p )
{
	return Add( stone, p.m_Row, p.m_Column );
}


inline ZHash const & ZHash::Add( Stone stone, int r, int c )
{
	ASSERT( !IsUndefined() );
	m_Value ^= m_ZValueTable.GetZValue( stone, r, c );

	return *this;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline ZHash const & ZHash::Remove( Stone stone, Position const & p )
{
	return Remove( stone, p.m_Row, p.m_Column );
}


inline ZHash const & ZHash::Remove( Stone stone, int r, int c )
{
	ASSERT( !IsUndefined() );
	m_Value ^= m_ZValueTable.GetZValue( stone, r, c );

	return *this;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline bool ZHash::IsUndefined() const
{
	// The value is undefined if the high order bit is set
	return ( static_cast< signed __int64 >( m_Value ) < 0 );
}

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline ZHash::Z ZHash::ZValueTable::GetZValue( Stone stone, int row, int column ) const
{
	ASSERT_LIMITS( 0, stone, NUMBER_OF_COLORS-1 );
	ASSERT_LIMITS( 0, row, Board::MAX_BOARD_SIZE-1 );
	ASSERT_LIMITS( 0, column, Board::MAX_BOARD_SIZE-1 );

	return m_ZValues[ row ][ column ][ stone ];
}

#endif // !defined( ZHASH_H_INCLUDED )
