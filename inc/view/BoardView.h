#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>

#include <inc/Common.h>



class QGridLayout;
class QLabel;
class PieceView;

class BoardView : public QWidget
{
    Q_OBJECT
public:
    BoardView();
    void setPiece(PieceView *piece, int row, int col);
public slots:
    void onPieceClicked(PieceView *pieceView);

private:
    void createBoard();
    QLabel* createCellName(const QString &cellName);
    bool isNumberEven(int number);

private:
    QGridLayout *mLayoutBoard;
    QLabel *mCells[BOARD_SIZE][BOARD_SIZE];

};


#endif // BOARDVIEW_H
