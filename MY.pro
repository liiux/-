#-------------------------------------------------
#
# Project created by QtCreator 2019-03-25T20:25:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MY
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += C++11

SOURCES += \
        main.cpp \
        Login.cpp \
    Registe.cpp \
    FlightID.cpp \
    UserMain.cpp \
    Alter.cpp \
    Alter_Password.cpp \
    Book.cpp \
    MyOrder.cpp \
    Item.cpp \
    MyOrderItem.cpp \
    Refund.cpp \
    Passenger.cpp \
    BookOrder.cpp \
    AdminMain.cpp \
    Alter_Flight.cpp \
    Add_Flight.cpp \
    Delete_Flight.cpp \
    background.cpp \
    Delete.cpp \
    Flight.cpp \
    index.cpp \
    Initialize.cpp \
    Modify.cpp \
    Others.cpp \
    Search.cpp \
    Write.cpp \
    Lucky.cpp \
    Query_Flight.cpp \
    QueryItem.cpp \
    Write_Oneday.cpp

HEADERS += \
        Login.h \
    Registe.h \
    FlightID.h \
    UserMain.h \
    Alter.h \
    Alter_Password.h \
    Book.h \
    MyOrder.h \
    Item.h \
    MyOrderItem.h \
    Refund.h \
    Passenger.h \
    BookOrder.h \
    AdminMain.h \
    Alter_Flight.h \
    Add_Flight.h \
    Delete_Flight.h \
    background.h \
    Delete.h \
    Flight.h \
    index.h \
    Initialize.h \
    Modify.h \
    Others.h \
    Search.h \
    Write.h \
    Lucky.h \
    Query_Flight.h \
    QueryItem.h \
    Write_Oneday.h

FORMS += \
        login.ui \
    registe.ui \
    usermain.ui \
    alter.ui \
    alter_password.ui \
    book.ui \
    myorder.ui \
    refund.ui \
    bookorder.ui \
    adminmain.ui \
    alter_flight.ui \
    add_flight.ui \
    delete_flight.ui \
    lucky.ui \
    query_flight.ui \
    write_oneday.ui
