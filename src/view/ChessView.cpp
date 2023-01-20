#include "inc/view/ChessView.h"

#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>

#include "inc/view/BoardView.h"
#include "inc/view/PieceView.h"

using namespace View;
using namespace Common;

ChessView::ChessView()
        :mMainWindow(new QMainWindow),
         mMainWidget(new QWidget),
         mBoardView(new BoardView)
{
    createView();
}
void ChessView::show()
{
    mMainWindow->show();
}

void ChessView::createView()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(mBoardView);
    mMainWidget->setLayout(mainLayout);
    mMainWindow->setCentralWidget(mMainWidget);
    mMainWindow->adjustSize();
    mMainWindow->move(QApplication::desktop()->screen()->rect().center() - mMainWindow->rect().center());
}
void ChessView::setBoard(const std::vector<Common::Piece> &pieces)
{
    createPieces(pieces);
}

void ChessView::updateBoard(Piece piece)
{
//    int row = piece.position.row;
//    int col = piece.position.col;
//    QLabel *pieceWidget = (*mPieceMap)[piece.pieceName];
//    mLayoutBoard->addWidget(pieceWidget,row + 1, col + 1, 1, 1, Qt::AlignCenter);
}

void ChessView::createPieces(const std::vector<Common::Piece> &pieces)
{
    int row;
    int col;

    for(int i = 0; i < pieces.size(); ++i)
    {
        Piece piece = pieces[i];
        QLabel* pieceWidget =  createPiece(piece);
        row = piece.position.row;
        col = piece.position.col;
        mBoardView->setPiece(pieceWidget,row ,col);
        //mPieceMap->insert(piece.pieceName,pieceWidget);
    }
}

QLabel* ChessView::createPiece(Piece piece)
{
    PieceView *tempPiece;
    switch(piece.pieceName)
    {
        case PieceName::PN_PAWN:
            tempPiece = new PieceView("P",piece);
            return tempPiece;
    }

    return nullptr;
}






