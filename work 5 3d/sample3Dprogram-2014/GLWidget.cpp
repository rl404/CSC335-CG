#include "GLWidget.h"
#include <QtGui>
#include <QtOpenGL>
#include <cmath>


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    gear1 = 0;
    gear2 = 0;
    gear3 = 0;
    gear4 = 0;
    xRot = 0;
    yRot = 0;
    zRot = 0;
    gear1Rot = 0;

    isrotating=false;
    cube = 0;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceGears()));
    timer->start(80);
}

GLWidget::~GLWidget()
{
    makeCurrent();
    glDeleteLists(gear1, 1);
    glDeleteLists(gear2, 1);
    glDeleteLists(gear3, 1);
    glDeleteLists(gear4, 1);

    glDeleteLists(cube,1);
}

void GLWidget::setXRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setYRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::initializeGL()
{
    glClearColor(0.878f, 1.000f, 1.000f, 0.0f); //background color

    static const GLfloat lightPos[4] = { 0.0f, 0.0f, 0.0f, 1.0f }; //light position
    static const GLfloat reflectance1[4] = { 0.5f, 0.1f, 0.0f, 1.0f }; //surface color
    static const GLfloat reflectance2[4] = { 0.0f, 0.1f, 0.5f, 1.0f };
    static const GLfloat reflectance3[4] = { 0.7f, 0.8f, 0.1f, 1.0f };
    static const GLfloat reflectance4[4] = { 0.8f, 0.2f, 0.6f, 1.0f };

    static const GLfloat reflectanceC[4] = { 0.0f, 1.0f, 0.0f, 1.0f };


    //glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    gear1 = makeGear(reflectance1, 4.0, 5.0, 1.0, 0.7, 20);
    gear2 = makeGear(reflectance2, 1.0, 1.5, 0.5, 0.8, 10);
    gear3 = makeGear(reflectance3, 2.0, 3.2, 1.5, 1.0, 10);
    gear4 = makeGear(reflectance4, 2.0, 5.0, 1.0, 0.7, 20);

    cube = makeCube(reflectanceC, 3,3,3);
    
    glEnable(GL_NORMALIZE);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //the base
    glPushMatrix();
    glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0);

    rotating();

    drawCube2(5,5,5,0);
    glPopMatrix();

    //the color
    for(float x=-1.0;x<2.0;x++){
        for(int y=-1.0;y<2.0;y++){
            for(int z=-1.0;z<2.0;z++){
                glPushMatrix();
                glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
                glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
                glRotated(zRot / 16.0, 0.0, 0.0, 1.0);

                rotating();

                glTranslated(1.75*x,1.75*y,1.75*z);
                drawCube2(1.51,1.51,1.51,1);
                glPopMatrix();
            }
        }
    }

    /*
    for(float x=-1.0;x<2.0;x++){
        for(int y=-1.0;y<2.0;y++){
            for(int z=-1.0;z<2.0;z++){
                glPushMatrix();
                glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
                glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
                glRotated(zRot / 16.0, 0.0, 0.0, 1.0);

                drawCube(cube, 2.0*x, 2.0*y, 2.0*z, 0.0);
                glPopMatrix();
            }
        }
    }

    /*
    glPushMatrix();
    glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0);

    drawGear(gear1, 0.0, 0.0, 0.0, gear1Rot / 16.0);

    glPushMatrix();
    //glRotated(+90.0, 1.0, 0.0, 0.0);
    drawGear(gear2, 0.0, 0.0, 0.0, +2.0 * (gear1Rot / 16.0) - 2.0);
    drawGear(gear3, 0, 0, 0, -2.0 * (gear1Rot / 16.0) - 2.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.5, 5.2, -4.7);
    glRotated(+90.0, 1.0, 0.0, 0.0);
    drawGear(gear4, 0, 0.0, 0.0, 2.0 * (gear1Rot / 32.0) - 2.0); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.5, -5.2, -4.7);
    glRotated(+90.0, 1.0, 0.0, 0.0);
    drawGear(gear4, 0, 0.0, 0.0, -2.0 * (gear1Rot / 32.0) - 2.0); 
    glPopMatrix();
    
    glTranslated(0.0, 0.0, -9.7);
    drawGear(gear1, 0.0, 0.0, 0.0, -gear1Rot / 16.0);
    
    glPopMatrix();
    */
}

void GLWidget::resizeGL(int width, int height)
{
	//viewport
    glViewport(0,0, width, height);
    
    //projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, +1.0, -1.0, 1.0, 1.0, 60.0);
      
    //viewing and modeling
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -10.0);
      
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}

void GLWidget::advanceGears()
{
    if(isrotating){gear1Rot += 2 * 16;}
    updateGL();
}

