#ifndef BASIC_ENEMY_H
#define BASIC_ENEMY_H

#include <QObject>
#include <QPoint>
#include<QPixmap>
#include<QPainter>
#include"changepoint.h"
#include<QTimer>

class Tower;
class Level1;
class Basic_enemy : public QObject
{
    Q_OBJECT

public:

    virtual~Basic_enemy();
    virtual void setvolume(double speed,int HP,int reward)=0;

    Basic_enemy(Changepoint *startPlace, QString pic,Level1*game);
    void move();
    void setspeed(double speed);

    void setHP(int HP);
    void draw(QPainter*painter);
    void receivedamage(int damage);
    QPoint getcurrentplace()const;
    void getfired(Tower*tower);
    void getoutofrange(Tower*tower);
    QList<Tower*>_beingfiredtower;
    void dead();
    void gotlostsight(Tower*tower);
    Changepoint _targetPlace;
    QPoint _currentPlace;
    bool _getfired;
    void getfrozen();
int _reward;
public slots:
  void action();
  void recoverfrozen();
private:

    QPixmap _pic;
    Level1*_game;
    bool _active;
    double _speed;
    int _HP;
    int _currentHP;
    bool _frozen;




};

#endif // BASIC_ENEMY_H
