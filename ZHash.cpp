/*****************************************************************************

                                  ZHash.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/ZHash.cpp#2 $

	$NoKeywords: $

*****************************************************************************/


#include "StdAfx.h"

#include "ZHash.h"

#include "Board.h"
#include "GoTypes.h"

#include "Misc/Random.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

ZHash::ZValueTable const	ZHash::m_ZValueTable;


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

ZHash::ZValueTable::ZValueTable()
{

	// Generate Z-values

	Random rng( 0 );

	for ( int i = 0; i < NUMBER_OF_COLORS; i++ )
	{
		for ( int j = 0; j < Board::MAX_BOARD_SIZE; j++ )
		{
			for ( int k = 0; k < Board::MAX_BOARD_SIZE; k++ )
			{
				// Z is 63 bits and Random is 32 bits so we have to concatenate
				// two numbers together to make a Z value.
				// Bit 64 is always 0 so that special values can be
				// available by setting the high bit.

				m_ZValues[i][j][k] = 0x7fffffffffffffff &
									 ( ( static_cast< unsigned __int64 >( rng.Next() ) << 32 ) |
										 static_cast< unsigned __int64 >( rng.Next() ) );
			}
		}
	}
}
