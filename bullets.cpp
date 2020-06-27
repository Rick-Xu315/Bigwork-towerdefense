#include "bullets.h"
#include<basic_enemy.h>
#include<QPainter>
#include<QPointer>
#include<QPropertyAnimation>
#include"level1.h"
const QSize Bullets::_size(8,8);
Bullets::Bullets(QPoint startplace,QPoint targetplace,int power,Basic_enemy*aimenemy,QString pic,Level1*game)
    :_game(game),_startplace(startplace),_pic(pic),_targetplace(targetplace),_aimenemy(aimenemy),_power(power),_currentplace(startplace)
{

}
void Bullets::setcurrentplace(QPoint place)
{
    _currentplace=place;
}
QPoint Bullets::getcurrentplace()const
{
    return _currentplace;
}


void Bullets::draw(QPainter *painter)const
{
    painter->drawPixmap(_currentplace,_pic);
}


void Bullets::move()
{
   static const int continuetime=100;//在这里更改持续时间
    QPropertyAnimation *process=new QPropertyAnimation(this,"_currentplace");
    process->setDuration(continuetime);
    process->setStartValue(_startplace);
    process->setEndValue(_targetplace);
    connect(process,SIGNAL(finished()), this,SLOT(hit()));
    process->start();

}
void Bullets::hit()
{
    if(_game->_basicenemy.indexOf(_aimenemy)!=-1)
    {_aimenemy->receivedamage(_power);}
    _game->removeBullet(this);
}
