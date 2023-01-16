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
         mPieceMap(new QMap<Piece,QString>)
{

}

void ChessView::initView()
{
    mPieceMap->insert(Piece::PID_PAWN_DARK, "P");
    mPieceMap->insert(Piece::PID_EMPTY, " ");
    drawBoard();
    mMainWidget->setLayout(mLayoutBoard);
    mMainWindow->setCentralWidget(mMainWidget);
    mMainWindow->show();
}
void ChessView::movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
{}

void ChessView::updateBoard(CoordinatePiece coordinate, Piece piece)
{
    int row = coordinate.row;
    int col = coordinate.col;
    QString stringPiece = (*mPieceMap)[piece];
    mCells[row][col]->setText(stringPiece);
    //mCells[row][col]->setStyleSheet("QLabel{font-size: 22pt;}");


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





void ChessView::drawBoard()
{

    QStringList columnNames = {"1","2","3","4","5","6","7","8"};
    QStringList rowNames = {"A","B","C","D","E","F","G","H"};

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
                    mCells[i][j]->setStyleSheet("QLabel { background-color : black; color : blue; font-size: 22pt; }");

                }
                else
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : white; color : blue; font-size: 22pt; }");
                }

            }
            else
            {
                if(!isNumberEven(j + 1))
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : black; color : blue; }");

                }
                else
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : white; color : blue; }");
                }
            }

            mLayoutBoard->addWidget(mCells[i][j],i + 1,j + 1,1,1);
        }
    }

}


