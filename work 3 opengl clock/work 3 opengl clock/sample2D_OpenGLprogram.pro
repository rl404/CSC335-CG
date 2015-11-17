TEMPLATE = app
TARGET = sample2D_OpengGL
QT += core \
    widgets \
    opengl
HEADERS += GLWidget.h \
    mainwindow.h \
    statdialog.h
SOURCES += GLWidget.cpp \
    main.cpp \
    mainwindow.cpp \
    statdialog.cpp
FORMS += statdialog.ui \
    mainwindow.ui
RESOURCES += 
CONFIG += c++11
