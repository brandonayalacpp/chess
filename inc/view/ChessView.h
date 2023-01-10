#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QMainWindow>

#include "inc/Common.h"

using namespace Common;

namespace View
{
    class ChessView : public QObject
    {
    Q_OBJECT
    public:
        ChessView();


        void initView();
        void movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate);

    public slots:
        void updateBoard(CoordinatePiece cordinate, CoordinatePiece newCoordinate);
    signals:
        void notifyBoardChange(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate);

    private:
        bool isNumberEven(int number);

        void drawBoard();

        QMainWindow mMainWindow;
        QWidget *mMainWidget;
        QGridLayout *mLayoutBoard;
        QLabel mPawn;
        QLabel mWhiteCell;
        QLabel mBlackCell[8][8];
    };
}


#endif // CHESSVIEW_H
