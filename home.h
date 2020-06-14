#ifndef HOME_H
#define HOME_H

#include <QObject>
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QMediaPlayer>
#include<QUrl>


class Home : public QObject
{
    Q_OBJECT
public:
    explicit Home(QObject *parent = nullptr);
    Home(QPoint place,QString pic);
    void getdamage();
    int getHP();
    void draw(QPainter*painter);

private:
    int _HP;
    int _currentHP;
    QPoint _place;
    QPixmap _pic;
    static const QSize _size;

signals:

};

#endif // HOME_H
