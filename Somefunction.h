#ifndef SOMEFUNCTION_H
#define SOMEFUNCTION_H
#include<QPoint>
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QtMath>


#endif // SOMEFUNCTION_H
inline bool collision(QPoint point1,int r1,QPoint point2,int r2)
{
    const int deltx=point1.x()-point2.x();
    const int delty=point1.y()-point2.y();
    const int delt=(int)qSqrt(deltx*deltx+delty*delty);
    if(delt<=r1+r2)
        return true;
    else return false;
}
