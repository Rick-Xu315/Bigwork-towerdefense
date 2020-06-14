#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include "towerplace.h"
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


class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint place, QString pic);
    void draw(QPainter*painter);
private:
    QPoint _place;
    QPixmap _pic;
    int range;
    int damage;
    int rate;
    static const QSize _size;

signals:

};

#endif // TOWER_H
