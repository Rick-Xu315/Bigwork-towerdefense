#ifndef ELITEENEMY_H
#define ELITEENEMY_H

#include <QObject>
#include <QPoint>
#include<QPixmap>
#include<QPainter>
#include"changepoint.h"
#include<QTimer>
#include"basic_enemy.h"

class Level1;
class Eliteenemy:public Basic_enemy
{

Q_OBJECT
public:
    ~Eliteenemy();
    Eliteenemy(Changepoint *startPlace, QString pic,Level1*game);
    void setvolume(double speed, int HP,int reward) ;
    void getrage();
public slots:
    void recover();
private:
    bool _rage;


};

#endif // ELITEENEMY_H
