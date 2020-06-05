#ifndef LEVEL2_H
#define LEVEL2_H

#include <QMainWindow>
#include "supwindow.h"
#include"button.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
class Level2 : public QMainWindow
{
    Q_OBJECT
public:
    void paintEvent(QPaintEvent*Event);
    explicit Level2(QWidget *parent = nullptr);
    void Back();

signals:

};

#endif // LEVEL1_H

