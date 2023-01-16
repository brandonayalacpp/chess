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
         mPawn(new QLabel)
{

}

void ChessView::initView()
{
    drawBoard();
    mMainWidget->setLayout(mLayoutBoard);
    mMainWindow->setCentralWidget(mMainWidget);
    mMainWindow->show();
}
void ChessView::movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
{}

void ChessView::updateBoard(CoordinatePiece cordinate, CoordinatePiece newCoordinate)
{

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
    cellNameLabel->setStyleSheet("font: 15pt;");
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

            if(!isNumberEven(i + 1))
            {
                if(isNumberEven(j + 1))
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : black; color : blue; }");

                }
                else
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : white; color : blue; }");
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


