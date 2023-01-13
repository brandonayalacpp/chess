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
#define INDEX_LEFT_EDGE 0
#define INDEX_RIGHT_EDGE 9
#define INDEX_TOP_EDGE 0
#define INDEX_BOTTOM_EDGE 9

#endif // COMMON_H
