#ifndef COMMONTOWER_H
#define COMMONTOWER_H

#include<tower.h>
class CommonTower:public Tower
{
    Q_OBJECT
public:
    CommonTower(QPoint place, QString pic,Level1*game);
    void setvolume(int range, int damage, int rate) override;
    void levelup() override;
};

#endif // COMMONTOWER_H
