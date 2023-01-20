#include "inc/view/BoardView.h"

#include <QLabel>
#include <QGridLayout>

BoardView::BoardView()
    :mLayoutBoard(new QGridLayout)
{
    setLayout(mLayoutBoard);
    createBoard();
}

void BoardView::setPiece(QLabel *piece, int row, int col)
{
    mLayoutBoard->addWidget(piece,row + 1,col + 1,1,1, Qt::AlignCenter);
}




void BoardView::createBoard()
{

    QStringList columnNames = {"1","2","3","4","5","6","7","8"};
    QStringList rowNames = {"A","B","C","D","E","F","G","H"};
    //mLayoutBoard->setAlignment(Qt::AlignCenter);
    for(int i =  1; i <= BOARD_SIZE ; ++i)
    {
        QLabel *columnName =  createCellName(columnNames[i-1]);
        QLabel *rowName =  createCellName(rowNames[i-1]);
        columnName->setStyleSheet("QLabel{font-size: 18pt;}");
        rowName->setStyleSheet("QLabel{font-size: 18pt;}");
        mLayoutBoard->addWidget(columnName,0,i,1,1);
        mLayoutBoard->addWidget(rowName,i,0,1,1);
    }

    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        for(int j = 0; j < BOARD_SIZE; ++j)
        {
            //QLabel mCells;
            mCells[i][j] = new QLabel;
            mCells[i][j]->setFixedHeight(CELL_SIZE);
            mCells[i][j]->setFixedWidth(CELL_SIZE);
            mCells[i][j]->setAlignment(Qt::AlignCenter);

            if(!isNumberEven(i + 1))
            {
                if(isNumberEven(j + 1))
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : green;  }");

                }
                else
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : gray; }");
                }

            }
            else
            {
                if(!isNumberEven(j + 1))
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : green; }");

                }
                else
                {
                    mCells[i][j]->setStyleSheet("QLabel { background-color : gray;}");
                }
            }

            mLayoutBoard->addWidget(mCells[i][j],i + 1,j + 1,1,1, Qt::AlignCenter);
        }
    }
}

QLabel* BoardView::createCellName(const QString &cellName)
{
    QLabel *cellNameLabel =  new QLabel;
    cellNameLabel->setAlignment(Qt::AlignCenter);
    cellNameLabel->setText(cellName);
    cellNameLabel->setFixedHeight(CELL_SIZE);
    cellNameLabel->setFixedWidth(CELL_SIZE);

    return cellNameLabel;

}

bool BoardView::isNumberEven(int number)
{
    return number % 2 == 0 ? true:false;
}

