#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>

#include "inc/Common.h"

using namespace Common;

namespace Model
{
    class BoardModel : public QObject
    {
    Q_OBJECT
    public:
        void initBoardModel();
        PieceID retrievePieceID(CoordinatePiece oldCoordinate);
        void updateBoard(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate);

    public slots:
        void test(CoordinatePiece cordinate, CoordinatePiece newCoordinate);

    signals:
        void notifyBoardChange(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate);
    private:
        PieceID mBoard[BOARD_SIZE][BOARD_SIZE];

    };
}


#endif // BOARDMODEL_H
