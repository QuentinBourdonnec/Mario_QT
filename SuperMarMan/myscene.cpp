#include "myscene.h"

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent), Largeur(1536), Hauteur(864)
{

    keyLeft = false; //Initialisation de notre booléen de flèche gauche à faux
    keyRight = false; //Initialisation de notre booléen de flèche droite à faux
    keyUp = false; //Initialisation de notre booléen de flèche gaut à faux
    DejaTouche = false; //Initialisation de notre booléen pour savoir si on a une collision à faux
    keyJ = false; //Initialisation de notre booléen de touche 'J' à faux
    keyR = false; //Initialisation de notre booléen de touche 'R' à faux
    keyEchap = false; //Initialisation de notre booléen de touche 'echap' à faux
    touchKey = false; //Initialisation de notre booléen de récupération de la clé

    enpause = 1; //On met notre entier pour gérer l'affichage du texte de pause
    l_mario = 45; //La largeur du mario
    h_mario = 80; //La hauteur du mario
    x_s1 = 0; //Abscisse du sol1
    y_s1 = 746; //Ordonnée du sol1
    x_s2 = 900; //Abscisse du sol2
    y_s2 = 340; //Ordonnée du sol2
    x_s3 = 1110; //Abscisse du sol3
    y_s3 = 340; //Ordonnée du sol3

    gravite = 0; //Initialisation de notre gravite à 0
    door_open = 0; //Initialisation de notre entier d'ouverture de porte à 0
    obstacle = 5; //Initialisation de notre nombre de vie à 5

    x_ma=100; //Abscisse de départ du personnage
    y_ma = 666; //Ordonnée de départ du personnage
    x_door = 1250; //Abscisse de la porte
    y_door = 685; //Ordonnée de la porte
    x_key = 345; //Abscisse de la clé
    y_key = 358; //Ordonnée de la clé

    x_p1 = 471; //Abscisse de notre plateforme1
    y_p1 = 543; //Ordonnée de notre plateforme1

    x_p2 = 674; //Abscisse de notre plateforme2
    y_p2 = 453; //Ordonnée de notre plateforme2

    x_p3 = 301; //Abscisse de notre plateforme3
    y_p3 = 386; //Ordonnée de notre plateforme3

    x_p4 = 95; //Abscisse de notre plateforme4
    y_p4 = 266; //Ordonnée de notre plateforme4

    x_p5 = 1287; //Abscisse de notre plateforme5
    y_p5 = 436; //Ordonnée de notre plateforme5

    x_p6 = 1390; //Abscisse de notre plateforme6
    y_p6 = 606; //Ordonnée de notre plateforme6

    x_p7 = 1253; //Abscisse de notre plateforme7
    y_p7 = 810; //Ordonnée de notre plateforme7

    //On affiche nos 3 images, le fond, la porte et la clé
    fond = new QGraphicsPixmapItem(QPixmap(":/img/fond")); //On cherche le chemin de notre image, ici vers le fichier ressource
    fond->setPos(0,0);
    this->addItem(fond);

    door = new QGraphicsPixmapItem(QPixmap(":/img/porte_f"));
    door->setPos(x_door,y_door);
    this->addItem(door);

    key = new QGraphicsPixmapItem(QPixmap(":/img/cle"));
    key->setPos(x_key,y_key);
    this->addItem(key);

    //Les trois différents sols de la map
    sol1 = new QGraphicsRectItem(0, 0, 906, 50); //On créer notre rectangle avec sa taille et sa position
    sol1->setPos(x_s1, y_s1); //On donne la position du sol
    sol1->setPen(QColor(Qt::transparent)); //On met le rectangle de couleur transparente pour que l'utilisateur ne le voit pas
    this->addItem(sol1); //On ajoute le sol à la scène

    sol2 = new QGraphicsRectItem(0, 0, 220, 550);
    sol2->setPos(x_s2, y_s2);
    sol2->setPen(QColor(Qt::transparent));
    this->addItem(sol2);

    sol3 = new QGraphicsRectItem(0, 0, 80, 85);
    sol3->setPos(x_s3, y_s3);
    sol3->setPen(QColor(Qt::transparent));
    this->addItem(sol3);



    //Les 4 obstacles à éviter pour ne pas perdre de vie (2 méduses et 2 lasers)
    obs1 = new QGraphicsRectItem(289, 214, 61, 68);
    obs1->setPen(QColor(Qt::transparent));
    this->addItem(obs1);

    obs2 = new QGraphicsRectItem(483, 116, 21, 423);
    obs2->setPen(QColor(Qt::transparent));
    this->addItem(obs2);

    obs3 = new QGraphicsRectItem(1365, 192, 79, 52);
    obs3->setPen(QColor(Qt::transparent));
    this->addItem(obs3);

    obs4 = new QGraphicsRectItem(1145, 537, 247, 23);
    obs4->setPen(QColor(Qt::transparent));
    this->addItem(obs4);



    //Les 7 platerforme où le personnage peut aller
    plat1 = new QGraphicsRectItem(x_p1, y_p1, 130, 42);
    plat1->setPen(QColor(Qt::transparent));
    this->addItem(plat1);

    plat2 = new QGraphicsRectItem(x_p2, y_p2, 130, 32);
    plat2->setPen(QColor(Qt::transparent));
    this->addItem(plat2);

    plat3 = new QGraphicsRectItem(x_p3, y_p3, 128, 38);
    plat3->setPen(QColor(Qt::transparent));
    this->addItem(plat3);

    plat4 = new QGraphicsRectItem(x_p4, y_p4, 132, 46);
    plat4->setPen(QColor(Qt::transparent));
    this->addItem(plat4);

    plat5 = new QGraphicsRectItem(x_p5, y_p5, 136, 38);
    plat5->setPen(QColor(Qt::transparent));
    this->addItem(plat5);

    plat6 = new QGraphicsRectItem(x_p6, y_p6, 136, 36);
    plat6->setPen(QColor(Qt::transparent));
    this->addItem(plat6);

    plat7 = new QGraphicsRectItem(x_p7, y_p7, 129, 45);
    plat7->setPen(QColor(Qt::transparent));
    this->addItem(plat7);

    //On affiche notre personnage
    pic = new QGraphicsPixmapItem(QPixmap(":/img/mario_d"));
    pic->setPos(x_ma,y_ma);
    this->addItem(pic);

    pig = new QGraphicsPixmapItem(QPixmap(":/img/mario_g"));
    this->addItem(pig);
    pig->setVisible(false);

    pihd = new QGraphicsPixmapItem(QPixmap(":/img/mario_hd"));
    this->addItem(pihd);
    pihd->setVisible(false);

    pihg = new QGraphicsPixmapItem(QPixmap(":/img/mario_hg"));
    this->addItem(pihg);
    pihg->setVisible(false);

    //On gere le timer
    timer = new QTimer(this); //On créer un nouveau timer
    timer->start(6); //Rafraichissement toute les 6 millisecondes
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    fin_jeu = new QGraphicsTextItem("'R' pour rejouer ou 'echap' pour quitter");
    fin_jeu->setPos(750,600);
    fin_jeu->setScale(3);
    //fin_jeu->setDefaultTextColor(Qt::green);
    fin_jeu->setDefaultTextColor(QColor(48, 193, 19, 255));
    this->addItem(this->fin_jeu);
    fin_jeu->setVisible(false);

    //texte pause
    text_pause  = new QGraphicsTextItem( "PAUSE - Espace pour continuer");
    text_pause->setScale(3);
    //text_pause->setDefaultTextColor(Qt::green);
    text_pause->setDefaultTextColor(QColor(48, 193, 19, 255));
    this->addItem(this->text_pause);
    text_pause->setVisible(false);

    plus_de_vie = new QGraphicsTextItem("'R' pour rejouer ou 'echap' pour quitter");
    plus_de_vie->setScale(3);
    //plus_de_vie->setDefaultTextColor(Qt::green);
    plus_de_vie->setDefaultTextColor(QColor(48, 193, 19, 255));
    this->addItem(this->plus_de_vie);
    plus_de_vie->setVisible(false);



    //On affiche les coeurs représentant les points de vie
    life1 = new QGraphicsPixmapItem(QPixmap(":/img/vie"));
    life1->setPos(20,20);
    this->addItem(life1);

    life2 = new QGraphicsPixmapItem(QPixmap(":/img/vie1"));
    life2->setPos(90,20);
    this->addItem(life2);

    life3 = new QGraphicsPixmapItem(QPixmap(":/img/vie2"));
    life3->setPos(160,20);
    this->addItem(life3);

    life4 = new QGraphicsPixmapItem(QPixmap(":/img/vie3"));
    life4->setPos(230,20);
    this->addItem(life4);

    life5 = new QGraphicsPixmapItem(QPixmap(":/img/vie4"));
    life5->setPos(300,20);
    this->addItem(life5);

    //On affiche l'image explicatif du jeu
    init = new QGraphicsPixmapItem(QPixmap(":/img/ecran"));
    init->setPos(0,500);
    this->addItem(init);

    QSound::play(":/son/hurry"); //Ajout du son de commencement du jeu


}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    //On réalise un switch pour passer à vrai les booléen de touche lorsqu'on appuie sur une des touches
    switch (event->key())
    {
            case Qt::Key_Left:
                keyLeft = true;
                break;
            case Qt::Key_Right:
                keyRight  = true;
                break;
            case Qt::Key_Up:
                  keyUp= true;
                break;
            case Qt::Key_R:
                  keyR = true;
                break;
            case Qt::Key_J:
                  keyJ = true;
                break;
            case Qt::Key_Escape:
                  keyEchap = true;
                break;
    }
    //On gère l'affiche du texte de pause (lorsque l'utilisateur appuie sur la barre d'espace)
    if(event->key() == Qt::Key_Space)
       {
           if(timer->isActive())
           {
               timer->stop(); //On stop le timer pour que le personnage ne bouge plus
               int x_tp = x_ma-220;
               int y_tp = y_ma-100;
               if(x_tp < 0) //Afin que le texte ne dépasse pas la scène
                    x_tp = x_ma;
               if(x_tp+500>1536)
                   x_tp = x_ma-600;

               text_pause->setPos(x_tp,y_tp);
               text_pause->setVisible(true);//On passe l'affichage du texte à vrai pour l'afficher
               enpause = 0;
           }
           else
           {
               timer->start(6); //On réactive le timer
               text_pause->setVisible(false); //On enlève le texte de pause
               enpause = 1;
           }
       }
}

