#ifndef PIECEVIEW_H
#define PIECEVIEW_H

#include <QLabel>
#include "inc/Common.h"


class PieceView : public QLabel
{
public:
    PieceView(QString displayText, Common::Piece piece);
private:
    void createPiece();

    QString mDisplayText;
    Common::Piece mPiece;
};


#endif // PIECEVIEW_H
