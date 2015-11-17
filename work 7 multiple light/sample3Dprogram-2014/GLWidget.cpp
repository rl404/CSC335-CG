#include "GLWidget.h"
#include <QtGui>
#include <QtOpenGL>
#include <cmath>
#include <GL/glu.h>


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    initializeGL();
    xRot = 0;
    yRot = 0;
    zRot = 0;

    gear1Rot=0;

    isrotating=false;
    lightcolor=10;
    lighteffect=0;
    modelambient=0;
    modeldiffuse=0;
    modelspecular=0;
    modelshininess=0;
    modelemission=0;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceGears()));
    timer->start(80);
}

GLWidget::~GLWidget()
{
    makeCurrent();
}

void GLWidget::initializeGL()
{
    //glClearColor(0.878f, 1.000f, 1.000f, 0.0f); //background color
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    //light properties
    float red,green,blue;
    if(lightcolor==1 || lightcolor==10){red=1.0f;}else{red=0.0f;}
    if(lightcolor==2 || lightcolor==10){green=1.0f;}else{green=0.0f;}
    if(lightcolor==3 || lightcolor==10){blue=1.0f;}else{blue=0.0f;}
    if(lightcolor==0){red=0.0f;green=0.0f;blue=0.0f;}

    float diffuse0[]  = {red, green, blue, 1.0f};
    float ambient0[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float specular0[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float position0[] = {6.0f, 6.0f, 6.0f, 0.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
    glLightfv(GL_LIGHT0, GL_POSITION, position0);

    //light model properties
    float model_ambient[] = {0.4f, 0.4f, 0.4f, 1.0f};
    int model_two_side = 1;                                //0=2sided, 1=1sided
    int viewpoint = 0;

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);     //small white ambient light
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, viewpoint);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, model_two_side);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    glEnable(GL_DEPTH_TEST); //important
    glEnable(GL_NORMALIZE);

    glShadeModel(GL_SMOOTH); //a default value
    //glShadeModel(GL_FLAT); //flat shading
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //material
    float ambient0[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float ambient1[] = {0.7f, 0.7f, 0.7f, 1.0f};
    float ambient2[] = {0.8f, 0.8f, 0.2f, 1.0f};

    float diffuse0[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float diffuse1[] = {0.1f, 0.5f, 0.8f, 1.0f};

    float specular0[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float specular1[] = {1.0f, 1.0f, 1.0f, 1.0f};

    float shininess0 = 0.0f;
    float shininess1 = 5.0f;
    float shininess2 = 100.0f;

    float emission0[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float emission1[] = {0.3f, 0.2f, 0.2f, 0.0f};

    //ambient
    if(modelambient==0){        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient0);}
    else if(modelambient==1){   glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);}
    else{                       glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);}

    //diffuse
    if(modeldiffuse==0){        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse0);}
    else{                       glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse1);}

    //specular
    if(modelspecular==0){       glMaterialfv(GL_FRONT, GL_SPECULAR, specular0);}
    else{                       glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);}

    //shininess
    if(modelshininess==0){      glMaterialf(GL_FRONT, GL_SHININESS, shininess0);}
    else if(modelshininess==1){ glMaterialf(GL_FRONT, GL_SHININESS, shininess1);}
    else{                       glMaterialf(GL_FRONT, GL_SHININESS, shininess2);}

    //emission
    if(modelemission==0){       glMaterialfv(GL_FRONT, GL_EMISSION, emission0);}
    else{                       glMaterialfv(GL_FRONT, GL_EMISSION, emission1);}

    //effect
    if(lighteffect==1){ glColorMaterial(GL_FRONT, GL_AMBIENT);}
    else if(lighteffect==2){ glColorMaterial(GL_FRONT, GL_DIFFUSE);}
    else if(lighteffect==10){glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);}

    //SNOWMAN --------------------------------------------------------------------------------
    GLUquadricObj *quadric;
    quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL );

    glEnable(GL_COLOR_MATERIAL);

    glPushMatrix();
    glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0);
    rotating();

    //head
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f,4.0f,0.0f);
    gluSphere(quadric, 1.0f, 50, 50);

    //left eyes
    glColor3f(0.0f, 0.0f, 0.0f );
    glTranslatef(0.3f,0.3f,1.0f);
    gluSphere(quadric, 0.15f, 50, 50);
    glTranslatef(-0.3f,-0.3f,-1.0f);

    //right eyes
    glColor3f(0.0f, 0.0f, 0.0f );
    glTranslatef(-0.3f,0.3f,1.0f);
    gluSphere(quadric, 0.15f, 50, 50);
    glTranslatef(0.3f,-0.3f,-1.0f);

    //nose
    glColor3f(1.0f, 0.549f, 0.0f);
    glTranslatef(0.0f,0.0f,1.0f);
    drawCylinder(1.0f,0.2f,0.01f,50,50);

    //body
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f,-2.5f,-1.0f);
    gluSphere(quadric, 2.0f, 50, 50);

    //button
    glColor3f(0.0f, 0.0f, 0.0f );
    glTranslatef(0.0f,1.0f,1.7f);
    gluSphere(quadric, 0.2f, 50, 50);
    glTranslatef(0.0f,-1.0f,0.3f);
    gluSphere(quadric, 0.2f, 50, 50);
    glTranslatef(0.0f,-1.0f,-0.3f);
    gluSphere(quadric, 0.2f, 50, 50);
    glTranslatef(0.0f,1.0f,-1.7f);

    //left hand
    glColor3f(0.545f, 0.271f, 0.075f);
    glTranslatef(1.5f,1.0f,0.0f);
    glRotated(90,0.0,1.0,0.0);
    glRotated(-30,1.0,0.0,0.0);
    drawCylinder(2.5f,0.2f,0.2,50,50);
    glRotated(30,1.0,0.0,0.0);
    glRotated(-90,0.0,1.0,0.0);

    //right hand
    glTranslatef(-3.0f,0.0f,0.0f);
    glRotated(-90,0.0,1.0,0.0);
    glRotated(-30,1.0,0.0,0.0);
    drawCylinder(2.5f,0.2f,0.2,50,50);
    glRotated(30,1.0,0.0,0.0);
    glRotated(90,0.0,1.0,0.0);

    //bottom
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(1.5f,-5.0f,0.0f);
    gluSphere(quadric, 3.0f, 50, 50);

    glPopMatrix();

    //hat
    glColor3f(0.0f, 0.0f, 1.0f );
    glPushMatrix();
    glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0);
    rotating();

    glTranslatef(0.0f,6.0f,0.0f);
    glRotatef(90,1.0,0.0,0.0);
    drawCylinder(1.25f, 0.8f, 0.7f, 50,50);

    glTranslatef(0.0f,0.0f,1.15f);
    drawCylinder(0.1f, 1.2f, 1.2f, 50,50);

    glPopMatrix();

    glDisable(GL_COLOR_MATERIAL);
}

