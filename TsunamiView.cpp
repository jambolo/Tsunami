/*****************************************************************************

                               TsunamiView.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Tsunami/TsunamiView.cpp#2 $

	$NoKeywords: $

*****************************************************************************/

#include "stdafx.h"

#include "TsunamiView.h"

#include "TsunamiDoc.h"
#include "Board.h"
#include "GameRecordEntry.h"
#include "GameTree.h"

#include <sstream>
#include <limits>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


namespace
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

std::ostringstream & operator<<( std::ostringstream & stream, GameRecordEntry const & entry )
{
//	stream << entry.m_Piece->GetSymbol();
//	stream << char( 'a' + entry.m_Move.m_From.m_Column ) << 8 - entry.m_Move.m_From.m_Row << '-';
//	stream << char( 'a' + entry.m_Move.m_To.m_Column ) << 8 - entry.m_Move.m_To.m_Row;

	return stream;
}

} // anonymous namespace



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CTsunamiView::CTsunamiView()
{
	// TODO: add construction code here

}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CTsunamiView::~CTsunamiView()
{
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

BOOL CTsunamiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

#ifdef _DEBUG


void CTsunamiView::AssertValid() const
{
	CView::AssertValid();
}


void CTsunamiView::Dump( CDumpContext& dc ) const
{
	CView::Dump(dc);
}


CTsunamiDoc * CTsunamiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTsunamiDoc)));
	return static_cast< CTsunamiDoc* >( m_pDocument );
}

CTsunamiDoc const * CTsunamiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTsunamiDoc)));
	return static_cast< CTsunamiDoc* >( m_pDocument );
}


#endif //_DEBUG



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

IMPLEMENT_DYNCREATE( CTsunamiView, CView )

BEGIN_MESSAGE_MAP( CTsunamiView, CView )
	//{{AFX_MSG_MAP(CTsunamiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND( ID_FILE_PRINT, CView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_DIRECT, CView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview )
