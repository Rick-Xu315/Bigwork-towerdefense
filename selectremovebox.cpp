#include "selectremovebox.h"
#include <QWidget>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include"button.h"
#include"towerplace.h"
#include"level1.h"
Selectremovebox::Selectremovebox(QPoint place,Towerplace*parent,Level1*game)
    : _parentplace(parent),_place(place),_game(game)
{
    setparent(_game);
    this->hide();
        box1->move(_place.x()+60,_place.y());
         box2->move(_place.x(),_place.y()-60);
          box3->move(_place.x()-60,_place.y());
}

void Selectremovebox::hide()
{

    box1->hide();
    box2->hide();
    box3->hide();


}

void Selectremovebox::display()
{
    box1->show();
    box2->show();
    box3->show();;

}


void Selectremovebox::setparent(Level1 *game)
{
    box1->setParent(game);
     box2->setParent(game);
      box3->setParent(game);

}