GLuint GLWidget::makeGear(const GLfloat *reflectance, GLdouble innerRadius,
                          GLdouble outerRadius, GLdouble thickness,
                          GLdouble toothSize, GLint toothCount)
{
    const double Pi = 3.14159;

    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, reflectance);

    GLdouble r0 = innerRadius;
    GLdouble r1 = outerRadius - toothSize / 2.0;
    GLdouble r2 = outerRadius + toothSize / 2.0;
    GLdouble delta = (2.0 * Pi / toothCount) / 4.0;
    GLdouble z = thickness / 2.0;
    int i, j;

    glShadeModel(GL_FLAT);

    for (i = 0; i < 2; ++i) {
        GLdouble sign = (i == 0) ? +1.0 : -1.0;

        glNormal3d(0.0, 0.0, sign);

        glBegin(GL_QUAD_STRIP);
        for (j = 0; j <= toothCount; ++j) {
            GLdouble angle = 2.0 * Pi * j / toothCount;
	    glVertex3d(r0 * cos(angle), r0 * sin(angle), sign * z);
	    glVertex3d(r1 * cos(angle), r1 * sin(angle), sign * z);
	    glVertex3d(r0 * cos(angle), r0 * sin(angle), sign * z);
	    glVertex3d(r1 * cos(angle + 3 * delta), r1 * sin(angle + 3 * delta),
                       sign * z);
        }
        glEnd();

        glBegin(GL_QUADS);
        for (j = 0; j < toothCount; ++j) {
            GLdouble angle = 2.0 * Pi * j / toothCount;
	    glVertex3d(r1 * cos(angle), r1 * sin(angle), sign * z);
	    glVertex3d(r2 * cos(angle + delta), r2 * sin(angle + delta),
                       sign * z);
	    glVertex3d(r2 * cos(angle + 2 * delta), r2 * sin(angle + 2 * delta),
                       sign * z);
	    glVertex3d(r1 * cos(angle + 3 * delta), r1 * sin(angle + 3 * delta),
                       sign * z);
        }
        glEnd();
    }

    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < toothCount; ++i) {
        for (j = 0; j < 2; ++j) {
            GLdouble angle = 2.0 * Pi * (i + (j / 2.0)) / toothCount;
            GLdouble s1 = r1;
            GLdouble s2 = r2;
            if (j == 1)
                qSwap(s1, s2);

	    glNormal3d(cos(angle), sin(angle), 0.0);
	    glVertex3d(s1 * cos(angle), s1 * sin(angle), +z);
	    glVertex3d(s1 * cos(angle), s1 * sin(angle), -z);

	    glNormal3d(s2 * sin(angle + delta) - s1 * sin(angle),
                       s1 * cos(angle) - s2 * cos(angle + delta), 0.0);
	    glVertex3d(s2 * cos(angle + delta), s2 * sin(angle + delta), +z);
	    glVertex3d(s2 * cos(angle + delta), s2 * sin(angle + delta), -z);
        }
    }
    glVertex3d(r1, 0.0, +z);
    glVertex3d(r1, 0.0, -z);
    glEnd();

    glShadeModel(GL_SMOOTH);

    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= toothCount; ++i) {
	GLdouble angle = i * 2.0 * Pi / toothCount;
	glNormal3d(-cos(angle), -sin(angle), 0.0);
	glVertex3d(r0 * cos(angle), r0 * sin(angle), +z);
	glVertex3d(r0 * cos(angle), r0 * sin(angle), -z);
    }
    glEnd();

    glEndList();

    return list;
}

void GLWidget::drawGear(GLuint gear, GLdouble dx, GLdouble dy, GLdouble dz,
                        GLdouble angle)
{
    glPushMatrix();
    glTranslated(dx, dy, dz);
    glRotated(angle, 0.0, 0.0, 1.0); //about the z-axis
    glCallList(gear);
    glPopMatrix();
}

void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}