END_MESSAGE_MAP()



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiView::OnDraw( CDC * pDC)
{
	CTsunamiDoc* pDoc = GetDocument();
	ASSERT_VALID( pDoc );

//	DrawBoard( pDC, CPoint( 20, 20 ) );
//	DrawStats( pDC, CPoint( 20, 400 ) );
//	DrawRecord( pDC, CPoint( 400, 20 ) );
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

BOOL CTsunamiView::OnPreparePrinting( CPrintInfo * pInfo )
{
	// default preparation
	return DoPreparePrinting( pInfo );
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiView::OnBeginPrinting( CDC * /*pDC*/, CPrintInfo * /*pInfo*/ )
{
	// TODO: add extra initialization before printing
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiView::OnEndPrinting( CDC * pDC, CPrintInfo * pInfo )
{
	// TODO: add cleanup after printing
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiView::DrawBoard( CDC * dc, CPoint const & xy ) const
{
//	int const board_size = 320;
//	int const square_size = board_size  / Board::BOARD_SIZE;
//	Board const & board = GetDocument()->m_GameState.m_Board;
//
//		// Do the board outline
//
//	CBrush	outline_brush( RGB( 0, 0, 0 ) );
//	CRect	outline_rect( xy, CSize( board_size+2, board_size+2 ) );
//
//	dc->FrameRect( &outline_rect, &outline_brush );
//
//		// Draw the squares
//
//	CBrush white_brush( RGB( 192, 192, 192 ) );
//	CBrush black_brush( RGB( 128, 128, 128 ) );
//	dc->SelectStockObject( NULL_PEN );
//	int y = outline_rect.top + 1;
//	for ( int i = 0; i < Board::BOARD_SIZE; i++ )
//	{
//		int x = outline_rect.left + 1;
//		for ( int j = 0; j < Board::BOARD_SIZE; j++ )
//		{
//			if ( ( ( i ^ j ) & 1 ) == 0 )			// Note: generates a checkerboard pattern
//				dc->SelectObject( &white_brush );
//			else
//				dc->SelectObject( &black_brush );
//
//			dc->Rectangle( x, y, x+square_size+1, y+square_size+1 );
//
//			x += square_size;
//		}
//		y += square_size;
//	}
//
//	dc->SelectStockObject( BLACK_BRUSH );	// Release the last selected brush so it can be deleted
//
//		// Draw the pieces
//
//	CDC bitmap_dc;
//	bitmap_dc.CreateCompatibleDC( NULL );
//
//	CDC image_dc;
//	image_dc.CreateCompatibleDC( NULL );
//	CBitmap image_bitmap;
//	image_bitmap.CreateCompatibleBitmap( dc, square_size, square_size );
//	CBitmap* old_image_bitmap = image_dc.SelectObject( &image_bitmap );
//
//	CDC mask_dc;
//	mask_dc.CreateCompatibleDC( NULL );
//	CBitmap mask_bitmap;
//	mask_bitmap.CreateBitmap( square_size, square_size, 1, 1, NULL );
//	CBitmap* old_mask_bitmap = mask_dc.SelectObject( &mask_bitmap );
//
//	Position p;
//	for ( p.m_Row = 0; p.m_Row < Board::BOARD_SIZE; p.m_Row++ )
//	{
//		for ( p.m_Column = 0; p.m_Column < Board::BOARD_SIZE; p.m_Column++ )
//		{
//			Piece const * const piece	= board.GetPieceAt( p );
//
//			if ( piece != NO_PIECE )
//			{
//				CBitmap const * const bitmap = piece->GetImage();
//
//				BITMAP	bm;
//				const_cast< CBitmap * >( bitmap )->GetBitmap( &bm );
//				ASSERT( bm.bmWidth <= square_size );
//				ASSERT( bm.bmHeight <= square_size );
//
//				CBitmap* old_bitmap = bitmap_dc.SelectObject( const_cast< CBitmap * >( bitmap ) );
//				image_dc.BitBlt( 0, 0, bm.bmWidth, bm.bmHeight, &bitmap_dc, 0, 0, SRCCOPY );
//				bitmap_dc.SelectObject( old_bitmap );
//
//
//				int const x = outline_rect.left+1 + p.m_Column*square_size + ( square_size - bm.bmWidth ) / 2;
//				int const y = outline_rect.top+1 + p.m_Row*square_size + ( square_size - bm.bmHeight ) / 2;
//
//				image_dc.SetBkColor( RGB( 255, 0, 255 ) );
//				mask_dc.BitBlt( 0, 0, bm.bmWidth, bm.bmHeight, &image_dc, 0, 0, SRCCOPY );
//				dc->BitBlt( x, y, bm.bmWidth, bm.bmHeight, &mask_dc, 0, 0, SRCAND );
//				mask_dc.BitBlt( 0, 0, bm.bmWidth, bm.bmHeight, NULL, 0, 0, DSTINVERT );
//				image_dc.SetBkColor( RGB( 255, 255, 255 ) );
//				image_dc.BitBlt( 0, 0, bm.bmWidth, bm.bmHeight, &mask_dc, 0, 0, SRCAND );
//				dc->BitBlt( x, y, bm.bmWidth, bm.bmHeight, &image_dc, 0, 0, SRCPAINT );
//			}
//		}
//	}
//
//	mask_dc.SelectObject( old_mask_bitmap );
//	mask_bitmap.DeleteObject();
//
//	image_dc.SelectObject( old_image_bitmap );
//	image_bitmap.DeleteObject();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiView::DrawStats( CDC * dc, CPoint const & xy ) const
{
//	CTsunamiDoc const * const pdoc = GetDocument();
//
//
//	if ( pdoc->m_GameState.m_Move.IsStartingPosition() )
//		return;
//
//	int x = xy.x;
//	int y = xy.y;
//
//	y += 20;
//
//	if ( pdoc->m_Time >= 0 )
//	{
//		std::ostringstream buffer;
//		buffer << "Elapsed Time: " << pdoc->m_Time / 1000.f << std::ends;
//		dc->TextOut( x, y, buffer.str().c_str() );
//	}
//
//	y += 20;
//
//	if ( pdoc->m_GeneratedStateCount >= 0 )
//	{
//		std::ostringstream buffer;
//		buffer << "Generated States: " << pdoc->m_GeneratedStateCount << std::ends;
//		dc->TextOut( x, y, buffer.str().c_str() );
//	}
//
//	y += 20;
//
//	if ( pdoc->m_EvaluationCount >= 0 )
//	{
//		std::ostringstream buffer;
//		buffer << "Static Evaluations: " << pdoc->m_EvaluationCount << std::ends;
//		dc->TextOut( x, y, buffer.str().c_str() );
//	}
//
//	y += 20;
//
//	if ( pdoc->m_AlphaHitCount >= 0 )
//	{
//		std::ostringstream buffer;
//		buffer << "Alpha hits: " << pdoc->m_AlphaHitCount << "  ";
//		buffer << "Beta hits: " << pdoc->m_BetaHitCount << std::ends;
//		dc->TextOut( x, y, buffer.str().c_str() );
//	}
//
//	y += 20;
//
//	if ( pdoc->m_TTableUsage >= 0 )
//	{
//		std::ostringstream buffer;
//		buffer << "Table usage: " << pdoc->m_TTableUsage << "  ";
//		buffer << "Table checks: " << pdoc->m_TTableCheckCount << "  ";
//		buffer << "Table hits: " << pdoc->m_TTableHitCount << "  ";
//		buffer << "Table collisions: " << pdoc->m_TTableCollisionCount << std::ends;
//		dc->TextOut( x, y, buffer.str().c_str() );
//	}
//
//	y += 20;
//
//	if ( pdoc->m_Value != -std::numeric_limits<float>::infinity() )
//	{
//		std::ostringstream buffer;
//		buffer.setf( std::ios::fixed, std::ios::floatfield );
//		buffer.precision( 1 );
//
//		buffer << "Value: ";
//		if ( pdoc->m_Value == GameTree::MY_CHECKMATE_VALUE )
//			buffer << "I win";
//		else if ( pdoc->m_Value == GameTree::OPPONENT_CHECKMATE_VALUE )
//			buffer << "I lose";
//		else
//			buffer << pdoc->m_Value;
//
//		buffer << " (worst value: ";
//		if ( pdoc->m_WorstValue == GameTree::MY_CHECKMATE_VALUE )
//			buffer << "I win";
//		else if ( pdoc->m_WorstValue == GameTree::OPPONENT_CHECKMATE_VALUE )
//			buffer << "I lose";
//		else
//			buffer << pdoc->m_WorstValue;
//		
//		buffer << ")" << std::ends;
//
//		dc->TextOut( x, y, buffer.str().c_str() );
//	}
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CTsunamiView::DrawRecord( CDC * dc, CPoint const & xy ) const
{
//	int const RECORD_ROWS = 10;
//	GameRecord const & game_record = GetDocument()->m_GameRecord;
//
//	int x = xy.x;
//	int y = xy.y;
//
//	GameRecord::const_iterator e;
//	if ( game_record.size() < RECORD_ROWS*2 )
//		e = game_record.begin();
//	else
//		e = game_record.begin() + ( ( game_record.size()+1 )/2 - RECORD_ROWS ) * 2;
//
//	while ( e != game_record.end() )
//	{
//		// Display move number
//
//		{
//			std::ostringstream move_number;
//			move_number << ( e-game_record.begin() ) / 2 + 1 << '.' << std::ends;
//			dc->TextOut( x, y, move_number.str().c_str() );
//		}
//
//		// Display white's move
//
//		GameRecordEntry const & whites_move = *e++;
//
//		if ( whites_move.m_Piece != NO_PIECE )
//		{
//			std::ostringstream buffer;
//
//			buffer << whites_move << std::ends;
//			dc->TextOut( x+30, y, buffer.str().c_str() );
//		}
//		else
//		{
//			dc->TextOut( x+30, y, "White resigns" );
//			break;
//		}
//
//		if ( e == game_record.end() )
//			break;
//
//		// Display black's move
//
//		GameRecordEntry const & blacks_move = *e++;
//
//		if ( blacks_move.m_Piece != NO_PIECE )
//		{
//			std::ostringstream buffer;
//
//			buffer << blacks_move << std::ends;
//			dc->TextOut( x+120, y, buffer.str().c_str() );
//		}
//		else
//		{
//			dc->TextOut( x+120, y, "Black resigns" );
//			break;
//		}
//
//		// Next row
//
//		y += 20;
//	}
}
