#include "inc/view/PieceView.h"

PieceView::PieceView(QString text, Common::Piece piece)
    :mDisplayText(text),
     mPiece(piece)
{
    createPiece();
}

void PieceView::createPiece()
{
    setFixedHeight(PIECE_SIZE);
    setFixedWidth(PIECE_SIZE);
    setAlignment(Qt::AlignCenter);
    setText(mDisplayText);

    if(mPiece.colorPiece == Common::ColorPiece::CP_BLACK)
    {
        setStyleSheet("QLabel { background-color : black; color : white; font-size: 22pt; }");
    }
    else if(mPiece.colorPiece == Common::ColorPiece::CP_WHITE)
    {
        setStyleSheet("QLabel { background-color : white; color : black; font-size: 22pt; }");
    }
}
