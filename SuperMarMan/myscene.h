#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QApplication>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QDebug>
#include <QColor>
#include <QSound>



class MyScene : public QGraphicsScene
{
    Q_OBJECT
    public :
        MyScene(QObject * parent = 0);
        //Les différentes méthodes utilisées
        void keyPressEvent(QKeyEvent *event); //Lorsqu'on appuie sur une touche
        void keyReleaseEvent(QKeyEvent * event); //Lorsqu'on relache la touche
        void CheckBord(); //Vérification des collisisions et des bords de la scène
        void deplacement(); //Le déplacement à gauche ou à droite du personnage
        void saut(); //Le saut du personnage
        void arrivee(); //Le personnage à la clé et arrive à la porte
        void cle(); //Pour récupérer la clé qui sert à ouvrir la porte
        void vie(); //Perte de vie lors de la collision à une méduse ou à un laser
        void touche(); //La touche 'R' pour recommencer et la touche 'echap' pour quitter le jeu
        void comm(); //L'image qui s'affiche au lancement du programme pour expliquer le but du jeu


    public slots :
        void update(); //La méthode update pour le rafraichissement et donc voir le déplacement du personnage


    private :
        //Création de différents rectangle pour structuré le sol du jeu
        QGraphicsRectItem * sol1;
        QGraphicsRectItem * sol2;
        QGraphicsRectItem * sol3;

        //Création de différents rectangle pour structuré les différentes plateformes du jeu
        QGraphicsRectItem * plat1;
        QGraphicsRectItem * plat2;
        QGraphicsRectItem * plat3;
        QGraphicsRectItem * plat4;
        QGraphicsRectItem * plat5;
        QGraphicsRectItem * plat6;
        QGraphicsRectItem * plat7;

        //Création de différents rectangle pour structuré les différents obstacles du jeu
        QGraphicsRectItem * obs1;
        QGraphicsRectItem * obs2;
        QGraphicsRectItem * obs3;
        QGraphicsRectItem * obs4;
        QGraphicsRectItem * affichage;


        //Création de texte à afficher dans le jeu
        QGraphicsTextItem * fin_jeu;
        QGraphicsTextItem * text_pause;
        QGraphicsTextItem * plus_de_vie;


        //Création des différentes images présentes dans le jeu
        QGraphicsPixmapItem * door; //La porte
        QGraphicsPixmapItem * fond; //Le fond du jeu (l'univers)
        QGraphicsPixmapItem * key; //La clé à récupérer
        QGraphicsPixmapItem * pic; //Notre personnage SuperMarMan vers la droite
        QGraphicsPixmapItem * life1; //Les 5 coeurs pour la vie
        QGraphicsPixmapItem * life2;
        QGraphicsPixmapItem * life3;
        QGraphicsPixmapItem * life4;
        QGraphicsPixmapItem * life5;
        QGraphicsPixmapItem * init; //L'image de début de jeu
        QGraphicsPixmapItem * pig; //Notre personnage SuperMarMan vers la gauche
        QGraphicsPixmapItem * pihd;
        QGraphicsPixmapItem * pihg;

        const int Largeur;//La largeur du terrain
        const int Hauteur;//La hauteur du terrain
        int x_ma,y_ma;//Coordonnées du personnage

        QTimer * timer;//Temps de MAJ pour faire bouger le personnage et les différentes fonctions qui s'y rapporte
        int door_open; //L'entier pour gérer l'ouverture de la porte
        bool keyLeft; //Booléen pour la gestion de la flèche gauche
        bool keyRight; //Booléen pour la gestion de la flèche droite
        bool keyUp; //Booléen pour la gestion de la flèche du haut
        bool keyR; //Booléen pour la gestion de la touche 'R'
        bool keyEchap; //Booléen pour la gestion de la touche 'echap'
        bool keyJ; //Booléen pour la gestion de la touche 'J'
        bool DejaTouche; //Booléen pour savoir si on à déjà réaliser une collision
        bool touchKey; //Booléen quand le personnage prend la clé

        int l_mario,h_mario; //La largeur et la hauteur de notre personnage
        int enpause; //entier pour savoir quand afficher le texte de pause
        int x_s1,y_s1; //Les coordonnée de sol1
        int x_s2,y_s2; //Les coordonnée de sol2
        int x_s3,y_s3; //Les coordonnée de sol3
        int gravite; //Pour gérer la gravite et savoir quand le personnage doit redescendre
        int x_door,y_door; //Les coordonnée de la porte
        int x_key, y_key; //Les coordonnée de la clé
        int x_p1,y_p1; //Les coordonnée de la plateforme1
        int x_p2,y_p2; //Les coordonnée de la plateforme2
        int x_p3,y_p3; //Les coordonnée de la plateforme3
        int x_p4,y_p4; //Les coordonnée de la plateforme4
        int x_p5,y_p5; //Les coordonnée de la plateforme5
        int x_p6,y_p6; //Les coordonnée de la plateforme6
        int x_p7,y_p7; //Les coordonnée de la plateforme7
        int obstacle; //Pour gérer le nombre de vie qu'il reste





};


#endif
