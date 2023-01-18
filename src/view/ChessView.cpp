#include "inc/view/ChessView.h"

#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QMainWindow>

using namespace View;
using namespace Common;

ChessView::ChessView()
        :mMainWindow(new QMainWindow),
         mMainWidget(new QWidget),
         mLayoutBoard(new QGridLayout),
         mPieceMap(new QMap<PieceName,QLabel*>)
{
    createView();
}
void ChessView::show()
{
    mMainWindow->show();
}

void ChessView::createView()
{
    createBoard();
    mMainWidget->setLayout(mLayoutBoard);
    mMainWindow->setCentralWidget(mMainWidget);
    mMainWindow->show();
}
void ChessView::setBoard(const std::vector<Common::Piece> &pieces)
{
    createPieces(pieces);
}

void ChessView::updateBoard(Piece piece)
{
    int row = piece.position.row;
    int col = piece.position.col;
    QLabel *pieceWidget = (*mPieceMap)[piece.pieceName];
    mLayoutBoard->addWidget(pieceWidget,row + 1, col + 1, 1, 1, Qt::AlignCenter);
}

bool ChessView::isNumberEven(int number)
{
    return number % 2 == 0 ? true:false;
}

QLabel* ChessView::createCellName(const QString &cellName)
{
    QLabel *cellNameLabel =  new QLabel;
    cellNameLabel->setAlignment(Qt::AlignCenter);
    cellNameLabel->setText(cellName);
    cellNameLabel->setFixedHeight(CELL_SIZE);
    cellNameLabel->setFixedWidth(CELL_SIZE);

    return cellNameLabel;

}

void ChessView::createBoard()
{

    QStringList columnNames = {"1","2","3","4","5","6","7","8"};
    QStringList rowNames = {"A","B","C","D","E","F","G","H"};
    //mLayoutBoard->setAlignment(Qt::AlignCenter);
    for(int i =  1; i <= BOARD_SIZE ; ++i)
    {
        QLabel *columnName =  createCellName(columnNames[i-1]);
        QLabel *rowName =  createCellName(rowNames[i-1]);
        columnName->setStyleSheet("QLabel{font-size: 18pt;}");
        rowName->setStyleSheet("QLabel{font-size: 18pt;}");
        mLayoutBoard->addWidget(columnName,0,i,1,1);
        mLayoutBoard->addWidget(rowName,i,0,1,1);
    }

    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        for(int j = 0; j < BOARD_SIZE; ++j)
        {
            //QLabel mCells;
            mCells[i][j] = new QLabel;
            mCells[i][j]->setFixedHeight(CELL_SIZE);
            mCells[i][j]->setFixedWidth(CELL_SIZE);
            mCells[i][j]->setAlignment(Qt::AlignCenter);

            if(!isNumberEven(i + 1))
            {
                if(isNumberEven(j + 1))
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : green;  }");

                }
                else
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : gray; }");
                }

            }
            else
            {
                if(!isNumberEven(j + 1))
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : green; }");

                }
                else
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : gray;}");
                }
            }

            mLayoutBoard->addWidget(mCells[i][j],i + 1,j + 1,1,1, Qt::AlignCenter);
        }
    }

}

void ChessView::createPieces(const std::vector<Common::Piece> &pieces)
{
    int row;
    int col;

    for(int i = 0; i < pieces.size(); ++i)
    {
        Piece piece = pieces[i];
        QLabel* pieceWidget =  createPiece(piece.pieceName);
        row = piece.position.row;
        col = piece.position.col;
        mLayoutBoard->addWidget(pieceWidget,row + 1,col + 1,1,1, Qt::AlignCenter);
        mPieceMap->insert(piece.pieceName,pieceWidget);
    }
}

QLabel* ChessView::createPiece(PieceName pieceName)
{
    QLabel *tempPiece;
    switch(pieceName)
    {
        case PieceName::PN_PAWN_DARK:
            tempPiece = createPown();
            tempPiece->setStyleSheet("QLabel { background-color : black; color : white; font-size: 22pt; }");
            return tempPiece;
    case PieceName::PN_PAWN_WHITE:
            tempPiece = createPown();
            tempPiece->setStyleSheet("QLabel { background-color : white; color : black; font-size: 22pt; }");
        return tempPiece;
    }

    return nullptr;
}

QLabel* ChessView::createPown()
{
    QLabel *pown = new QLabel;
    pown->setFixedHeight(PIECE_SIZE);
    pown->setFixedWidth(PIECE_SIZE);
    pown->setAlignment(Qt::AlignCenter);
    pown->setText("P");

    return pown;
}







