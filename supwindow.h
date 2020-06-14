#ifndef SUPWINDOW_H
#define SUPWINDOW_H

#include <QMainWindow>
#include"button.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>

class Supwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Supwindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*Event);

signals:
    void Back();
};

#endif // SUPWINDOW_H
