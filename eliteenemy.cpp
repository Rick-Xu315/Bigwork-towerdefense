#include "eliteenemy.h"
#include"qdebug.h"
#include<QMediaPlayer>
Eliteenemy::Eliteenemy(Changepoint *startPlace, QString pic,Level1*game):Basic_enemy(startPlace,pic,game)
{
setvolume(0.6,60,500);
_rage=false;

}
void Eliteenemy::setvolume(double speed, int HP,int reward)
{
    setHP(HP);
    setspeed(speed);
    _reward=reward;

}
void Eliteenemy::recover()
{
    _rage=false;
    _getfired=false;
    setspeed(0.6);

}

void Eliteenemy::getrage()
{
    if(_getfired&&!_rage)
       {

        _rage=true;
        setspeed(2);
        QTimer::singleShot(500,this,SLOT(recover()));

}}
Eliteenemy::~Eliteenemy()
{
    qDebug()<<"elite"<<endl;
}
