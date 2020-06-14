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

class Towerplace
{

public:
    explicit Towerplace(QObject *parent = nullptr);
    Towerplace(QPoint place,const QPixmap &pic=QPixmap(":/0place.png"));
    void fill(bool filled=true);
    bool filled() const;
    const QPoint center() const;
    bool contain(const QPoint&place)const;
    void draw(QPainter*painter);
    QPoint getplace();

private:
    QPoint _place;
    bool _filled;
    QPixmap _pic;
    static const QSize _size;



};

#endif // TOWERPLACE_H
