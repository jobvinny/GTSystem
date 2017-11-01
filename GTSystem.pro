#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T13:53:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GTSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    studentlogin.cpp \
    adminlogin.cpp \
    register.cpp \
    searchdetails.cpp \
    viewdetails.cpp \
    adminchoice.cpp

HEADERS  += mainwindow.h \
    studentlogin.h \
    adminlogin.h \
    register.h \
    searchdetails.h \
    viewdetails.h \
    adminchoice.h

FORMS    += mainwindow.ui \
    studentlogin.ui \
    adminlogin.ui \
    register.ui \
    searchdetails.ui \
    viewdetails.ui \
    adminchoice.ui

win32: LIBS += -L$$PWD/../mysql/mysql-connector-c++-noinstall-1.1.7-winx64/lib/ -lmysqlcppconn

INCLUDEPATH += $$PWD/../mysql/mysql-connector-c++-noinstall-1.1.7-winx64/include
DEPENDPATH += $$PWD/../mysql/mysql-connector-c++-noinstall-1.1.7-winx64/include

win32: LIBS += -L$$PWD/../mysql/mysql-connector-c++-noinstall-1.1.7-winx64/lib/ -lmysqlcppconn-static

INCLUDEPATH += $$PWD/../mysql/mysql-connector-c++-noinstall-1.1.7-winx64/include
DEPENDPATH += $$PWD/../mysql/mysql-connector-c++-noinstall-1.1.7-winx64/include

win32: LIBS += -L$$PWD/../mysql/mysql-connector-c-6.1.9-win32/lib/ -llibmysql

INCLUDEPATH += $$PWD/../mysql/mysql-connector-c-6.1.9-win32/include
DEPENDPATH += $$PWD/../mysql/mysql-connector-c-6.1.9-win32/include
