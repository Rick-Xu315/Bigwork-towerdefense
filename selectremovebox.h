#ifndef SELECTREMOVEBOX_H
#define SELECTREMOVEBOX_H

#include <QObject>

#include <QWidget>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include"button.h"
class Towerplace;
class Level1;
class Selectremovebox :public QObject
{

public:
    Selectremovebox(QPoint place,Towerplace*parent,Level1*game);
    void hide();
    void display();
    Button *box1=new Button(":/removebutton.png");
    Button* box2=new Button(":/levelupbutton.png");
    Button* box3=new Button(":/towerbutton4.png");

    void setparent(Level1*game);
private:
   Towerplace*_parentplace;
   QPoint  _place;
   Level1*_game;

signals:




};
#endif // SELECTREMOVEBOX_H
