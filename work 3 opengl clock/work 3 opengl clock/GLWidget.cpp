#include "GLWidget.h"
#include <windows.h>
#include <QtGui>
#include <QtOpenGL>

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    sec=0;min=0;hour=0;
}

GLWidget::~GLWidget()
{

}


void GLWidget::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //background color
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-315,315,-300,300,0,1);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::paintGL()
{
    glClearColor(0.847f, 0.749f, 0.847f, 0.0f); //background color
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    //Background
    glColor3f(0.502f, 0.000f, 0.502f);
    drawCircle(200);

    glColor3f(0.0f, 0.0f, 0.0f);
    glScaled(0.8,0.8,1);
    drawCircle(200);

    glColor3f(0.980f, 0.502f, 0.447f);
    drawNumber();

    //Second Hand
    glLoadIdentity();
    glColor3f(0.980f, 0.502f, 0.447f);
    glRotated(-6*sec,0,0,1);
    drawRec(160,1);

    //Minute Hand
    glLoadIdentity();
    glColor3f(0.980f, 0.502f, 0.447f);
    glRotated(-6*min,0,0,1);
    drawRec(170,5);

    //Hour Hand
    glLoadIdentity();
    glColor3f(0.980f, 0.502f, 0.447f);
    glRotated(-30*hour-0.5*min,0,0,1);
    drawRec(130,8);

    //Center dot
    glLoadIdentity();
    glColor3f(0.502f, 0.000f, 0.502f);
    drawCircle(10);



//    glPushMatrix();
//    glPopMatrix();
}

void GLWidget::drawCube(){
    //glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0,0);
    glVertex2i(0,20);
    glVertex2i(10,30);
    glVertex2i(10,10);
    glVertex2i(0,0);
    glVertex2i(20,0);
    glVertex2i(30,10);
    glVertex2i(10,10);
    glVertex2i(10,30);
    glVertex2i(30,30);
    glVertex2i(30,10);
    glVertex2i(20,0);
    glVertex2i(20,20);
    glVertex2i(30,30);
    glVertex2i(20,20);
    glVertex2i(0,20);
    glEnd();
}

void GLWidget::drawNumber(){
    for(int deg = 1;deg<61;deg++){
        glLoadIdentity();
        glRotated(deg*6,0,0,1);
        glTranslated(0,165,0);
        drawRec(10,1);
    }

    for(int deg = 1;deg<13;deg++){
        glLoadIdentity();
        glRotated(deg*30,0,0,1);
        glTranslated(0,160,0);
        if(deg%3==0)
            drawRec(30,7);
        drawRec(10,3);
    }
}

void GLWidget::drawRec(int h,int w){

    glBegin(GL_QUADS); //different color at each vertex
        glVertex2i(0-w/2,0);
        glVertex2i(0-w/2,h);
        glVertex2i(w-w/2,h);
        glVertex2i(w-w/2,0);
    glEnd();
}

void GLWidget::drawCircle(int radius){
    double twicePi = 2.0f * 3.14;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0,0); // center of circle
        for(int i = 0; i <= 101;i++) {
            glVertex2f(
                (radius * cos(i *  twicePi / 100)),
                (radius * sin(i * twicePi / 100))
            );
        }
    glEnd();
}

void GLWidget::reset(){
    sec=0;  min=0;  hour=0;
    update();
}

void GLWidget::set(int s,int m,int h){
    sec=s;  min=m;  hour=h;
    update();
}

