#ifndef SELECTFUNCBOX_H
#define SELECTFUNCBOX_H

#include <QWidget>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include"button.h"
class Towerplace;
class Level1;
class Selectfuncbox :public QObject
{

public:
    Selectfuncbox(QPoint place,Towerplace*parent,Level1*game);
    void hide();
    void display();
    Button *box1=new Button(":/towerbutton1.png");
    Button* box2=new Button(":/towerbutton2.png");
    Button* box3=new Button(":/towerbutton3.png");
    Button* box4=new Button(":/towerbutton4.png");
    void setparent(Level1*game);
private:
   Towerplace*_parentplace;
   QPoint  _place;
   Level1*_game;

signals:
   void build1();
   void build2();
   void build3();



};

#endif // SELECTFUNCBOX_H
