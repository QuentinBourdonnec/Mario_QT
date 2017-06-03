#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow()
{
    //le widget dans lequel tout s'affiche
    widget_general = new QWidget;
    QHBoxLayout * qbl_general = new QHBoxLayout;
    widget_general->setLayout(qbl_general);
    this->setCentralWidget(widget_general);

    setWindowTitle("Super Marman"); //Ajout d'un titre à la fenêtre de jeu, ici SuperMarMan en référence à Super Mario et Superman
    setWindowIcon(QIcon(":/img/icon")); //Ajout d'un icone à la fenêtre


    QGraphicsView * myview; //On créer une vue
    myscene = new MyScene(this);
    myview = new QGraphicsView(myscene, this);

    myview->setFixedSize(900, 400); //On fixe la taille de la vue à 900px par 400px

    myview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Suppression de la barre de scrolling horizontale
    myview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Suppression de la barre de scrolling verticale

    myview->setStyleSheet("background-color: black"); //Le fixe le fond de la vue en noir
    qbl_general->addWidget(myview);
}

MainWindow::~MainWindow()
{

}

