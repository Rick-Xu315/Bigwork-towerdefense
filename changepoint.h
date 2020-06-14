#ifndef CHANGEPOINT_H
#define CHANGEPOINT_H

#include <QObject>
#include<QPoint>

class Changepoint
{

public:
    Changepoint(QPoint place);


    void setNext(Changepoint *next);
    Changepoint*getNext()const;
    const QPoint getPlace()const;
private:
    QPoint _place;
    Changepoint *_nextChangepoint;

signals:

};

#endif // CHANGEPOINT_H
