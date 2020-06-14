#include "level1.h"
#include "supwindow.h"
#include"towerplace.h"
#include"tower.h"
#include"button.h"
#include"basic_enemy.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QTimer>

Level1::Level1(QWidget *parent) : QMainWindow(parent)
{   _waves=0;

    setFixedSize(960,540);
    loadTowerplace();
    loadChangepoint();
    loadwave();
    QTimer* timer=new QTimer(this);
    timer->start(10);
    connect(timer,&QTimer::timeout,this,&Level1::UpdateAll);
    connect(timer,&QTimer::timeout,this,&Level1::Updateenemylist);
}
void Level1::loadTowerplace()
{
    QPoint place[]=
    {
        QPoint(120,63),
        QPoint(298,126),
        QPoint(120,183),
        QPoint(298,233),
        QPoint(180,296),
        QPoint(361,362),
        QPoint(537,230),
        QPoint(599,359),
        QPoint(719,230)
    };

    for(int i=0;i<9;i++)
    {
       _towerplace.push_back(place[i]);
    }



}
void Level1::paintEvent(QPaintEvent*Event)
{

    QPainter painter(this);
    QPixmap pixmap(":/1grass.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

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
}
void Level1::mousePressEvent(QMouseEvent *event){
    QPoint pressplace=event->pos();
    auto it =_towerplace.begin();
    while(it!=_towerplace.end())
    {
        if(canBuy()&&it->contain(pressplace)&&!it->filled())
        {
                it->fill();
                Tower*tower=new Tower(it->center(),":/basictower.png");
                tower->setParent(this);
                _tower.push_back(tower);
                update();
                break;
        }
           it++;

    }
    }

bool Level1::canBuy()
{
    return true;
}



void Level1::loadChangepoint()
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



void Level1::UpdateAll()
{   foreach(Basic_enemy*basicenemy,_basicenemy)
    {
        basicenemy->move();
    }

    update();
}


void Level1::receivedamage()
{
home->getdamage();
}

void Level1::removeenemy(Basic_enemy *enemy)
{

    _basicenemy.removeOne(enemy);
    delete enemy;
    if(_basicenemy.empty())
    {
        ++_waves;
        if(!loadwave())
        {
            _win=true;
        }
    }
}



bool Level1::loadwave()
{
    if(_waves>=4)
    return false;
    Changepoint*startpoint=_changepoint.front();
    int enemybornInterval[]={100,1000,1600,2400};
    for(int i=0;i<4;i++)
    {
        Basic_enemy*enemy=new Basic_enemy(startpoint,":/basicenemy.png");
        _basicenemy.push_back(enemy);
        QTimer::singleShot(enemybornInterval[i],enemy,SLOT(action()));

    }
    return true;


}

void Level1::Updateenemylist()
{
    connect(_basicenemy.at(0),&Basic_enemy::damage,this,[=](){
        removeenemy(_basicenemy.at(0));
        receivedamage();
    });
}





