#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);
    Button(QString pic);

signals:

};

#endif // BUTTON_H