void MyScene::keyReleaseEvent(QKeyEvent * event)
{
    //On réalise un nouveau switch pour mettre nos booléen à faux lorsqu'on relache une des 3 flèche de déplacement
    switch (event->key())
    {
        case Qt::Key_Left:
            keyLeft = false;
            break;
        case Qt::Key_Right:
            keyRight = false;
            break;
        case Qt::Key_Up:
            keyUp = false;
            break;
    }
}

void MyScene::CheckBord()
{
    if(pic->x() == Largeur-l_mario-5)//On met notre booléen de fléche droite à faux pour ne pas que notre personnage sorte de la scène
    {
        keyRight = false;
    }

    if(pic->x() == 3) //On met notre booléen de fléche gauche à faux pour ne pas que notre personnage sorte de la scène
    {
        keyLeft = false;
    }

    if(pic->y() == 80) //On met notre booléen de fléche haut à faux pour ne pas que notre personnage sorte de la scène
    {
        keyUp = false;
    }
    //Gestion des 3 sol pour le personnage se pose bien dessus et ne puisse à y accéder sur les côtés ou le dessous
    if(pic->collidesWithItem(sol1)) //Lorsqu'on arrive sur notre sol1, on met notre gravité à 1 pour que notre personnage de descende pas plus bas
    {
        gravite = 1;
    }

    if(pic->collidesWithItem(sol2))
    {
        if(y_ma+h_mario == y_s2)
        {
            gravite = 1;
            if(x_ma+l_mario <= x_s2)
            {
                gravite = 0;
            }

        }

        if((x_ma+l_mario)==x_s2)
        {
            keyRight = false;
            if(y_ma+h_mario<=y_s2)
                keyRight =! false;
        }
        if(x_ma==x_s2+220)
        {
            keyLeft = false;


        }
    }

    if(pic->collidesWithItem(sol3))
    {
        if(y_ma+h_mario == y_s3)
        {
            gravite = 1;
            if(x_ma >= x_s3+79)
                gravite = 0;

        }
        if((x_ma)==x_s3+79)
        {
            keyLeft = false;
            if(y_ma+h_mario<=y_s3 || y_ma>= y_s3+84)
              keyLeft =! false;
        }

        if((y_ma)==y_s3+85)
        {
            keyUp = false;
        }
    }

    //On refait pareil pour les 7 différentes plateformes
    if(pic->collidesWithItem(plat1))
    {
        if(y_ma+h_mario == y_p1)
        {
            gravite = 1;
            if(x_ma+l_mario <= x_p1 || x_ma >= x_p1+129 )
                gravite=0;
        }

        if(x_ma+l_mario == x_p1)
        {
            keyRight = false;
            if(y_ma+h_mario<=y_p1 || y_ma >= y_p1+42)
                keyRight =! false;
        }

        if(x_ma == x_p1+130)
        {
            keyLeft = false;
            if(y_ma+h_mario<=y_p1 || y_ma>= y_p1+42)
                   keyLeft =! false;
        }

        if(y_ma == y_p1+42)
        {
            keyUp = false;
        }
    }

    if(pic->collidesWithItem(plat2))
    {
        if(y_ma+h_mario == y_p2)
        {
            gravite = 1;
            if(x_ma+l_mario <= x_p2 || x_ma >= x_p2+129 )
                gravite=0;
        }

        if(x_ma+l_mario == x_p2)
        {
            keyRight = false;
            if(y_ma+h_mario<=y_p2 || y_ma >= y_p2+32)
                keyRight =! false;
        }

        if(x_ma == x_p2+130)
        {
            keyLeft = false;
            if(y_ma+h_mario<=y_p2 || y_ma>= y_p2+32)
                   keyLeft =! false;
        }

        if(y_ma == y_p2+32)
        {
            keyUp = false;
        }
    }

    if(pic->collidesWithItem(plat3))
    {
        if(y_ma+h_mario == y_p3)
        {
            gravite = 1;
            if(x_ma+l_mario <= x_p3 || x_ma >= x_p3+127 )
                gravite=0;
        }

        if(x_ma+l_mario == x_p3)
        {
            keyRight = false;
            if(y_ma+h_mario<=y_p3 || y_ma >= y_p3+38)
                keyRight =! false;
        }

        if(x_ma == x_p3+128)
        {
            keyLeft = false;
            if(y_ma+h_mario<=y_p3 || y_ma>= y_p3+38)
                   keyLeft =! false;
        }

        if(y_ma == y_p3+38)
        {
            keyUp = false;
        }
    }

    if(pic->collidesWithItem(plat4))
    {
        if(y_ma+h_mario == y_p4)
        {
            gravite = 1;
            if(x_ma+l_mario <= x_p4 || x_ma >= x_p4+131)
                gravite=0;
        }

        if(x_ma+l_mario == x_p4)
        {
            keyRight = false;
            if(y_ma+h_mario<=y_p4 || y_ma >= y_p4+46)
                keyRight =! false;
        }

        if(x_ma == x_p4+132)
        {
            keyLeft = false;
            if(y_ma+h_mario<=y_p4 || y_ma>= y_p4+46)
                   keyLeft =! false;
        }

        if(y_ma == y_p4+46)
        {
            keyUp = false;
        }
    }

    if(pic->collidesWithItem(plat5))
    {
        if(y_ma+h_mario == y_p5)
        {
            gravite = 1;
            if(x_ma+l_mario <= x_p5 || x_ma >= x_p5+135 )
                gravite=0;
        }

        if(x_ma+l_mario == x_p5)
        {
            keyRight = false;
            if(y_ma+h_mario<=y_p5 || y_ma >= y_p5+38)
                keyRight =! false;
        }

        if(x_ma == x_p5+136)
        {
            keyLeft = false;
            if(y_ma+h_mario<=y_p5 || y_ma>= y_p5+38)
                   keyLeft =! false;
        }

        if(y_ma == y_p5+38)
        {
            keyUp = false;
        }
    }

    if(pic->collidesWithItem(plat6))
    {
        if(y_ma+h_mario == y_p6)
        {
            gravite = 1;
            if(x_ma+l_mario <= x_p6 || x_ma >= x_p6+135 )
                gravite=0;
        }

        if(x_ma+l_mario == x_p6)
        {
            keyRight = false;
            if(y_ma+h_mario<=y_p6 || y_ma >= y_p6+36)
                keyRight =! false;
        }

        if(x_ma == x_p6+136)
        {
            keyLeft = false;
            if(y_ma+h_mario<=y_p6 || y_ma>= y_p6+36)
                   keyLeft =! false;
        }

        if(y_ma == y_p6+36)
        {
            keyUp = false;
        }
    }

    if(pic->collidesWithItem(plat7))
    {
        if(y_ma+h_mario == y_p7)
        {
            gravite = 1;
            if(x_ma+l_mario <= x_p7 || x_ma >= x_p7+128 )
                gravite=0;
        }

        if(x_ma+l_mario == x_p7)
        {
            keyRight = false;
            if(y_ma+h_mario<=y_p7 || y_ma >= y_p7+45)
                keyRight =! false;
        }

        if(x_ma == x_p7+129)
        {
            keyLeft = false;
            if(y_ma+h_mario<=y_p7 || y_ma>= y_p7+45)
                   keyLeft =! false;
        }

        if(y_ma == y_p7+45)
        {
            keyUp = false;
        }
    }

}

