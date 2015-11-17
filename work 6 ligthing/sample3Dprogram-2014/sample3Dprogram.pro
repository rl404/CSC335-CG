TEMPLATE = app
TARGET = sample3Dprogram
QT += core \
    gui \
    opengl
HEADERS += GLWidget.h \
    statdialog.h \
    mainwindow.h
SOURCES += GLWidget.cpp \
    statdialog.cpp \
    main.cpp \
    mainwindow.cpp
FORMS += statdialog.ui \
    mainwindow.ui
RESOURCES += 
