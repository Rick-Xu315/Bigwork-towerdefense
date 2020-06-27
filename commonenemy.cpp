#include "commonenemy.h"
#include"qdebug.h"
CommonEnemy::CommonEnemy(Changepoint *startPlace, QString pic,Level1*game):Basic_enemy(startPlace,pic,game)
{
setvolume(0.6,40,200);
}
void CommonEnemy::setvolume(double speed, int HP,int reward)
{
    setspeed(speed);
    setHP(HP);
    _reward=reward;
}
CommonEnemy::~CommonEnemy()
{
qDebug()<<"common"<<endl;
}
