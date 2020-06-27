#include "tower.h"
#include "towerplace.h"
#include"Somefunction.h"
#include"button.h"
#include"bullets.h"
#include"basic_enemy.h"
#include"supwindow.h"
#include<QPointer>
#include<QTimer>
#include<QList>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QMediaPlayer>
#include<QUrl>
#include"level1.h"
#include<QSound>
Tower::Tower(QPoint place, QString pic,Level1*game) : QObject(0),_place(place),_targetenemy(NULL),_pic(pic),_shoot(true),_game(game)
{QMediaPlayer*player=new QMediaPlayer;
   player->setMedia(QUrl("qrc:/set.wav"));
   player->setVolume(30);

    player->play();
    _range=150;
    _rate=500;
    _damage=5;

    connect(_ratetimer, SIGNAL(timeout()), this, SLOT(shootweapon()));


}
Tower::~Tower()
{
    delete _ratetimer;
    _ratetimer=NULL;
}
void Tower::setvolume(int range, int damage, int rate)
{
    _range=range;
    _damage=damage;
    _rate=rate;

}

const QSize Tower::_size(69,120);
void Tower::draw(QPainter *painter){
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(_place,_range,_range);
    static const QPoint just(-34,-90);
    painter->translate(_place);
    painter->drawPixmap(just,_pic);
    painter->restore();

}







void Tower::shootweapon(){
   if(_shoot){
    Bullets*bullet=new Bullets(_place,_targetenemy->_currentPlace,_damage,_targetenemy,":/bullet1.png",_game);
    bullet->move();
    _game->loadbullet(bullet);}
}

void Tower::checkenemy()
{
    if(_targetenemy)
    {
        if(!collision(_place,_range,_targetenemy->getcurrentplace(),1))
        {
                        outofrange();
        }


    }
    else
    {
QList<Basic_enemy*>_enemy=_game->_basicenemy;
        foreach(Basic_enemy*enemy,_enemy)
        {
            if(collision(_place,_range,enemy->getcurrentplace(),1))
            {chooseEnemy(enemy);
            break;
        }
    }


}}

void Tower::fireenemy()
{
    _ratetimer->start(_rate);
}

void Tower::chooseEnemy(Basic_enemy *enemy)
{
   Q_ASSERT(enemy);
    _targetenemy=enemy;
    fireenemy();
    _targetenemy->getfired(this);
}

void Tower::targetkilled()
{
    if(_targetenemy)
    {    _targetenemy=NULL;
      }
    if(_ratetimer)
    _ratetimer->stop();

}


void Tower::outofrange()
{
    if(_targetenemy)
    {
        _targetenemy->getoutofrange(this);
        _targetenemy=NULL;


    }
 if(_ratetimer)
         _ratetimer->stop();

}

void Tower::setpic(QString newpic)
{
    _pic=newpic;
}



