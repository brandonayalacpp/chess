#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QObject>

#include "inc/Common.h"

class QGridLayout;
class QLabel;
class QDebug;
class QMainWindow;

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
        void createBoard();
        void createPieces(const std::vector<Common::Piece> &pieces);
        QLabel* createPiece(Common::PieceName pieceName);
        QLabel* createPown();
        bool isNumberEven(int number);
        QLabel* createCellName(const QString &cellName);

        QMainWindow *mMainWindow;
        QWidget *mMainWidget;
        QGridLayout *mLayoutBoard;
        QLabel *mPawn;
        QLabel *mCells[BOARD_SIZE][BOARD_SIZE];
        QMap<Common::PieceName, QLabel*> *mPieceMap;
    };
}


#endif // CHESSVIEW_H
