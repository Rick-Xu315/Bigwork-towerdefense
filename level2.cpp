#include "level2.h"
#include "supwindow.h"
#include"button.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
Level2::Level2(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(960,540);
}
void Level2::paintEvent(QPaintEvent*Event)
{

    QPainter painter(this);
    QPixmap pixmap(":/2desert.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
