#-------------------------------------------------
#
# Project created by QtCreator 2014-12-17T03:40:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OtimizationUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    edge.cpp \
    graphwidget.cpp \
    ../OtimizationGraph/TravelingSalesmanSimplex.cpp \
    ../OtimizationGraph/SalesmanGraph.cpp \
    ../OtimizationGraph/SNodes.cpp

HEADERS  += mainwindow.h \
    node.h \
    edge.h \
    graphwidget.h \
    ../OtimizationGraph/TravelingSalesmanSimplex.h \
    ../OtimizationGraph/SalesmanGraph.h \
    ../OtimizationGraph/SNodes.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:\Projects\UFABC\OtimizationGraph\Libs

unix|win32: LIBS += -l..\Libs\liblpsolve55 /NODEFAULTLIB:MSVCRTD


unix|win32: LIBS += -l..\Libs\lpsolve55
