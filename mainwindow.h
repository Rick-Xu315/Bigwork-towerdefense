#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QMediaPlayer>
#include<QMediaPlaylist>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    void paintEvent(QPaintEvent*Event);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setBGM();

private:
    Ui::MainWindow *ui;
    QMediaPlaylist *BGMlist=new QMediaPlaylist;
};
#endif // MAINWINDOW_H
