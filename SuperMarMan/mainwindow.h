#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "myscene.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

public slots:

private:
    QWidget * widget_general; //Création de plusieurs attributs pour notre classe MainWindow
    QGraphicsView * myview;
    MyScene * myscene;
};

#endif // MAINWINDOW_H
