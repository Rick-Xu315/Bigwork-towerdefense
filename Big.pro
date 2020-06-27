QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
# any Qt feature that has been marked deprecated (the exact warnings

# The following define makes your compiler emit warnings if you use
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basic_enemy.cpp \
    boomerenemy.cpp \
    boomtower.cpp \
    bullets.cpp \
    button.cpp \
    changepoint.cpp \
    commonenemy.cpp \
    commontower.cpp \
    eliteenemy.cpp \
    freezetower.cpp \
    home.cpp \
    level1.cpp \
    main.cpp \
    mainwindow.cpp \
    selectfuncbox.cpp \
    selectremovebox.cpp \
    supwindow.cpp \
    tower.cpp \
    towerplace.cpp

HEADERS += \
    Somefunction.h \
    basic_enemy.h \
    boomerenemy.h \
    boomtower.h \
    bullets.h \
    button.h \
    changepoint.h \
    commonenemy.h \
    commontower.h \
    eliteenemy.h \
    freezetower.h \
    home.h \
    level1.h \
    mainwindow.h \
    selectfuncbox.h \
    selectremovebox.h \
    supwindow.h \
    tower.h \
    towerplace.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
