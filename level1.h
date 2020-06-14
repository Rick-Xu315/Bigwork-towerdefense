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

class Level1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Level1(QWidget*parent=nullptr);
    void paintEvent(QPaintEvent*Event);

    void Back();
    void loadTowerplace();
    void mousePressEvent(QMouseEvent *event);
    bool canBuy();
    void loadChangepoint();

    void UpdateAll();
    void receivedamage();
    void removeenemy(Basic_enemy*enemy);
    void Updateenemylist();
    bool loadwave();

private:
    Home*home=new Home(QPoint(768,250),":/home.png");
    QList<Towerplace> _towerplace;
    QList<Tower*> _tower;
    QList<Changepoint*>_changepoint;
    QList<Basic_enemy*>_basicenemy;
    int _waves;
    bool _win;



signals:

};

#endif // LEVEL1_H
