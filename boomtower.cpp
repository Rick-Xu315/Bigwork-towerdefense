#include "boomtower.h"
#include"Somefunction.h"
#include"tower.h"
#include<qtimer.h>
#include<level1.h>
#include<QSound>
BoomTower:: BoomTower(QPoint place, QString pic,Level1*game):Tower(place,pic,game)
{
    _shoot=false;
    setvolume(150,0,200);
    QTimer::singleShot(200,this,SLOT(boom()));
}

 void BoomTower:: setvolume(int range, int damage, int rate)
 {
     _range=range;
     _damage=damage;
     _rate=rate;
     }
 void  BoomTower::levelup()
 {


 }
void BoomTower:: boom()
{

    foreach(Basic_enemy*enemy,_game->_basicenemy)
    {
        if(collision(_place,_range,enemy->_currentPlace,1))
        {
            _game->removeenemy(enemy);
        }}

    _game->removetower(this);
}

