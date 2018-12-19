#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setWindowIcon(QIcon(":/tetris.ico"));
    w.setWindowTitle("词典");
    w.setWindowOpacity(0.95);
    w.show();



    return a.exec();
}