void MyScene::deplacement() //On gère le déplacement à droite ou à gauche suivant la flèche appuyée de 1px par 1 px
{
    if(keyLeft==true)
    {
        x_ma-=1;
        pic->setVisible(false);
        pihg->setVisible(false);
        pihd->setVisible(false);
        pig->setPos(x_ma,y_ma);
        pig->setVisible(true);
    }

    if(keyRight==true)
    {
        x_ma+=1;
        pig->setVisible(false);
        pihg->setVisible(false);
        pihd->setVisible(false);
        pic->setPos(x_ma,y_ma);
        pic->setVisible(true);
    }
}

void MyScene::saut() //On gère le déplacement en l'air de notre personnage
{

    if(keyUp==true)
    {
        gravite = 0;
        if(y_ma>0)
        {
            y_ma = y_ma-1;
            pig->setVisible(false);
            pic->setVisible(false);
            pihd->setPos(x_ma, y_ma);
            pihd->setVisible(true);
            if(keyLeft == true)
            {
                pihd->setVisible(false);
                pihg->setPos(x_ma, y_ma);
                pihg->setVisible(true);
            }
        }
     }
    else
    {
        if(y_ma<Hauteur-h_mario && gravite == 0)
        {
            y_ma = y_ma+1;
            pihd->setVisible(false);
            pihg->setVisible(false);
            pic->setPos(x_ma,y_ma);
            pic->setVisible(true);
            if(keyLeft == true)
            {
                pic->setVisible(false);
                pig->setPos(x_ma,y_ma);
                pig->setVisible(true);
            }
        }
     }
}