void GLWidget::drawCube2(double l,double h,double w,int c){
    glBegin(GL_QUADS);
        // Top face (y = 1.0f)
        if(c==0){glColor3f(0.0f, 0.0f, 0.0f);}
        else{glColor3f(1.0f, 1.0f, 1.0f);}     // white
        glVertex3d( l/2, h/2, -w/2);
        glVertex3d(-l/2, h/2, -w/2);
        glVertex3d(-l/2, h/2,  w/2);
        glVertex3d( l/2, h/2,  w/2);

        // Bottom face (y = -1.0f)
        if(c==0){glColor3f(0.0f, 0.0f, 0.0f);}
        else{glColor3f(1.0f, 1.0f, 0.0f);}    // yellow
        glVertex3d( l/2, -h/2,  w/2);
        glVertex3d(-l/2, -h/2,  w/2);
        glVertex3d(-l/2, -h/2, -w/2);
        glVertex3d( l/2, -h/2, -w/2);

        // Front face  (z = 1.0f)
        if(c==0){glColor3f(0.0f, 0.0f, 0.0f);}
        else{glColor3f(1.0f, 0.0f, 0.0f);}     // red
        glVertex3d( l/2,  h/2, w/2);
        glVertex3d(-l/2,  h/2, w/2);
        glVertex3d(-l/2, -h/2, w/2);
        glVertex3d( l/2, -h/2, w/2);

        // Back face (z = -1.0f)
        if(c==0){glColor3f(0.0f, 0.0f, 0.0f);}
        else{glColor3f(1.0f, 0.647f, 0.0f);}     // orange
        glVertex3d( l/2, -h/2, -w/2);
        glVertex3d(-l/2, -h/2, -w/2);
        glVertex3d(-l/2,  h/2, -w/2);
        glVertex3d( l/2,  h/2, -w/2);

        // Left face (x = -1.0f)
        if(c==0){glColor3f(0.0f, 0.0f, 0.0f);}
        else{glColor3f(0.0f, 1.0f, 0.0f);}     // green
        glVertex3d(-l/2,  h/2,  w/2);
        glVertex3d(-l/2,  h/2, -w/2);
        glVertex3d(-l/2, -h/2, -w/2);
        glVertex3d(-l/2, -h/2,  w/2);

        // Right face (x = 1.0f)
        if(c==0){glColor3f(0.0f, 0.0f, 0.0f);}
        else{glColor3f(0.0f, 0.0f, 1.0f);}     // blue
        glVertex3d(l/2,  h/2, -w/2);
        glVertex3d(l/2,  h/2,  w/2);
        glVertex3d(l/2, -h/2,  w/2);
        glVertex3d(l/2, -h/2, -w/2);
    glEnd();
}

void GLWidget::rotating(){
    glRotated(gear1Rot / 16.0, 0.0, 0.0, 1.0);
    glRotated(gear1Rot / 16.0, 0.0, 1.0, 0.0);
}

void GLWidget::setrotating(bool r){
    isrotating=r;
}

void GLWidget::reset(){
    xRot = 0;
    yRot = 0;
    zRot = 0;
    gear1Rot = 0;
    update();
}

GLuint GLWidget::makeCube(const GLfloat *reflectance, int l,int h,int w){

    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, reflectance);

    glShadeModel(GL_FLAT);
    //glShadeModel(GL_SMOOTH);

    glBegin(GL_QUADS);
        // Top face (y = 1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3d( l/2, h/2, -w/2);
        glVertex3d(-l/2, h/2, -w/2);
        glVertex3d(-l/2, h/2,  w/2);
        glVertex3d( l/2, h/2,  w/2);

        // Bottom face (y = -1.0f)
        glColor3f(1.0f, 0.5f, 0.0f);     // Orange
        glVertex3d( l/2, -h/2,  w/2);
        glVertex3d(-l/2, -h/2,  w/2);
        glVertex3d(-l/2, -h/2, -w/2);
        glVertex3d( l/2, -h/2, -w/2);

        // Front face  (z = 1.0f)
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3d( l/2,  h/2, w/2);
        glVertex3d(-l/2,  h/2, w/2);
        glVertex3d(-l/2, -h/2, w/2);
        glVertex3d( l/2, -h/2, w/2);

        // Back face (z = -1.0f)
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3d( l/2, -h/2, -w/2);
        glVertex3d(-l/2, -h/2, -w/2);
        glVertex3d(-l/2,  h/2, -w/2);
        glVertex3d( l/2,  h/2, -w/2);

        // Left face (x = -1.0f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3d(-l/2,  h/2,  w/2);
        glVertex3d(-l/2,  h/2, -w/2);
        glVertex3d(-l/2, -h/2, -w/2);
        glVertex3d(-l/2, -h/2,  w/2);

        // Right face (x = 1.0f)
        glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
        glVertex3d(l/2,  h/2, -w/2);
        glVertex3d(l/2,  h/2,  w/2);
        glVertex3d(l/2, -h/2,  w/2);
        glVertex3d(l/2, -h/2, -w/2);
    glEnd();

    glEndList();

    return list;
}

void GLWidget::drawCube(GLuint cube, GLdouble dx, GLdouble dy, GLdouble dz,
                        GLdouble angle){
    glPushMatrix();
    glTranslated(dx, dy, dz);
    glRotated(angle, 0.0, 0.0, 1.0); //about the z-axis
    glCallList(cube);
    glPopMatrix();
}
