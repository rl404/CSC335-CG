TEMPLATE = app
TARGET = sample2D_OpengGL
QT += core \
    widgets \
    opengl
HEADERS += MyImage.h \
    GLWidget.h \
    statdialog.h \
    mainwindow.h
SOURCES += MyImage.cpp \
    GLWidget.cpp \
    statdialog.cpp \
    main.cpp \
    mainwindow.cpp
FORMS += statdialog.ui \
    mainwindow.ui
RESOURCES += 
