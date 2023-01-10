#ifndef CHESSMANAGER_H
#define CHESSMANAGER_H

#include "inc/view/ChessView.h"
#include "inc/model/BoardModel.h"

using namespace View;
using namespace Model;

namespace Manager
{
    class ChessManager
    {
    public:
        ChessManager(ChessView &chessView, BoardModel &boardModel);

        void init();

        void movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate);

    private:
        ChessView &mChessView;
        BoardModel &mBoardModel;
    };
}

#endif // CHESSMANAGER_H
