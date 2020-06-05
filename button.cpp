#include "button.h"
#include<QPointer>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include<QPainter>

Button::Button(QString pic) : QPushButton(0)
{
    QPixmap pixmap(pic);
    setFixedSize(pixmap.width(),pixmap.height());
    setStyleSheet("QPushButton(border:0px:}");
    setIcon(pixmap);
    setIconSize(QSize(pixmap.width(),pixmap.height()));


}
