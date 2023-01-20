#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QLabel>
#include "inc/Common.h"


class PieceView : public QLabel
{
    Q_OBJECT
public:
    PieceView(QString displayText, Common::Piece piece);
    void mousePressEvent(QMouseEvent*);
signals:
    void notifyPieceClicked(PieceView *pieceView);
private:
    void createPiece();

    QString mDisplayText;
    Common::Piece mPiece;
};


#endif // PIECEVIEW_H
