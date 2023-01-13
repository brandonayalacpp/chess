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
         mLayoutBoard(new QGridLayout)
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

void ChessView::drawBoard()
{
//    QLabel *rowNames =  new QLabel("1 2 3 4 5 6 7 8");
//    rowNames->setStyleSheet("QLabel { background-color : blue; color : black; }");
//    mLayoutBoard->addWidget(rowNames,0,0,1,10);


    for(int i =  1; i <= BOARD_SIZE ; ++i)
    {
        QLabel *rowName =  new QLabel;
        rowName->setAlignment(Qt::AlignCenter);
        rowName->setText(QString::number(i));
        rowName->setFixedHeight(50);
        rowName->setFixedWidth(50);
        //rowName->setStyleSheet("QLabel { background-color : blue; color : black; }");
        mLayoutBoard->addWidget(rowName,0,i,1,1);


//        mBlackCell[i][INDEX_LEFT_EDGE] = new QLabel;
//        mBlackCell[i][INDEX_LEFT_EDGE]->setFixedHeight(50);
//        mBlackCell[i][INDEX_LEFT_EDGE]->setFixedWidth(50);
//        mBlackCell[i][INDEX_LEFT_EDGE]->setStyleSheet("QLabel { background-color : blue; color : black; }");


//            mBlackCell[i][INDEX_LEFT_EDGE]->setText(QString(i-1));

    }


    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        for(int j = 0; j < BOARD_SIZE; ++j)
        {
            //QLabel mBlackCell;
            mBlackCell[i][j] = new QLabel;
            mBlackCell[i][j]->setFixedHeight(50);
            mBlackCell[i][j]->setFixedWidth(50);

            if(!isNumberEven(i + 1))
            {
                if(isNumberEven(j + 1))
                {
                    mBlackCell[i][j]->setStyleSheet("QLabel { background-color : black; color : blue; }");

                }
                else
                {
                    mBlackCell[i][j]->setStyleSheet("QLabel { background-color : white; color : blue; }");
                }

            }
            else
            {
                if(!isNumberEven(j + 1))
                {
                    mBlackCell[i][j]->setStyleSheet("QLabel { background-color : black; color : blue; }");

                }
                else
                {
                    mBlackCell[i][j]->setStyleSheet("QLabel { background-color : white; color : blue; }");
                }
            }

            mLayoutBoard->addWidget(mBlackCell[i][j],i + 1,j + 1,1,1);
        }
    }

}


