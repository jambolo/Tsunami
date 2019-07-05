/****************************************************************************

                                 GameState.cpp

						Copyright 2000, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/GameState.cpp#2 $

	$NoKeywords: $

****************************************************************************/

#include "StdAfx.h"

#include "GameState.h"

#include "Move.h"
#include "Board.h"
#include "ZHash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GameState::GameState( GameState const & old_state, Move const & move )
{
	m_Board = old_state.m_Board;

#if defined( USING_ZORBRIST_HASH )
	m_HashCode = old_state.GetHashCode();
#endif // defined( USING_ZORBRIST_HASH )

	MakeMove( move );

	// Note: m_Value must be computed explicitly
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void GameState::MakeMove( Move const & move )
{
	m_Move = move;

	// These special moves don't do anything

	if ( move.IsResignation() || move.IsUndo() || move.IsStartingPosition() )
		return;

//	Piece const * const	pPiece		= m_Board.GetPieceAt( move.m_From );
//	Piece const * const	pCaptured	= m_Board.GetPieceAt( move.m_To );
//
//	// Remove a captured piece
//
//	if ( pCaptured != NO_PIECE )
//	{
//#if defined( USING_ZORBRIST_HASH )
//		m_HashCode.Remove( *pCaptured, move.m_To );
//#endif // defined( USING_ZORBRIST_HASH )
//
//		m_Board.RemovePiece( move.m_To );
//	}
//
//	// Move the piece on the board
//
//#if defined( USING_ZORBRIST_HASH )
//	m_HashCode.Remove( *pPiece, move.m_From );
//	m_HashCode.Add( *pPiece, move.m_To );
//#endif // defined( USING_ZORBRIST_HASH )
//
//	m_Board.MovePiece( move.m_From, move.m_To );
//
//	// If a pawn has reached the last row, replace it with a queen of the same color
//
//	if ( pPiece->GetType() == PIECE_PAWN &&
//		 ( move.m_To.m_Row == Board::BOARD_SIZE-1 || move.m_To.m_Row == 0 ) )
//	{
//		// Remove the pawn
//
//#if defined( USING_ZORBRIST_HASH )
//		m_HashCode.Remove( *pPiece, move.m_To );
//#endif // defined( USING_ZORBRIST_HASH )
//
//		m_Board.RemovePiece( move.m_To );
//
//		// Replace with a queen
//
//		Piece const * const	pQueen	= GetQueen( pPiece->GetColor() );
//
//#if defined( USING_ZORBRIST_HASH )
//		m_HashCode.Add( *pQueen, move.m_To );
//#endif // defined( USING_ZORBRIST_HASH )
//
//		m_Board.PutPiece( pQueen, move.m_To );
//	}
}

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void GameState::Initialize()
{
	m_Board.Initialize();

#if defined( USING_ZORBRIST_HASH )
	m_HashCode = ComputeHashCode();
#endif // defined( USING_ZORBRIST_HASH )

	MakeMove( MOVE_0 );

	m_Value = 0.f;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

ZHash GameState::ComputeHashCode() const
{
	ZHash z;

	for ( int r = 0; r < m_Board.GetSize(); r++ )
	{
		for ( int c = 0; c <  m_Board.GetSize(); c++ )
		{
			Stone const	stone	= m_Board.GetStoneAt( r, c );

			if ( stone != STONE_NONE )
			{
				z.Add( stone, r, c );
			}
		}
	}

	return z;
}
