#ifndef COMMONENEMY_H
#define COMMONENEMY_H

#include <QObject>
#include <QPoint>
#include<QPixmap>
#include<QPainter>
#include"changepoint.h"

#include"basic_enemy.h"

class Level1;

class CommonEnemy:public Basic_enemy
{Q_OBJECT
public:
    ~CommonEnemy();
    CommonEnemy(Changepoint *startPlace, QString pic,Level1*game);
    void setvolume(double speed, int HP,int reward) ;

};

#endif // COMMONENEMY_H
