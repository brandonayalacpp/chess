#ifndef CHESSMANAGER_H
#define CHESSMANAGER_H

#include "inc/Common.h"

#include <vector>

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
        void setupGame();
        void updateBoard(Common::Piece piece);

    private:
        std::vector<Common::Piece> createPieces();
        View::ChessView *mChessView;
        Model::BoardModel *mBoardModel;
    };
}

#endif // CHESSMANAGER_H
