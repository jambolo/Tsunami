/** @file *//********************************************************************************************************

                                                       Board.h

						                    Copyright 2004, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Tsunami/Board.h#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


#include "GoTypes.h"

/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

class Board
{
public:
	enum
	{
		MIN_BOARD_SIZE = 9,	// Min number of rows and columns
		MAX_BOARD_SIZE = 19	// Max number of rows and columns
	};


	Board( int size = MAX_BOARD_SIZE );
	//virtual ~Board();

		// Copy constructor and assignment operator
	Board( Board const & board );
	Board const & operator=( Board const & board );

	// Reset the board
	void Initialize();

	// Returns true if the specified board is the same as this one
	bool operator==( Board const & y ) const;

	// Returns true if p is a valid location
	bool IsValidPosition( Position const & p ) const;
	bool IsValidPosition( int r, int c ) const;

	// Returns the stone at the given position or STONE_NONE, if none
	Stone GetStoneAt( Position const & p ) const;
	Stone GetStoneAt( int r, int c ) const;

	// Places the stone on the board at the given position
	void PutStone( Stone stone, Position const & p );
	void PutStone( Stone stone, int r, int c );

	// Removes the stone at the given position from the board
	void RemoveStone( Position const & p );
	void RemoveStone( int r, int c );

	// Return the size of the board
	int GetSize() const							{ return m_Size; }

private:

	unsigned char	m_Board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];	// The board
	int				m_Size;										// Size of the board
};


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline Board::Board( int size /* = MAX_BOARD_SIZE */ ) 
	: m_Size( size )
{
	Initialize();
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline void Board::Initialize()
{
	ASSERT_MEMSET_VALID( m_Board, STONE_NONE );
	memset( m_Board, (int)STONE_NONE, sizeof m_Board );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline bool Board::IsValidPosition( Position const & p ) const
{
	return IsValidPosition( p.m_Row, p.m_Column );
}

inline bool Board::IsValidPosition( int r, int c ) const
{
	return ( r >= 0 && r < m_Size &&
			 c >= 0 && c < m_Size );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline Stone Board::GetStoneAt( Position const & p ) const
{
	return GetStoneAt( p.m_Row, p.m_Column );
}


inline Stone Board::GetStoneAt( int r, int c ) const
{
	ASSERT( IsValidPosition( r, c ) );

	return static_cast< Stone >( m_Board[ r ][ c ] );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline void Board::PutStone( Stone stone, Position const & p )
{
	PutStone( stone, p.m_Row, p.m_Column );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline void Board::PutStone( Stone stone, int r, int c )
{
	ASSERT( IsValidPosition( r, c ) );
	ASSERT( stone == STONE_WHITE || stone == STONE_BLACK );

	// Place the stone

	m_Board[ r ][ c ] = stone;
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline void Board::RemoveStone( Position const & p )
{
	RemoveStone( p.m_Row, p.m_Column );
}


inline void Board::RemoveStone( int r, int c )
{
	ASSERT( IsValidPosition( r, c ) );
	ASSERT( m_Board[ r ][ c ] == STONE_WHITE || m_Board[ r ][ c ] == STONE_BLACK );

	// Remove the stone

	m_Board[ r ][ c ] = STONE_NONE;
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline bool Board::operator==( Board const & y ) const
{
	return ( memcmp( m_Board, y.m_Board, sizeof m_Board ) == 0 );
}
