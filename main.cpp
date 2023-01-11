#include "mainwindow.h"

#include <QApplication>
#include <QObject>

#include "inc/manager/ChessManager.h"
#include "inc/model/BoardModel.h"
#include "inc/view/ChessView.h"



using namespace View;
using namespace Manager;
using namespace Model;

class Startup
{
public:
    Startup()
        :mChessView(new ChessView),
         mBoardModel(new BoardModel),
         mChessManager(new ChessManager(mChessView,mBoardModel))
    {}

    void init()
    {
        mChessManager->init();
    }

private:
    ChessView *mChessView;
    BoardModel *mBoardModel;
    ChessManager *mChessManager;

};





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Startup startup;
    startup.init();

    return a.exec();
}
