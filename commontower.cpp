#include "commontower.h"

CommonTower::CommonTower(QPoint place, QString pic,Level1*game):Tower(place,pic,game)
{
setvolume(150,10,500);
}
void CommonTower::setvolume(int range, int damage, int rate)
{
    _rate=rate;
    _damage=damage;
    _range=range;
}
void CommonTower::levelup()
{
    setvolume(150,20,300);
}
