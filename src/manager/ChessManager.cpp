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
    QObject::connect(mBoardModel, &BoardModel::updateBoard, mChessView, &ChessView::updateBoard);
    setPieces();
    mChessView->show();


}

void ChessManager::movePiece(CoordinatePiece oldCoordinate, CoordinatePiece newCoordinate)
{}

void ChessManager::setPieces()
{
    CoordinatePiece coordinate;
    coordinate.row = 0;
    coordinate.col = 0;

    Piece pown = Piece::PID_PAWN_DARK;
    mBoardModel->setPiece(coordinate,pown);

}