void MyScene::arrivee() //on gère l'arrivée du personnage à la porte lorsqu'il a la clé pour pouvoir recommencer ou quitter le jeu
{
    if(pic->collidesWithItem(door) && door_open==1)
    {
        if(y_ma+h_mario == y_door+100)
        {
            fin_jeu->setVisible(true);
            pic->setVisible(false);
            QSound::play(":/son/fin");
        }
    }
}

void MyScene::cle() //On change de porte (porte fermée à ouverte) lorsque l'utilisateur trouve la clé
{
    if(pic->collidesWithItem(key))
    {
        if(touchKey == false)
            QSound::play(":/son/cle");
        touchKey = true;
        key->setVisible(false);
        door = new QGraphicsPixmapItem(QPixmap(":/img/porte_o"));
        door->setPos(x_door,y_door);
        this->addItem(door);
        door_open = 1;
    }
}

void MyScene::vie() //On gère la vie qui est décrementée à chaque collision avec un des lasers ou une des méduses
{
    if(pic->collidesWithItem(obs1) || pic->collidesWithItem(obs2) || pic->collidesWithItem(obs3) || pic->collidesWithItem(obs4))
    {
        if(DejaTouche == false)
        {
            obstacle --;
            QSound::play(":/son/comm");
        }
        DejaTouche = true;
    }
    else
        DejaTouche = false;
    if(obstacle == 5)
    {
        life1->setVisible(true);
        life2->setVisible(true);
        life3->setVisible(true);
        life4->setVisible(true);
        life5->setVisible(true);
    }

    if(obstacle == 4)
    {
        life5->setVisible(false); //On passe le 5ème coeur à false pour ne plus le voir car on a perdu une vie
    }

    if(obstacle == 3)
    {
        life4->setVisible(false);
    }

    if(obstacle == 2)
    {
        life3->setVisible(false);
    }

    if(obstacle == 1)
    {
        life2->setVisible(false);
    }

    if(obstacle == 0)
    {

        life1->setVisible(false);
        int x_pdv = x_ma-220;
        int y_pdv = y_ma-100;
        if(x_pdv < 0) //Afin que le texte ne dépasse pas la scène
             x_pdv = x_ma;
        if(x_pdv+500>1536)
            x_pdv = x_ma-600;

        plus_de_vie->setPos(x_pdv,y_pdv);
        plus_de_vie->setVisible(true);
        keyLeft = false;
        keyRight = false;
        keyUp = false;
        gravite=1;

        //QApplication::quit(); //On quitte l'application si le mario n'a plus de vie
    }
}

