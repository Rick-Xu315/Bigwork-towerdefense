#include "supwindow.h"
#include"button.h"
#include"level1.h"
#include"level2.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
Supwindow::Supwindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(960,540);
    Button *Backbut1=new Button(":/0back.png");
    Backbut1->setParent(this);
    Backbut1->move(425,400);
    Button *Lev1but=new Button(":/0level1.png");
    Button *Lev2but=new Button(":/0level2.png");
    Lev1but->setParent(this);
    Lev2but->setParent(this);
    Lev1but->setFixedSize(127,41);
    Lev2but->setFixedSize(127,41);
    Lev1but->move(425,200);
    Lev2but->move(425,300);
    Level1* level1=new Level1;
    Level2* level2=new Level2;
    connect(Backbut1,&Button::clicked,this,[=](){
        emit Back();

    });
    connect(Lev1but,&Button::clicked,this,[=](){
        this->hide();
        level1->show();

    });
    connect(Lev2but,&Button::clicked,this,[=](){
        this->hide();
        level2->show();

    });

}
void Supwindow::paintEvent(QPaintEvent*event){
 QPainter painter(this);
 QPixmap pixmap(":/0pic2.png");
 painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}