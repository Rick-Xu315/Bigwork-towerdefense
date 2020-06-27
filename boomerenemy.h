#ifndef BOOMERENEMY_H
#define BOOMERENEMY_H

#include <QObject>
#include <QPoint>
#include<QPixmap>
#include<QPainter>
#include"changepoint.h"

#include"basic_enemy.h"
#include<QList>


class Boomerenemy:public Basic_enemy
{
    Q_OBJECT
public:
    ~Boomerenemy();
    Boomerenemy(Changepoint *startPlace, QString pic,Level1*game);
    void setvolume(double speed, int HP,int reward) ;


};

#endif // BOOMERENEMY_H
