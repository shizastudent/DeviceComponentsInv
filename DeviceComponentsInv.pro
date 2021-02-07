QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

MYSQL_LIBS=-lmysqld

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminview.cpp \
    checkmanview.cpp \
    componentview.cpp \
    database.cpp \
    deviceview.cpp \
    generatewaybillview.cpp \
    loginview.cpp \
    main.cpp \
    mainwindow.cpp \
    repairerview.cpp \
    warehouseview.cpp

HEADERS += \
    adminview.h \
    checkmanview.h \
    componentview.h \
    database.h \
    dependencies.h \
    deviceview.h \
    generatewaybillview.h \
    loginview.h \
    mainwindow.h \
    repairerview.h \
    warehouseview.h

FORMS += \
    adminview.ui \
    checkmanview.ui \
    componentview.ui \
    deviceview.ui \
    generatewaybillview.ui \
    loginview.ui \
    mainwindow.ui \
    repairerview.ui \
    warehouseview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
