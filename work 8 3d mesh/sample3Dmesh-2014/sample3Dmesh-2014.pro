TEMPLATE = app
TARGET = sample3Dmesh
QT += core \
    gui \
    widgets \
    opengl
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000
HEADERS += Vector3d.h \
    Point3d.h \
    VertexID.h \
    Mesh.h \
    Face.h \
    statwidget.h \
    GLWidget.h \
    statdialog.h \
    mainwindow.h
SOURCES += Vector3d.cpp \
    Point3d.cpp \
    VertexID.cpp \
    Mesh.cpp \
    Face.cpp \
    statwidget.cpp \
    GLWidget.cpp \
    statdialog.cpp \
    main.cpp \
    mainwindow.cpp
FORMS += statwidget.ui \
    statdialog.ui \
    mainwindow.ui
RESOURCES += 
