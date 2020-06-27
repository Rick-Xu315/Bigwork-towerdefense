#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include "towerplace.h"
#include"button.h"

#include"supwindow.h"
#include<QTimer>
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QMediaPlayer>
#include<QUrl>

class Level1;
class Basic_enemy;
class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint place, QString pic,Level1*game);
    virtual ~Tower();
    virtual void setvolume(int range,int damage,int rate)=0;
    virtual void levelup()=0;
    void draw(QPainter*painter);
    void checkenemy();
   void targetkilled();
   void chooseEnemy(Basic_enemy*enemy);
   void fireenemy();
    void outofrange();
    void removetower();
  void setrange(int range);
  void setrate(int rate);
  void setdamage(int damage);
  void setpic(QString newpic);
  bool _shoot;
 Level1*_game;
 QPoint _place;
 int _range;
 int _damage;
 int _rate;
 Basic_enemy*_targetenemy;
public slots:
    void shootweapon();


private:



    QPixmap _pic;

    static const QSize _size;

    QTimer*_ratetimer=new QTimer(this);


signals:

};

#endif // TOWER_H
