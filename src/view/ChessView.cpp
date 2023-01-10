#include "inc/view/ChessView.h"

using namespace View;

ChessView::ChessView()
        :mMainWidget(new QWidget),
         mLayoutBoard(new QGridLayout)
{

}


void ChessView::initView()
{
    drawBoard();
    mMainWidget->setLayout(mLayoutBoard);
    mMainWindow.setCentralWidget(mMainWidget);
    mMainWindow.show();
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
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        for(int j = 0; j < BOARD_SIZE; ++j)
        {
            //QLabel mBlackCell;
            mBlackCell[i][j].setFixedHeight(50);
            mBlackCell[i][j].setFixedWidth(50);

            if(!isNumberEven(i + 1))
            {
                if(isNumberEven(j + 1))
                {
                    mBlackCell[i][j].setStyleSheet("QLabel { background-color : black; color : blue; }");

                }
                else
                {
                    mBlackCell[i][j].setStyleSheet("QLabel { background-color : white; color : blue; }");
                }

            }
            else
            {
                if(!isNumberEven(j + 1))
                {
                    mBlackCell[i][j].setStyleSheet("QLabel { background-color : black; color : blue; }");

                }
                else
                {
                    mBlackCell[i][j].setStyleSheet("QLabel { background-color : white; color : blue; }");
                }
            }

            //mBlackCell[i][j].setStyleSheet("QLabel { background-color : red; color : blue; }");
            mLayoutBoard->addWidget(&mBlackCell[i][j],i,j);
        }
    }

}


