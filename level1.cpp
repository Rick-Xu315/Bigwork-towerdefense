#include "level1.h"
#include "supwindow.h"
#include"button.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>

Level1::Level1(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(960,540);
}
void Level1::paintEvent(QPaintEvent*Event)
{

    QPainter painter(this);
    QPixmap pixmap(":/1grass.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
