#include "inc/manager/ChessManager.h"

using namespace Manager;

ChessManager::ChessManager(ChessView &chessView, BoardModel &boardModel)
    :mChessView(chessView),
     mBoardModel(boardModel)
{}

void ChessManager::init()
{
    QObject::connect(&mBoardModel, &BoardModel::notifyBoardChange, &mChessView, &ChessView::updateBoard);
    mChessView.initView();


}

void ChessManager::movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
{}