void GLWidget::rotating(){
    //glRotated(gear1Rot / 16.0, 0.0, 0.0, 1.0);
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

void GLWidget::color(int c){
    lightcolor=c;
    initializeGL();
}

void GLWidget::effect(int e){
    lighteffect=e;
    initializeGL();
}

void GLWidget::ambient(int a){
    modelambient=a;
    initializeGL();
}

void GLWidget::diffuse(int d){
    modeldiffuse=d;
    initializeGL();
}

void GLWidget::specular(int s){
    modelspecular=s;
    initializeGL();
}

void GLWidget::shininess(int sh){
    modelshininess=sh;
    initializeGL();
}

void GLWidget::emission(int e){
    modelemission=e;
    initializeGL();
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

void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}

void GLWidget::drawSnowman(){

}

void GLWidget::drawCylinder(float h, float rb, float rt, float s1, float s2){
    GLUquadricObj *quadric;
    quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL );

    gluCylinder(quadric,rb,rt,h,s1,s2);

    //top
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, h);
    gluDisk(quadric, 0.0, rt, s1,s2);
    glPopMatrix();

    //bottom
    glPushMatrix();
    glRotatef(180, 1.0f, 0.0f, 0.0f);
    gluDisk(quadric, 0.0, rb, s1,s2);
    glPopMatrix();
}



