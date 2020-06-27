#include "boomerenemy.h"
#include"towerplace.h"

#include"Somefunction.h"
#include"qdebug.h"
Boomerenemy::Boomerenemy(Changepoint *startPlace, QString pic,Level1*game):Basic_enemy(startPlace,pic,game)
{

setvolume(2,80,800);
}
void Boomerenemy ::setvolume(double speed, int HP,int reward)
{
    setspeed(speed);
    setHP(HP);
    _reward=reward;
}

    Boomerenemy::~Boomerenemy(){
        qDebug()<<"boomer"<<endl;

    }
