#include "supwindow.h"
#include"button.h"
#include"level1.h"
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


    connect(Backbut1,&Button::clicked,this,[=](){
        emit Back();

    });
    connect(Lev1but,&Button::clicked,this,[=](){
        this->hide();
        Level1* level1=new Level1(this,1,QPoint(768,250));
        level1->show();
        connect(level1,&Level1::backtosup,this,[=](){
            level1->hide();
            this->show();

        });

    });
    connect(Lev2but,&Button::clicked,this,[=](){
        this->hide();
        Level1* level2=new Level1(this,2,QPoint(780,168));
        level2->show();
        connect(level2,&Level1::backtosup,this,[=](){
            level2->hide();
            this->show();



        });

    });



}
void Supwindow::paintEvent(QPaintEvent*event){
 QPainter painter(this);
 QPixmap pixmap(":/0pic2.png");
 painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}






