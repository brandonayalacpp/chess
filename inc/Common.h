#ifndef COMMON_H
#define COMMON_H

namespace Common
{
    enum PieceID
    {
        PID_EMPTY,
        PID_PAWN_WHITE,
        PID_PAWN_DARK
    };

    struct CoordinatePiece
    {
        int row;
        int col;
    };


}

#define BOARD_SIZE 8

#endif // COMMON_H
