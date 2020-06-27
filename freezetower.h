#ifndef FREEZETOWER_H
#define FREEZETOWER_H

#include"tower.h"
#include<QList>
class Basic_enemy;
class Freezetower : public Tower
{
    Q_OBJECT
public:
    Freezetower(QPoint place, QString pic,Level1*game);
    void setvolume(int range, int damage, int rate) override;
    void levelup() override;
    void check();
    void freeze(Basic_enemy*enemy);
    QList<Basic_enemy*>_freezeaim;
    Level1*_game2;
public slots:
    void sendfreeze();
private:
    QTimer*freezetimer=new QTimer(this);

};

#endif // FREEZETOWER_H
