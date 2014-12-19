#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T03:27:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TravelingSalesmanUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    edge.cpp \
    graphwidget.cpp \
    node.cpp \
    ../OtimizationGraph/SalesmanGraph.cpp \
    ../OtimizationGraph/SNodes.cpp \
    ../OtimizationGraph/TravelingSalesmanSimplex.cpp

HEADERS  += mainwindow.h \
    edge.h \
    graphwidget.h \
    node.h \
    ../OtimizationGraph/SalesmanGraph.h \
    ../OtimizationGraph/SNodes.h \
    ../OtimizationGraph/TravelingSalesmanSimplex.h

FORMS    += mainwindow.ui

INCLUDEPATH += ..\Libs

unix|win32: LIBS += -l..\Libs\liblpsolve55 /NODEFAULTLIB:MSVCRTD


unix|win32: LIBS += -l..\Libs\lpsolve55
