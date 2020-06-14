#include "home.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QMediaPlayer>
#include<QUrl>

Home::Home(QPoint place,QString pic):_pic(pic),_place(place)
{
    _HP=5;
    _currentHP=5;

}
const QSize Home::_size(60,80);
void Home::draw(QPainter *painter)
{
    painter->drawPixmap(_place,_pic);
    painter->save();
    QPoint Healthbarpoint=_place+QPoint(25,0);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect HealthbarBack(Healthbarpoint,QSize(40,5));
    painter->drawRect(HealthbarBack);
    painter->setBrush(Qt::green);
    QRect Healthbar(Healthbarpoint,QSize((double)_currentHP/_HP*40,5));
    painter->drawRect(Healthbar);
    painter->restore();
}
void Home::getdamage()
{
    _currentHP-=1;
}
int Home::getHP()
{
    return _currentHP;
}
