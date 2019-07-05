/****************************************************************************

                                   Move.cpp

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/Move.cpp#2 $

	$NoKeywords: $

****************************************************************************/

#include "StdAfx.h"

#include "Move.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// Special move -- resignation
Move const MOVE_INVALID( Move::SM_INVALID );

// Special move -- resignation
Move const MOVE_RESIGN( Move::SM_RESIGN );

// Special move -- undo
Move const MOVE_UNDO( Move::SM_UNDO );

// Special move -- initial board
Move const MOVE_0( Move::SM_0 );

// All functions are inline