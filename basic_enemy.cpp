#include "basic_enemy.h"
#include"tower.h"
#include<QVector2D>
#include<QPainter>
#include"Somefunction.h"
#include"level1.h"
#include<QPointer>
#include<QDebug>
#include<QSound>
Basic_enemy::Basic_enemy(Changepoint *startPlace, QString pic,Level1*game) : QObject(0)
  ,_game(game),_targetPlace(*startPlace->getNext()),_currentPlace(startPlace->getPlace()),_pic(pic),_frozen(false)
{   _reward=200;
    _getfired=false;
    _active=false;
    _speed=0.5;
    _currentHP=40;
    _HP=40;
}
Basic_enemy::~Basic_enemy()
{qDebug()<<"base "<<endl;
    _beingfiredtower.clear();
    _game=NULL;

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

            _game->receivedamage();
            if(_game->_basicenemy.indexOf(this)!=-1)
            _game->removeenemy(this);
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



QPoint Basic_enemy::getcurrentplace()const
{
    return _currentPlace;
}


void Basic_enemy::getfired(Tower *tower)
{

_getfired=true;
    _beingfiredtower.push_back(tower);


}

void Basic_enemy::getoutofrange(Tower *tower)
{
    _beingfiredtower.removeOne(tower);
}


void Basic_enemy::receivedamage(int damage)
{
   _currentHP-=damage;
   if(_currentHP<=0)
   {
       dead();
   }
}

void Basic_enemy::dead()
{
   if(_currentHP<=0){ if(_beingfiredtower.empty())
        return;

    foreach(Tower*tower,_beingfiredtower)
    {
        Q_ASSERT(tower);
        if(tower)
        tower->targetkilled();
    }
    _game->removeenemy(this);}

}



void Basic_enemy::setHP(int HP)
{
    _HP=HP;
    _currentHP=HP;
}


void Basic_enemy::setspeed(double speed)
{
    _speed=speed;
}

void Basic_enemy::getfrozen()
{
    if(!_frozen)
    {

        _frozen=true;
    _speed-=0.6;
    QTimer::singleShot(500,this,SLOT(recoverfrozen()));}

}
void Basic_enemy::recoverfrozen()
{
    _frozen=false;
    _speed+=0.6;
}
