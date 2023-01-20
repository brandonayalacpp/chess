#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QLabel>
#include <QMap>
#include "inc/Common.h"


class PieceView : public QLabel
{
    Q_OBJECT
public:
    PieceView(Common::Piece piece);
    void mousePressEvent(QMouseEvent*);
signals:
    void notifyPieceClicked(PieceView *pieceView);
private:
    void createPiece();

    Common::Piece mPiece;
    QMap<Common::ColorPiece,QString> mStylesMap;
};


#endif // PIECEVIEW_H
