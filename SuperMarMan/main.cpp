#include "mainwindow.h"
//#include "myscene.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(970, 450); //on fixe la taille de la scene à 900x900
    w.show();
    return a.exec();
}
