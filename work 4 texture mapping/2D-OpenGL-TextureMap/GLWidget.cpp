#include "GLWidget.h"
#include <QtGui>
#include <QtOpenGL>
#include <QtCore/qmath.h>

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{

	textureReady = false;
}

GLWidget::~GLWidget()
{

}


void GLWidget::initializeGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //background color
    textureReady = false;
    createTexture(); //use our own texture

}

void GLWidget::resizeGL(int width, int height)
{
	//optional
	//viewport, an area of the display window.
    glViewport(0, 0, width, height);

    //optional
    //projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-415,415,-400,400,0,1); //(xmin,xmax,ymin,ymax,near,far) @ the lower left corner.
    //or using:
    //gluOrtho2D(0,100,0,100);
    //glOrtho(-100,100,-100,100,0,1); //xmin,xmax,ymin,ymax,near,far @ the center.

    //optional
    //viewing and modeling
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glTranslated(0.0, 0.0, 0.0); //position of the camera

}



void GLWidget::paintGL()
{
	glClearColor(0.9f, 0.9f, 0.8f, 1.0f); //background color
    glClear(GL_COLOR_BUFFER_BIT);

    if(textureReady){
        glLoadIdentity();
        glTranslated(0,250,0);
        drawNormal();

        glLoadIdentity();
        drawEllipse(400,200);

        glLoadIdentity();
        glTranslated(0,-250,0);
        drawEllipse(200,200);

        glLoadIdentity();
        glTranslated(-200,-250,0);
        //drawCircle(100);
    }

}


void GLWidget::drawNormal(){
    glBegin(GL_QUADS);
        // top left vertex
        glTexCoord2f(0.0f, 1.0f);
        glVertex2i(-100, 100);
        // bottom left vertex
        glTexCoord2f(0.0f, 0.0f);
        glVertex2i(-100, -100);
        // bottom right vertex
        glTexCoord2f(1.0f, 0.0f);
        glVertex2i(100, -100);
        // top right vertex
        glTexCoord2f(1.0f, 1.0f);
        glVertex2i(100, 100);
    glEnd();
}


void GLWidget::drawCircle(int r){
    int pcs = 1000;
    float a = 1.0f/pcs;
    double deg = 3.14*2/pcs;

    for(int i=0;i<pcs+1;i++){
        glBegin(GL_TRIANGLES);
            glTexCoord2f(0.0f+i*a,0.0f);
            glVertex2i(cos(i*deg)*r,sin(i*deg)*r);

            glTexCoord2f(0.0f+(i+1)*a,0.0f);

            if(i+1==pcs){glVertex2i(r,0);
            }else{glVertex2i(cos(i*deg+deg)*r,sin(i*deg+deg)*r);}

            glTexCoord2f(0.0f+(i+0.5)*a,1.0f);
            glVertex2i(0,0);
        glEnd();
    }
}

void GLWidget::drawEllipse(int w,int h){
    int pcs = 1000;

    glBegin(GL_QUADS);

    for(int i=0;i<pcs;i++){
       double y = (-h/2)+(i*h/pcs);
       double x = (1-(1.0*y*y/(h*h/4.0)))*(w*w/4);
       double x1 = -sqrt(x);
       double x2 = sqrt(x);
       double x3 = x2-x1;

       for(int j=0;j<pcs;j++){
           glTexCoord2f(1.0*j/pcs,1.0*i/pcs);
           glVertex2i(x1 + 1.0*(j)*x3/pcs, -h/2 + 1.0*(i)*h/pcs);

           glTexCoord2f(1.0*(j+1)/pcs,1.0*i/pcs);
           glVertex2i(x1 + 1.0*(j+1)*x3/pcs, -h/2 + 1.0*(i)*h/pcs);

           glTexCoord2f(1.0*(j+1)/pcs,1.0*(i+1)/pcs);
           glVertex2i(x1 + 1.0*(j+1)*x3/pcs, -h/2 + 1.0*(i+1)*h/pcs);

           glTexCoord2f(1.0*j/pcs,1.0*(i+1)/pcs);
           glVertex2i(x1 + 1.0*j*x3/pcs, -h/2 + 1.0*(i+1)*h/pcs);
       }
    }
    glEnd();

}

//create a texture from the read-in image.
void GLWidget::createTexture(QImage& img){
	image = img;

    for(int i = 0; i < image.height() ; i++){
        for(int j = 0; j < image.width() ; j++){
                QRgb rgb = image.pixel(i,j);
                myTexels[i][j][0] = qRed(rgb);
                myTexels[i][j][1] = qGreen(rgb);
                myTexels[i][j][2] = qBlue(rgb);
		}
    }

    UINT tId; //texture ID
	glGenTextures(1, &tId); // generate a unique ID for this texture
	glBindTexture(GL_TEXTURE_2D, tId); // create texture tId
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, myTexels);
	// target, level, internalFormat, width, height, border, format, type, pointer to texels

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tId); // use texture tId    

	textureReady = true;
	update();
}

//create a texture by ourself.
void GLWidget::createTexture(){

	for(int j=0; j < 256; j++){
		for(int i=0; i < 256; i++){
			if(j< 86){
				myData[i][j][0] = 255;
				myData[i][j][1] = 0;
				myData[i][j][2] = 0;
			}
			else if (j< 172){
				myData[i][j][0] = 0;
				myData[i][j][1] = 0;
				myData[i][j][2] = 0;
			}
			else{
				myData[i][j][0] = 255;
				myData[i][j][1] = 255;
				myData[i][j][2] = 0;
			}
		}
	}

    UINT tId; //texture ID
	glGenTextures(1, &tId); // generate a unique ID for this texture
	glBindTexture(GL_TEXTURE_2D, tId); // create texture tId
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, myData);
	// target, level, internalFormat, width, height, border, format, type, pointer to texels

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tId); // use texture tId

	textureReady = true;

	update();
}


