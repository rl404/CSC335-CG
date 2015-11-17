#ifndef GLWIDGET_H_
#define GLWIDGET_H_
#define GLUT_DISABLE_ATEXIT_HACK

#include <QGLWidget>
#include <QtOpenGL>

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    int sec,min,hour;
    void reset();
    void set(int s,int m,int h);


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    void drawTriangle();
    void drawPolygon();
    void drawPolygonRed();
    void drawLines();

    void drawRec(int h,int w);
    void drawCube();
    void drawCircle(int r);
    void drawNumber();
};

#endif /*GLWIDGET_H_*/
