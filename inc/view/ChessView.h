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
        QLabel* createCellName(const QString &cellName);

        QMainWindow *mMainWindow;
        QWidget *mMainWidget;
        QGridLayout *mLayoutBoard;
        QLabel *mCells[BOARD_SIZE][BOARD_SIZE];
        QLabel *mPawn;
    };
}


#endif // CHESSVIEW_H
