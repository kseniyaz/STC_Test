#include "widget.h"
#include "choosefilewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChooseFileWindow win;
    win.show();
    return a.exec();
}
