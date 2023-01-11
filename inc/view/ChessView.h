#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QObject>

#include "inc/Common.h"

class QGridLayout;
class QLabel;
class QDebug;
class QMainWindow;

namespace View
{
    class ChessView : public QObject
    {
    Q_OBJECT
    public:
        ChessView();


        void initView();
        void movePiece(Common::CoordinatePiece oldCoordinate, Common::CoordinatePiece newCoordinate);

    public slots:
        void updateBoard(Common::CoordinatePiece cordinate, Common::CoordinatePiece newCoordinate);
    signals:
        void notifyBoardChange(Common::CoordinatePiece oldCoordinate, Common::CoordinatePiece newCoordinate);

    private:
        bool isNumberEven(int number);

        void drawBoard();

        QMainWindow *mMainWindow;
        QWidget *mMainWidget;
        QGridLayout *mLayoutBoard;
        QLabel *mPawn;
        QLabel *mWhiteCell;
        QLabel *mBlackCell[8][8];
    };
}


#endif // CHESSVIEW_H
