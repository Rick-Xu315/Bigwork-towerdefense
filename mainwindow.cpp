#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"button.h"
#include"supwindow.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    setBGM();
    this->setFixedSize(960,540);
    ui->setupUi(this);
    Button *Startbut=new Button(":/0start.png");
    Startbut->setParent(this);
    Startbut->move(430,320);
    Supwindow*supwindow=new Supwindow;
    connect(Startbut,&QPushButton::clicked,this,[=](){
        this->hide();
        supwindow->show();
    });
    connect(supwindow,&Supwindow::Back,this,[=](){
        this->show();
        supwindow->hide();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*event){
 QPainter painter(this);
 QPixmap pixmap(":/0pic1.png");
 painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
void MainWindow::setBGM()
{

    BGMlist->addMedia(QUrl("qrc:/bgm1.mp3"));
    BGMlist->setCurrentIndex(1);
    BGMlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    QMediaPlayer *player=new QMediaPlayer;
    player->setPlaylist(BGMlist);
    player->setVolume(10);
    player->play();
}
