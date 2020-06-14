#include "basic_enemy.h"
#include<QVector2D>
#include<QPainter>
#include"Somefunction.h"

Basic_enemy::Basic_enemy(Changepoint *startPlace, QString pic) : QObject(0)
  ,_targetPlace(*startPlace->getNext()),_currentPlace(startPlace->getPlace()),_pic(pic)
{

    _active=false;
    _speed=1.0;
    _currentHP=40;
    _HP=40;
}
void Basic_enemy::move()
{   if(!_active)
    {
        return;
    }
    if(collision(_currentPlace,1,_targetPlace.getPlace(),1))
    {
        if(_targetPlace.getNext())
         {  _currentPlace=_targetPlace.getPlace();
            _targetPlace=Changepoint(*_targetPlace.getNext());
        }
        else
        {
            emit damage();
            return;
        }

    }

    QPoint targetpoint=_targetPlace.getPlace();
    double currentspeed=_speed;
    QVector2D direction(targetpoint-_currentPlace);
    direction.normalize();
    _currentPlace=_currentPlace+direction.toPoint() *currentspeed;

}

void Basic_enemy::action()
{
    _active=true;
}











void Basic_enemy::draw(QPainter *painter)
{
    painter->drawPixmap(_currentPlace,_pic);
    painter->save();
    QPoint Healthbarpoint=_currentPlace+QPoint(10,5);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect HealthbarBack(Healthbarpoint,QSize(20,2));
    painter->drawRect(HealthbarBack);
    painter->setBrush(Qt::green);
    QRect Healthbar(Healthbarpoint,QSize((double)_currentHP/_HP*20,2));
    painter->drawRect(Healthbar);
    painter->restore();
}
