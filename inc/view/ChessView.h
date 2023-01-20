#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QObject>

#include "inc/Common.h"

class QHBoxLayout;
class QLabel;
class QDebug;
class QMainWindow;
class BoardView;

namespace View
{
    class ChessView : public QObject
    {
    Q_OBJECT
    public:
        ChessView();
        void show();

    public slots:
        void setBoard(const std::vector<Common::Piece> &pieces);
        void updateBoard(Common::Piece piece);

    private:
        void createView();
        void createPieces(const std::vector<Common::Piece> &pieces);
        QLabel* createPiece(Common::PieceName pieceName);
        QLabel* createPown();


        QMainWindow *mMainWindow;
        QWidget *mMainWidget;
        BoardView *mBoardView;
        QLabel *mPawn;
        QLabel *mCells[BOARD_SIZE][BOARD_SIZE];
        QMap<Common::PieceName, QLabel*> *mPieceMap;
    };
}


#endif // CHESSVIEW_H
