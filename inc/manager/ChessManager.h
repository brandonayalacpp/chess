#ifndef CHESSMANAGER_H
#define CHESSMANAGER_H

#include "inc/Common.h"

namespace View
{
    class ChessView;
}

namespace Model
{
    class BoardModel;
}

namespace Manager
{
    class ChessManager
    {
    public:
        ChessManager(View::ChessView *chessView, Model::BoardModel *boardModel);

        void init();

        void movePiece(Common::CoordinatePiece oldCoordinate,
                       Common::CoordinatePiece newCoordinate);

    private:
        void setPieces();
        View::ChessView *mChessView;
        Model::BoardModel *mBoardModel;
    };
}

#endif // CHESSMANAGER_H
