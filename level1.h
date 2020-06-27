#ifndef LEVEL1_H
#define LEVEL1_H

#include <QMainWindow>
#include "supwindow.h"
#include"button.h"
#include"tower.h"
#include"towerplace.h"
#include"basic_enemy.h"
#include"changepoint.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QList>
#include<home.h>
#include"bullets.h"

class Level1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Level1(QWidget*parent=nullptr);
    Level1(QWidget *parent,int level,QPoint homeplace);
    void paintEvent(QPaintEvent*Event);
void drawvolume(QPainter*painter);
    void Back();
    void loadTowerplace1();
    void loadTowerplace2();
    void mousePressEvent(QMouseEvent *event);
    bool canBuy(int cost);
    void loadChangepoint1();
    void loadChangepoint2();
void removeBullet(Bullets*bullet);
    void UpdateAll();
    void receivedamage();
    void removeenemy(Basic_enemy*enemy);
    void removetower(Tower*tower);
    void loadbullet(Bullets*bullet);
void gameover();
    bool loadwave();

    QList<Basic_enemy*>_basicenemy;
    QList<Bullets*>_bullet;
    QList<Towerplace> _towerplace;

private:
    int _level;
    Home*home;

    QList<Tower*> _tower;
    QList<Changepoint*>_changepoint;

    int _money;
    int _waves;
    bool _win;
    bool _end;


signals:
    void backtosup();

};

#endif // LEVEL1_H
