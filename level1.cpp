#include "level1.h"
#include "supwindow.h"
#include"towerplace.h"
#include"tower.h"
#include"button.h"
#include"home.h"
#include"commonenemy.h"
#include"basic_enemy.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QSound>
#include<QPainter>
#include<QTimer>
#include<eliteenemy.h>
#include"boomerenemy.h"
#include"commontower.h"
#include"freezetower.h"
#include"boomtower.h"
Level1::Level1(QWidget *parent,int level,QPoint homeplace) : QMainWindow(parent),_waves(0),_win(false),_end(false),_money(1500),_level(level)
{
    home=new Home(homeplace,":/home.png");
    setFixedSize(960,540);

    if(_level==1)
    {loadTowerplace1();
    loadChangepoint1();}
    if(_level==2){
        loadChangepoint2();
        loadTowerplace2();
    }

    loadwave();
    QTimer* timer=new QTimer(this);
    timer->start(10);
    connect(timer,&QTimer::timeout,this,&Level1::UpdateAll);

    Button *Backbut2=new Button(":/0back.png");
    Backbut2->setParent(this);
    Backbut2->move(70,450);
    connect(Backbut2,&Button::clicked,this,[=](){
        emit backtosup();

    });



}
void Level1::loadTowerplace1()
{
    Towerplace place[]=
    {
        Towerplace( QPoint(120,63),this),
       Towerplace( QPoint(298,126),this),
        Towerplace(QPoint(120,183),this),
        Towerplace(QPoint(298,233),this),
        Towerplace(QPoint(180,296),this),
        Towerplace(QPoint(361,362),this),
        Towerplace(QPoint(537,230),this),
        Towerplace(QPoint(599,359),this),
        Towerplace(QPoint(719,230) ,this)
    };

    for(int i=0;i<9;i++)
    {
       _towerplace.push_back(place[i]);
    }



}
void Level1::loadTowerplace2()
{

    Towerplace place[]=
    {
        Towerplace( QPoint(120,83),this),
       Towerplace( QPoint(123,214),this),
        Towerplace(QPoint(243,144),this),
        Towerplace(QPoint(244,382),this),
        Towerplace(QPoint(428,216),this),
        Towerplace(QPoint(489,81),this),
        Towerplace(QPoint(489,439),this),
        Towerplace(QPoint(608,307),this),
        Towerplace(QPoint(671,138) ,this),
        Towerplace(QPoint(730,373) ,this)

    };

    for(int i=0;i<9;i++)
    {
       _towerplace.push_back(place[i]);
    }


}
void Level1::drawvolume(QPainter *painter)
{

    painter->setPen(QPen(Qt::black));
    painter->setFont(QFont("¿¬Ìå"));

    painter->drawText(QRect(700,30,100,25),QString("WavesLeft:%1").arg(4-_waves));
    painter->drawText(QRect(500,30,100,25),QString("HP:%1").arg(home->getHP()));
    painter->drawText(QRect(300,30,100,25),QString("Money:%1").arg(_money));
painter->drawText(QRect(100,30,100,25),QString("Level:%1").arg(_level));

}



