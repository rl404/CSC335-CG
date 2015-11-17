#ifndef GLWIDGET_H_
#define GLWIDGET_H_

#include <QGLWidget>

#include "Mesh.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }

    bool read_file(QString fname,QString fextension);
    int read_OBJ(QString filename);
    
    bool isrotating;
    void rotating();
    void setrotating(bool r);
    void reset();
    void reseteffect();

    int hasNormal,shade,lightcolor,lighteffect,modelambient,modeldiffuse;
    int modelspecular,modelshininess,modelemission;
    double scroll;
    void color(int c);
    void effect(int e);
    void ambient(int a);
    void diffuse(int d);
    void specular(int s);
    void shininess(int sh);
    void emission(int e);
    void shading(int s);
    void normal(int n);

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void wheelEvent(QWheelEvent *event);

private:
    void normalizeAngle(int *angle);
    void advanceGears();
    void drawMeshPoints();
    void drawMeshWireframe();
    GLvoid crossProduct(float *Nx, float *Ny, float *Nz);
    int xRot;
    int yRot;
    int zRot;
    int gear1Rot;
    QPoint lastPos;

public:
	 Mesh *mesh;
	 
};

#endif /*GLWIDGET_H_*/