void MyScene::touche()
{
    if(keyEchap == true) //Lorsque l'utilisateur appuie sur la touche 'echap', cela quitte le jeu
        QApplication::quit();

    if(keyR == true) //Lorsque l'utilisateur appuie sur la touche 'R', on recommence en réinitialisent les différents paramètres
    {
       keyLeft = false;
       keyRight = false;
       keyR = false;
       keyEchap = false;
       touchKey == false; //Marque un problème comme quoi ce booléen n'est pas utilisé mais le son de la clé n'est pas là si on recommence le jeu sinon
       enpause = 1;
       x_ma=100;
       y_ma = 666;
       pic->setPos(x_ma,y_ma);
       key->setVisible(true);
       door = new QGraphicsPixmapItem(QPixmap(":/img/porte_f"));
       door->setPos(x_door,y_door);
       this->addItem(door);
       door_open = 0;
       obstacle = 5;
       timer->start(6);
       pic->setVisible(true);
       fin_jeu->setVisible(false);
       plus_de_vie->setVisible(false);
    }

}

void MyScene::comm() //Lorsque l'utilisateur presse la touche 'J' pour commencer à jouer au jeu
{
    if(keyJ == true)
        init->setVisible(false); //L'image d'explication disparait
}


void MyScene::update()
{

    CheckBord();
    if(keyJ == true) //Si l'utilisateur à décider de commencer le jeu, le personnage peut se déplacer
    {
        deplacement();
        saut();
    }
    arrivee();
    cle();
    pic->setPos(x_ma, y_ma);
    text_pause->scale();
    vie();
    touche();
    comm();

    //pour le scrolling du mario
    QList < QGraphicsView* > ListeView = this->views();
    ListeView.at(0)->centerOn(pic); //On centre la vue sur notre personnage
}
