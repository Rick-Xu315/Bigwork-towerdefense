#include "selectfuncbox.h"
#include <QWidget>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include"button.h"
#include"towerplace.h"
#include"level1.h"

Selectfuncbox::Selectfuncbox(QPoint place,Towerplace*parent,Level1*game)
    : _parentplace(parent),_place(place),_game(game)
{

setparent(_game);
this->hide();
    box1->move(_place.x()+60,_place.y());
     box2->move(_place.x(),_place.y()-60);
      box3->move(_place.x()-60,_place.y());
       box4->move(_place.x(),_place.y()+60);



}

void Selectfuncbox::hide()
{

    box1->hide();
    box2->hide();
    box3->hide();
    box4->hide();

}

void Selectfuncbox::display()
{
    box1->show();
    box2->show();
    box3->show();;
    box4->show();
}

void Selectfuncbox::build1()
{

}
void Selectfuncbox::build2()
{

}
void Selectfuncbox::build3()
{

}
void Selectfuncbox::setparent(Level1 *game)
{
    box1->setParent(game);
     box2->setParent(game);
      box3->setParent(game);
       box4->setParent(game);
}



