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
        Piece retrievePiece(CoordinatePiece coordinate);
        void setPiece(CoordinatePiece coordinatePiece, Piece piece);

    signals:
        void updateBoard(CoordinatePiece coordinatePiece, Piece Piece);
    private:
        Piece mBoard[BOARD_SIZE][BOARD_SIZE];

    };
}


#endif // BOARDMODEL_H
