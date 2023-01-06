#include "mainwindow.h"

#include <QApplication>

namespace Common
{
    enum PieceID
    {
        PID_EMPTY,
        PID_PAWN_WHITE,
        PID_PAWN_DARK
    };

    struct CoordinatePiece
    {
        int row;
        int col;
    };


}

#define BOARD_SIZE 8
using namespace Common;

namespace Model
{
    class BoardModel
    {
    public:
        void initBoardModel()
        {}
        PieceID retrievePieceID(CoordinatePiece oldCoordinate)
        {}
        void updateBoard(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
        {}
    private:
        PieceID mBoard[BOARD_SIZE][BOARD_SIZE];

    };
}

namespace Controller
{
    class ChessController
    {
    public:
        void movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
        {}
    };
}

#include <QGridLayout>
#include <QLabel>
#include <QDebug>
namespace View
{
    class ChessView
    {
    public:
        ChessView()
            :mMainWidget(new QWidget),
             mLayoutBoard(new QGridLayout)
        {

        }


        void initView()
        {
            qDebug()<<"Holi init";
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


            mMainWidget->setLayout(mLayoutBoard);
            mMainWindow.setCentralWidget(mMainWidget);
            mMainWindow.show();
            qDebug()<<"Holi Finished";
        }
        void movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
        {}
        void updateBoard(CoordinatePiece cordinate, PieceID pieceId)
        {}

    private:
        bool isNumberEven(int number)
        {
            return number % 2 == 0 ? true:false;
        }

        QMainWindow mMainWindow;
        QWidget *mMainWidget;
        QGridLayout *mLayoutBoard;
        QLabel mPawn;
        QLabel mWhiteCell;
        QLabel mBlackCell[8][8];
    };
}




using namespace View;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessView chessView;
    chessView.initView();

    return a.exec();
}
