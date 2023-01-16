#include "inc/manager/ChessManager.h"
#include "inc/view/ChessView.h"
#include "inc/model/BoardModel.h"

using namespace Manager;
using namespace View;
using namespace Model;
//using namespace Common;

ChessManager::ChessManager(ChessView *chessView, BoardModel *boardModel)
    :mChessView(chessView),
     mBoardModel(boardModel)
{}

void ChessManager::init()
{
    QObject::connect(mBoardModel, &BoardModel::updateBoard, mChessView, &ChessView::updateBoard);
    mChessView->initView();
    CoordinatePiece coordinate;
    coordinate.row = 0;
    coordinate.col = 0;

    Piece pown = Piece::PID_PAWN_DARK;
    mBoardModel->setPiece(coordinate,pown);

}

void ChessManager::movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
{}
