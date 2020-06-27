#ifndef BULLECT_H
#define BULLECT_H

#include <QObject>
#include<QPainter>
#include<QPoint>

class Level1;
class Basic_enemy;
class Bullets: QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint _currentplace READ getcurrentplace WRITE setcurrentplace)
public:
    Bullets(QPoint startplace,QPoint targetplace,int power,Basic_enemy*aimenemy,QString pic,Level1 *game);
    void draw(QPainter*painter)const;
    void move();
    void setcurrentplace(QPoint place);
    QPoint getcurrentplace()const;
    QPoint _startplace;
    QPoint _currentplace;
     QPoint _targetplace;

public slots:
    void hit();//与动画进程结束关联

private:
    Level1* _game;

    QPixmap _pic;
    Basic_enemy* _aimenemy;
    int _power;
    static const QSize _size;
};

#endif // BULLECT_H
