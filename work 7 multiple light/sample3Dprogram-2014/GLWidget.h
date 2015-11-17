#ifndef GLWIDGET_H_
#define GLWIDGET_H_

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    int xRotation() const { return xRot; }
    int yRotation() const { return yRot; }
    int zRotation() const { return zRot; }

    bool isrotating;
    void rotating();
    void setrotating(bool r);
    void reset();
    void reseteffect();

    int lightcolor,lighteffect,modelambient,modeldiffuse;
    int modelspecular,modelshininess,modelemission;
    void color(int c);
    void effect(int e);
    void ambient(int a);
    void diffuse(int d);
    void specular(int s);
    void shininess(int sh);
    void emission(int e);

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

private slots:
    void advanceGears();

private:
    void normalizeAngle(int *angle);

    int xRot;
    int yRot;
    int zRot;
    int gear1Rot; 
    QPoint lastPos;

    void drawCylinder(float h, float rb, float rt, float s1, float s2);
    void drawSnowman();
};

#endif /*GLWIDGET_H_*/
