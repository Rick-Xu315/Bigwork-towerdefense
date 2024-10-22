#include "towerplace.h"
#include"button.h"
#include"supwindow.h"
#include"selectfuncbox.h"
#include"selectremovebox.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QMediaPlayer>
#include<QUrl>
#include"level1.h"
Towerplace::Towerplace(QPoint place,Level1*game, const QPixmap &pic)
    : _place(place),_tower(NULL),_pic(pic),_filled(false),_funcbox(new Selectfuncbox(place,this,game)),_removebox(new Selectremovebox(place,this,game))
{


}
const QSize Towerplace::_size(63,63);
const QPoint Towerplace::center() const
{
    QPoint just(_size.width()/2,_size.height()/2);
    return _place+just;
}
bool Towerplace::contain(const QPoint &place) const
{
    bool Xin=_place.x()<place.x()&&place.x()<(_place.x()+_size.width());
    bool Yin=_place.y()<place.y()&&place.y()<(_place.y()+_size.height());
    return Xin&&Yin;
}
bool Towerplace::filled() const
{
    return _filled;
}
void Towerplace::fill(bool filled)
{
    _filled=filled;
}
void Towerplace::draw(QPainter *painter)
{
    painter->drawPixmap(_place.x(),_place.y(),_pic);
}

QPoint Towerplace::getplace()
{
    return _place;
}

void Towerplace::setTower(Tower *tower)
{
    _tower=tower;
}






