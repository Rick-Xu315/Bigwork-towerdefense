#ifndef TOWERPLACE_H
#define TOWERPLACE_H

#include <QObject>
#include <QWidget>
#include"button.h"
#include"supwindow.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QMediaPlayer>
#include<QUrl>
#include"selectfuncbox.h"
#include"selectremovebox.h"
class Tower;
class Level1;
class Towerplace
{

public:
    explicit Towerplace(QObject *parent = nullptr);
    Towerplace(QPoint place,Level1*game, const QPixmap &pic=QPixmap(":/0place.png"));
    void fill(bool filled=true);
    bool filled() const;
    const QPoint center() const;
    bool contain(const QPoint&place)const;
    void draw(QPainter*painter);
    QPoint getplace();
    void setTower(Tower*tower);
    Tower* _tower;
    Selectfuncbox*_funcbox;
    Selectremovebox*_removebox;



private:
    Level1* _game;
    QPoint _place;
    bool _filled;
    QPixmap _pic;
    static const QSize _size;




};

#endif // TOWERPLACE_H
