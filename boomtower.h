#ifndef BOOMTOWER_H
#define BOOMTOWER_H
#include"tower.h"
#include<qtimer.h>
class BoomTower : public Tower
{
    Q_OBJECT
public:
    BoomTower(QPoint place, QString pic,Level1*game);
    void setvolume(int range, int damage, int rate) override;
    void levelup() override;
public slots:
    void boom();

};

#endif // BOOMTOWER_H
