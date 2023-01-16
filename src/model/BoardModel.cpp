#include "inc/model/BoardModel.h"

using namespace Model;

void BoardModel::initBoardModel()
{}
Piece BoardModel::retrievePiece(CoordinatePiece coordinate)
{
    return Piece::PID_EMPTY;
}

void BoardModel::setPiece(CoordinatePiece coordinatePiece, Piece piece)
{
    int row = coordinatePiece.row;
    int col = coordinatePiece.col;

    mBoard[row][col] = piece;
    emit updateBoard(coordinatePiece, piece);
}




