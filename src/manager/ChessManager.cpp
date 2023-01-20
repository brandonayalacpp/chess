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

void ChessManager::setupGame()
{
    QObject::connect(mBoardModel, &BoardModel::notifySetBoard, mChessView, &ChessView::setBoard);
    QObject::connect(mBoardModel, &BoardModel::notifyUpdateBoard, mChessView, &ChessView::updateBoard);
    std::vector<Common::Piece> pieces =  createPieces();
    mBoardModel->setBoard(pieces);
    mChessView->show();
}

void ChessManager::updateBoard(Common::Piece piece)
{

}

std::vector<Common::Piece> ChessManager::createPieces()
{
    Position position;
    position.row = 0;
    position.col = 0;

    Piece pown;
    pown.pieceName = PieceName::PN_PAWN;
    pown.pieceString = "P";
    pown.position = position;
    pown.colorPiece = ColorPiece::CP_BLACK;
    pown.pieceStyle = "QLabel { background-color : black; color : white; font-size: 22pt; }";


    std::vector<Common::Piece> pieces;
    pieces.push_back(pown);

    position.row = 7;
    position.col = 0;
    pown.position = position;
    pown.colorPiece = ColorPiece::CP_WHITE;
    pown.pieceStyle = "QLabel { background-color : white; color : black; font-size: 22pt; }";

    pieces.push_back(pown);

    return pieces;
}
