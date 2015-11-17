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
    GLuint makeGear(const GLfloat *reflectance, GLdouble innerRadius,
                    GLdouble outerRadius, GLdouble thickness,
                    GLdouble toothSize, GLint toothCount);
    void drawGear(GLuint gear, GLdouble dx, GLdouble dy, GLdouble dz,
                  GLdouble angle);
    void normalizeAngle(int *angle);

    GLuint gear1;
    GLuint gear2;
    GLuint gear3;
    GLuint gear4;
    int xRot;
    int yRot;
    int zRot;
    int gear1Rot; 
    QPoint lastPos;

    GLuint cube;
    GLuint makeCube(const GLfloat *reflectance, int l,int h,int w);
    void drawCube2(double l, double h, double w, int c);
    void drawCube(GLuint cube, GLdouble dx, GLdouble dy, GLdouble dz,
                  GLdouble angle);
};

#endif /*GLWIDGET_H_*/
