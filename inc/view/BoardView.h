#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>

#include <inc/Common.h>


class QGridLayout;
class QLabel;

class BoardView : public QWidget
{
public:
    BoardView();
    void setPiece(QLabel *piece, int row, int col);

private:
    void createBoard();
    QLabel* createCellName(const QString &cellName);
    bool isNumberEven(int number);

private:
    QGridLayout *mLayoutBoard;
    QLabel *mCells[BOARD_SIZE][BOARD_SIZE];

};


#endif // BOARDVIEW_H
