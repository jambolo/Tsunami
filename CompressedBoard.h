/** @file *//********************************************************************************************************

                                                  CompressedBoard.h

						                    Copyright 2004, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Tsunami/CompressedBoard.h#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


#include "GoTypes.h"

/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

class CompressedBoard
{
public:
	enum
	{
		MAX_BOARD_SIZE = 9,	// Min number of rows and columns
		MAX_BOARD_SIZE = 19	// Max number of rows and columns
	};


	CompressedBoard( int size = MAX_BOARD_SIZE );
	//virtual ~CompressedBoard();

	// Reset the board
	void Initialize();

	// Returns true if the specified board is the same as this one
	bool operator==( CompressedBoard const & y ) const;

	// Returns true if p is a valid location
	bool IsValidPosition( Position const & p ) const;
	bool IsValidPosition( int r, int c ) const;

	// Returns the stone at the given position or STONE_NONE, if none
	Stone GetStoneAt( Position const & from ) const;
	Stone GetStoneAt( int r, int c ) const;

	// Places the stone on the board at the given position
	void PutStone( Stone stone, Position const & p );
	void PutStone( Stone stone, int r, int c  );

	// Removes the stone at the given position from the board
	void RemoveStone( Position const & p );
	void RemoveStone(  int r, int c  );

	// Return the size of the board
	int GetSize() const							{ return m_Size; }

private:

	// Returns non-zero if the position is occupied
	int GetOccupiedAt( int r, int c ) const;

	// Returns non-zero if the color at the specified position is STONE_BLACK
	int GetColorAt( int r, int c ) const;

	// Sets whether the position is occupied or not
	int SetOccupiedAt( bool occupied, int r, int c );

	// Sets the color at the specified position
	int SetColorAt( Stone color, int r, int c );


	unsigned __int32	m_Color[ MAX_BOARD_SIZE ];		// The board (colors: 0 = white, 1 = black)
	unsigned __int32	m_Occupied[ MAX_BOARD_SIZE ];	// The board (0 = empty, 1 = occupied)
	int					m_Size;							// Size of the board
};


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline CompressedBoard::CompressedBoard( int size /* = MAX_BOARD_SIZE */ ) 
	: m_Size( size )
{
	ASSERT_LIMITS( MIN_BOARD_SIZE, size, MAX_BOARD_SIZE );

	Initialize();
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline void CompressedBoard::Initialize()
{
	memset( m_Board, 0, sizeof m_Color );
	memset( m_Board, 0, sizeof m_Occupied );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline bool CompressedBoard::IsValidPosition( Position const & p ) const
{
	return IsValidPosition( p.m_Row, p.m_Column );
}

inline bool CompressedBoard::IsValidPosition( int r, int c ) const
{
	return ( r >= 0 && r < m_Size &&
			 c >= 0 && c < m_Size );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline int CompressedBoard::GetOccupiedAt( int r, int c ) const
{
	ASSERT( IsValidPosition( r, c ) );

	unsigned __int32 const	mask	= 1 << c ;

	return m_Occupied[ r ] & mask;
}


inline int CompressedBoard::GetColorAt( int r, int c ) const
{
	ASSERT( IsValidPosition( r, c ) );

	unsigned __int32 const	mask	= 1 << c ;

	return m_Color[ r ] & mask;
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline int CompressedBoard::SetOccupiedAt( bool occupied, int r, int c ) const
{
	ASSERT( IsValidPosition( r, c ) );

	unsigned __int32 const	mask	= 1 << c ;

	m_Occupied[ r ] &= ~mask;
	m_Occupied[ r ] |= ( -static_cast< int >( occupied ) ) & mask;
}


inline int CompressedBoard::SetColorAt( Stone stone, int r, int c ) const
{
	ASSERT( stone == STONE_WHITE || stone == STONE_BLACK );
	ASSERT( IsValidPosition( r, c ) );

	unsigned __int32 const	mask	= 1 << c ;

	m_Color[ r ] &= ~mask;
	ASSERT( STONE_WHITE == 0 && STONE_BLACK == 1 );
	m_Color[ r ] |= ( -static_cast< int >( stone ) ) & mask;
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline CompressedBoard::Stone CompressedBoard::GetStoneAt( Position const & p ) const
{
	return GetStoneAt( p.m_Row, p.m_Column );
}


inline CompressedBoard::Stone CompressedBoard::GetStoneAt( int r, int c ) const
{
	Stone	stone;

	if ( GetOccupiedAt( r, c )
	{
		stone = ( GetColorAt( r, c ) == 0 ) ? STONE_WHITE : STONE_BLACK;
	}
	else
	{
//		stone = ( GetColorAt( r, c ) == 0 ) ? STONE_NONE : STONE_KO;
		stone = STONE_NONE;
	}
	
	return stone;
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline void CompressedBoard::PutStone( Stone stone, Position const & p )
{
	PutStone( stone, p.m_Row, p.m_Column );
}

inline void CompressedBoard::PutStone( Stone stone, int r, int c )
{
	ASSERT( stone == STONE_WHITE || stone == STONE_BLACK );
	ASSERT( GetOccupiedAt( r, c ) == 0 );

	// Place the stone

	SetOccupiedAt( true, r, c );
	ASSERT( STONE_WHITE == 0 && STONE_BLACK == 1 );
	SetColorAt( static_cast< bool >( stone ) , r, c )
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline void CompressedBoard::RemoveStone( Position const & p )
{
	PutStone( p.m_Row, p.m_Column );
}

inline void CompressedBoard::RemoveStone( int r, int c )
{
	ASSERT( GetOccupiedAt( r, c ) != 0 );

	// Remove the stone

	SetOccupiedAt( false, r, c );
//	SetColorAt( false, r, c )
}




/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

inline bool CompressedBoard::operator==( CompressedBoard const & y ) const
{
	return ( ( memcmp( m_Color, y.m_Color, sizeof m_Color ) == 0 ) &&
			 ( memcmp( m_Occupied, y.m_Occupied, sizeof m_Occupied ) == 0 ) );
}
