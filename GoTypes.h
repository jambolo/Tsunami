#if !defined( GOTYPES_H_INCLUDED )
#define GOTYPES_H_INCLUDED

#pragma once

/*****************************************************************************

                                  GoTypes.h

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/GoTypes.h#2 $

	$NoKeywords: $

*****************************************************************************/

#include <vector>

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/


class Position
{
public:
	Position() {}
	Position( int r, int c );

	int	m_Row;
	int m_Column;
};

class PositionVector : public std::vector< Position > {};

inline Position::Position( int r, int c )
	: m_Row( r ),
	m_Column( c )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

enum Stone
{
//	STONE_KO			= -2,
	STONE_INVALID		= -1,
	STONE_NONE			= -1,
	STONE_WHITE			= 0,
	STONE_BLACK			= 1,

	NUMBER_OF_COLORS	= 2
};

inline Stone OtherColor( Stone color )
{
	return ( color == STONE_WHITE ) ? STONE_BLACK : STONE_WHITE;
}


#endif // !defined( GOTYPES_H_INCLUDED )
