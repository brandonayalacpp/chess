#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QObject>

#include "inc/Common.h"

class QHBoxLayout;
class QLabel;
class QDebug;
class QMainWindow;
class BoardView;
class PieceView;

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
        QLabel* createPiece(Common::Piece piece);
        QLabel* createPown();


        QMainWindow *mMainWindow;
        QWidget *mMainWidget;
        BoardView *mBoardView;
    };
}


#endif // CHESSVIEW_H
