#include "tower.h"
#include "towerplace.h"
#include"button.h"
#include"supwindow.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QMediaPlayer>
#include<QUrl>

Tower::Tower(QPoint place, QString pic) : QObject(0),_place(place),_pic(pic)
{
    range=150;
    damage=20;
}
const QSize Tower::_size(69,120);
void Tower::draw(QPainter *painter){
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(_place,range,range);
    static const QPoint just(-34,-90);
    painter->translate(_place);
    painter->drawPixmap(just,_pic);
    painter->restore();

}
