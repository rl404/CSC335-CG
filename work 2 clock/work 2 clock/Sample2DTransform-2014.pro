TEMPLATE = app
TARGET = Sample2DTransformation

QT += core \
    widgets
HEADERS += MyRenderWidget.h \
    mainwindow.h \
    setwindow.h
SOURCES += MyRenderWidget.cpp \
    mainwindow.cpp \
    main.cpp \
    setwindow.cpp
FORMS += MyRenderWidget.ui \
    mainwindow.ui \
    setwindow.ui
RESOURCES += 

DISTFILES += \
    KjForm.ui.qml \
    Kj.qml