void Level1::paintEvent(QPaintEvent*Event)
{
    QPainter painter(this);
    QPixmap winmap(":/win.png");
    QPixmap losemap(":/lose.png");
    if(_end||_win)
    {
        if(_end)
            painter.drawPixmap(0,0,this->width(),this->height(), losemap);
        else
            painter.drawPixmap(0,0,this->width(),this->height(),winmap);

                return;
    }

    if(_level==1){
    QPixmap pixmap(":/1grass.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
    if(_level==2)
    {
        QPixmap pixmap(":/2desert.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    }
    for(int i=0;i<9;i++)
    {

        _towerplace[i].draw(&painter);

    }
    home->draw(&painter);

    foreach(Tower *tower,_tower)
    {
        tower->draw(&painter);
    }
    foreach(Basic_enemy*basicenemy,_basicenemy)
        {
            basicenemy->draw(&painter);
        }
    foreach(Bullets*bullet,_bullet)
    {
        bullet->draw(&painter);
    }
    drawvolume(&painter);
}
void Level1::mousePressEvent(QMouseEvent *event){
    QPoint pressplace=event->pos();
    auto it =_towerplace.begin();
    while(it!=_towerplace.end())
    {
        if(it->contain(pressplace)&&!it->filled())
        {it->_funcbox->display();
            connect(it->_funcbox->box1,&Button::clicked,this,[=](){
                if(canBuy(400)){it->fill(true);
                Tower*tower=new CommonTower(it->center(),":/basictower.png",this);
                tower->setParent(this);
                it->setTower(tower);
                _tower.push_back(tower);
            it->_funcbox->hide();}});

           connect(it->_funcbox->box2,&Button::clicked,this,[=](){
                if(canBuy(600)){
                it->fill(true);
                Tower*tower=new Freezetower(it->center(),":/freezetower.png",this);
                tower->setParent(this);
                it->setTower(tower);
                _tower.push_back(tower);
         it->_funcbox->hide();}});

           connect(it->_funcbox->box3,&Button::clicked,this,[=](){

                if(canBuy(800)){ Tower*tower=new BoomTower(it->center(),":/boomtower.png",this);
                tower->setParent(this);
                _tower.push_back(tower);
                it->_funcbox->hide();}
           });

           connect(it->_funcbox->box4,&Button::clicked,this,[=](){
                it->_funcbox->hide();});


                update();
                break;
        }
        if(it->contain(pressplace)&&it->filled())
        {it->_removebox->display();
            connect(it->_removebox->box1,&Button::clicked,this,[=](){

                it->fill(false);
                _tower.removeOne(it->_tower);
                delete it->_tower;
                it->_tower=NULL;
                it->_removebox->hide();
                this->_money+=200;

            });
            connect(it->_removebox->box2,&Button::clicked,this,[=](){

               if(canBuy(500)){
                it->_tower->levelup();
                it->_removebox->hide();
            }});
            connect(it->_removebox->box3,&Button::clicked,this,[=](){


                it->_removebox->hide();
            });

            update();
            break;
        }
           it++;

    }
    }

bool Level1::canBuy(int cost)
{
    if(_money>=cost){

    _money-=cost;
return true;
    }
    else
    {

        return false;}

}



void Level1::loadChangepoint1()
{

    Changepoint*point4=new Changepoint(QPoint(812,286));
    Changepoint*point3=new Changepoint(QPoint(250,286));
    point3->setNext(point4);
    Changepoint*point2=new Changepoint(QPoint(250,118));
    point2->setNext(point3);
    Changepoint*point1=new Changepoint(QPoint(0,118));
    point1->setNext(point2);

    _changepoint.push_back(point1);
    _changepoint.push_back(point2);
    _changepoint.push_back(point3);
    _changepoint.push_back(point4);
}

void Level1::loadChangepoint2()
{
    Changepoint*point10=new Changepoint(QPoint(790,200));
    Changepoint*point9=new Changepoint(QPoint(672,200));
    point9->setNext(point10);
    Changepoint*point8=new Changepoint(QPoint(672,370));
    point8->setNext(point9);
    Changepoint*point7=new Changepoint(QPoint(490,370));
    point7->setNext(point8);
    Changepoint*point6=new Changepoint(QPoint(490,146));
    point6->setNext(point7);
    Changepoint*point5=new Changepoint(QPoint(307,146));
    point5->setNext(point6);
    Changepoint*point4=new Changepoint(QPoint(307,306));
    point4->setNext(point5);
    Changepoint*point3=new Changepoint(QPoint(187,306));
    point3->setNext(point4);
    Changepoint*point2=new Changepoint(QPoint(187,145));
    point2->setNext(point3);
    Changepoint*point1=new Changepoint(QPoint(0,145));
    point1->setNext(point2);


    _changepoint.push_back(point1);
    _changepoint.push_back(point2);
    _changepoint.push_back(point3);
    _changepoint.push_back(point4);

    _changepoint.push_back(point5);
     _changepoint.push_back(point6);
      _changepoint.push_back(point7);
       _changepoint.push_back(point8);
        _changepoint.push_back(point9);
         _changepoint.push_back(point10);

}
void Level1::UpdateAll()
{   foreach(Basic_enemy*basicenemy,_basicenemy)
    {
        basicenemy->move();

        if(basicenemy!=NULL){ Basic_enemy*base=basicenemy;
        Eliteenemy*elite=dynamic_cast<Eliteenemy*>(base);
        if(elite!=NULL)
            elite->getrage();}



    }

foreach(Tower*tower,_tower)
{
    tower->checkenemy();}


    update();
}


void Level1::receivedamage()
{
home->getdamage();
if(home->getHP()<=0)
    gameover();
}

void Level1::removeenemy(Basic_enemy *enemy)
{
Q_ASSERT(enemy);
    if(enemy){
        _money+=enemy->_reward;
    _basicenemy.removeOne(enemy);
    delete enemy;}
    if(_basicenemy.empty())
    {
        ++_waves;
        if(!loadwave())
        {
            _win=true;

        }
    }
}


void Level1::loadbullet(Bullets*bullet)
{
    Q_ASSERT(bullet);
    _bullet.push_back(bullet);
}
bool Level1::loadwave()
{
    if(_waves>=5)
    return false;
    Changepoint*startpoint=_changepoint.front();
    int enemybornInterval[]={500,1300,2100,2900,3700,4500};
    if(_waves==0)
    {   for(int i=0;i<=3;i++){
        Basic_enemy*enemy=new CommonEnemy(startpoint,":/basicenemy.png",this);
        _basicenemy.push_back(enemy);
        QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));


    }}
    if(_waves==1)
    {   for(int i=0;i<=4;i++){
       if(i<=3){ Basic_enemy*enemy=new CommonEnemy(startpoint,":/basicenemy.png",this);
        _basicenemy.push_back(enemy);
        QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}
       if(i==4){ Basic_enemy*enemy=new Eliteenemy(startpoint,":/eliteenemy.png",this);
           _basicenemy.push_back(enemy);
           QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}


    }}
        if(_waves==2){
        for(int i=0;i<=4;i++){
         if(i<=2){ Basic_enemy*enemy=new CommonEnemy(startpoint,":/basicenemy.png",this);
                _basicenemy.push_back(enemy);
                QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}
         if(i>2){ Basic_enemy*enemy=new Eliteenemy(startpoint,":/eliteenemy.png",this);
             _basicenemy.push_back(enemy);
             QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}

        }}
        if(_waves==3){
            for(int i=0;i<=4;i++){
                if(i==0){ Basic_enemy*enemy=new Boomerenemy(startpoint,":/boomerenemy.png",this);
                    _basicenemy.push_back(enemy);
                    QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}
             if(i==1||i==2){ Basic_enemy*enemy=new CommonEnemy(startpoint,":/basicenemy.png",this);
                    _basicenemy.push_back(enemy);
                    QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}
             if(i>2){ Basic_enemy*enemy=new Eliteenemy(startpoint,":/eliteenemy.png",this);
                 _basicenemy.push_back(enemy);
                 QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}

            }
        }
        if(_waves==4)
        {
            for(int i=0;i<=5;i++){
                if(i<=1){ Basic_enemy*enemy=new Boomerenemy(startpoint,":/boomerenemy.png",this);
                    _basicenemy.push_back(enemy);
                    QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}
             if(i>1&&i<=3){ Basic_enemy*enemy=new CommonEnemy(startpoint,":/basicenemy.png",this);
                    _basicenemy.push_back(enemy);
                    QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}
             if(i>3){ Basic_enemy*enemy=new Eliteenemy(startpoint,":/eliteenemy.png",this);
                 _basicenemy.push_back(enemy);
                 QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));}

            }
        }

    return true;


}

void Level1::removeBullet(Bullets *bullet)
{
                    Q_ASSERT(bullet);
            if(bullet)
            {_bullet.removeOne(bullet);}
            delete bullet;

        }
void Level1::removetower(Tower *tower)
        {
            Q_ASSERT(tower);
            if(_tower.indexOf(tower)!=-1)
           {

                _tower.removeOne(tower);}
            if(tower)delete tower;


        }
void Level1:: gameover()
        {
            if(!_end)
            {
                _end=true;

            }
        }






