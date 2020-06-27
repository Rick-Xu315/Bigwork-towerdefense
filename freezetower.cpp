#include "freezetower.h"
#include"tower.h"
#include<Somefunction.h>
#include<level1.h>
Freezetower::Freezetower(QPoint place, QString pic,Level1*game):Tower(place,pic,game),_game2(game)
{
    _shoot=false;
setvolume(150,10,1000);
connect(freezetimer,SIGNAL(timeout()),this,SLOT(sendfreeze()));
freezetimer->start(_rate);
}

void Freezetower::setvolume(int range, int damage, int rate)
{
    _rate=rate;
    _damage=damage;
    _range=range;
}
void Freezetower::levelup()
{
    setvolume(200,10,80);
}

void Freezetower::sendfreeze(){
   foreach(Basic_enemy*enemy,_game->_basicenemy)
   {
       if(collision(_place,_range,enemy->_currentPlace,1))
       {
           enemy->getfrozen();
           enemy->receivedamage(5);
       }
   }

}
