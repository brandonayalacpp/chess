#include "inc/view/PieceView.h"

#include <QString>

PieceView::PieceView(Common::Piece piece)
     :mPiece(piece)
{
    createPiece();
}

void PieceView::createPiece()
{
    setFixedHeight(PIECE_SIZE);
    setFixedWidth(PIECE_SIZE);
    setAlignment(Qt::AlignCenter);
    setText(QString::fromStdString(mPiece.pieceString));
    setStyleSheet(QString::fromStdString(mPiece.pieceStyle));
}

void PieceView::mousePressEvent(QMouseEvent*)
{
    setStyleSheet("QLabel { background-color : yellow; color : white; font-size: 22pt; }");
    emit notifyPieceClicked(this);
}

