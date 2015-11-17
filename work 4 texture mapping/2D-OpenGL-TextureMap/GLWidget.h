#ifndef GLWIDGET_H_
#define GLWIDGET_H_

#include <QGLWidget>
#include "MyImage.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void createTexture(QImage& img);

    void drawNormal();
    void drawCircle(int r);
    void drawEllipse(int w,int h);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void createTexture();

    unsigned char myData[256][256][3]; //create our own texture.
    unsigned char myTexels[400][400][3]; //read-in image used as a texture.
    QImage image;
    bool textureReady;
};

#endif /*GLWIDGET_H_*/
