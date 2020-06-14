#ifndef BASIC_ENEMY_H
#define BASIC_ENEMY_H

#include <QObject>
#include <QPoint>
#include<QPixmap>
#include<QPainter>
#include"changepoint.h"



class Basic_enemy : public QObject
{
    Q_OBJECT

public:
    Basic_enemy():_targetPlace(QPoint(0,0)){};
    Basic_enemy(Changepoint *startPlace, QString pic);
    void move();
    void draw(QPainter*painter);


public slots:
    void action();
private:

    Changepoint _targetPlace;
    QPoint _currentPlace;
    QPixmap _pic;


    bool _active;
    double _speed;
    int _HP;
    int _currentHP;


signals:
    void damage();

};

#endif // BASIC_ENEMY_H
