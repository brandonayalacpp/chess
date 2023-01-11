#include "inc/manager/ChessManager.h"
#include "inc/view/ChessView.h"
#include "inc/model/BoardModel.h"

using namespace Manager;
using namespace View;
using namespace Model;

ChessManager::ChessManager(ChessView *chessView, BoardModel *boardModel)
    :mChessView(chessView),
     mBoardModel(boardModel)
{}

void ChessManager::init()
{
    QObject::connect(mBoardModel, &BoardModel::notifyBoardChange, mChessView, &ChessView::updateBoard);
    mChessView->initView();


}

void ChessManager::movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
{}
