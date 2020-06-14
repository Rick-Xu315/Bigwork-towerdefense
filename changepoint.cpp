#include "changepoint.h"
#include<QPoint>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>

Changepoint::Changepoint(QPoint place) : _place(place),_nextChangepoint(NULL)
{

}

void Changepoint::setNext(Changepoint *next)
{
    _nextChangepoint=next;
}
Changepoint* Changepoint::getNext()const
{
    return _nextChangepoint;
}
const QPoint Changepoint::getPlace()const
{
    return _place;
}
