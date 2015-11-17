#include "GLWidget.h"
#include <QtGui>
#include <QtOpenGL>
#include <cmath>

#include <fstream>
using namespace std;

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;  
    mesh = new Mesh();
    shade = 0;
    scroll = 1.0;

    gear1Rot=0;

    isrotating=false;
    lightcolor=10;
    lighteffect=10;
    modelambient=0;
    modeldiffuse=0;
    modelspecular=0;
    modelshininess=0;
    modelemission=0;

    hasNormal=0;

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

    if(shade==1){glShadeModel(GL_FLAT);}
    else if(shade==2){glShadeModel(GL_SMOOTH);}
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
    else if(lighteffect==2){glColorMaterial(GL_FRONT, GL_DIFFUSE);}
    else if(lighteffect==10){glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);}

    glPushMatrix();
    glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0);
    rotating();

    glScaled(scroll,scroll,scroll);
    //drawMeshPoints();
    drawMeshWireframe();
    
    glPopMatrix();
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0,0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, +5.0, -5.0, 5.0, 5.0, 550.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0.0, 0.0, -100.0);
    
    updateGL();
}

void GLWidget::drawMeshWireframe()
{
    int i, j;
    int index;
    float x1, y1, z1;
    float x2, y2, z2;
    float x3, y3, z3;

    if(shade==0){glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
    else{glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);}

    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0f,0.1f,0.1f);
    glBegin(GL_TRIANGLES);
    for(i=0; i< mesh->numFaces; i++){
        for(j=0; j< mesh->face[i].nVerts-2; j++){
            index = mesh->face[i].vert[j].vertIndex;
            x1 = mesh->pt[index].x;
            y1 = mesh->pt[index].y;
            z1 = mesh->pt[index].z;

            j++;
            index = mesh->face[i].vert[j].vertIndex;
            x2 = mesh->pt[index].x;
            y2 = mesh->pt[index].y;
            z2 = mesh->pt[index].z;

            j++;
            index = mesh->face[i].vert[j].vertIndex;
            x3 = mesh->pt[index].x;
            y3 = mesh->pt[index].y;
            z3 = mesh->pt[index].z;

            if(hasNormal==1){
                double v1x = x2-x1;
                double v1y = y2-y1;
                double v1z = z2-z1;

                double v2x = x3-x1;
                double v2y = y3-y1;
                double v2z = z3-z1;

                double vnx=v1y*v2z - v1z*v2y;
                double vny=v1x*v2z - v1z*v2x;
                double vnz=v1x*v2y - v1y*v2x;

                double size=qSqrt(vnx*vnx+vny*vny+vnz*vnz);

                glNormal3d(vnx/size, vny/size, vnz/size);
            }else{
                glNormal3d(x1,y1,z1);
            }

            glVertex3d(x1,y1,z1);
            glVertex3d(x2,y2,z2);
            glVertex3d(x3,y3,z3);
        }
    }
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
}
 GLvoid GLWidget::crossProduct(float *Nx, float *Ny, float *Nz){
    GLfloat Qx, Qy, Qz, Px, Py, Pz;

    Qx = mesh->pt[0].y-mesh->pt[0].x;
    Qy = mesh->pt[1].y-mesh->pt[1].x;
    Qz = mesh->pt[2].y-mesh->pt[2].x;
    Px = mesh->pt[0].z-mesh->pt[0].x;
    Py = mesh->pt[1].z-mesh->pt[1].x;
    Pz = mesh->pt[2].z-mesh->pt[2].x;

    *Nx = Py*Qz - Pz*Qy;
    *Ny = Pz*Qx - Px*Qz;
    *Nz = Px*Qy - Py*Qx;
 }

void GLWidget::rotating(){
    //glRotated(gear1Rot / 16.0, 0.0, 0.0, 1.0);
    glRotated(gear1Rot / 16.0, 0.0, 1.0, 0.0);
    update();
}

void GLWidget::setrotating(bool r){
    isrotating=r;
    update();
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
    update();
    initializeGL();
}

void GLWidget::effect(int e){
    lighteffect=e;
    update();
    initializeGL();
}

void GLWidget::ambient(int a){
    modelambient=a;
    update();
    initializeGL();
}

void GLWidget::diffuse(int d){
    modeldiffuse=d;
    update();
    initializeGL();
}

void GLWidget::specular(int s){
    modelspecular=s;
    update();
    initializeGL();
}

void GLWidget::shininess(int sh){
    modelshininess=sh;
    update();
    initializeGL();
}

void GLWidget::emission(int e){
    modelemission=e;
    update();
    initializeGL();
}

void GLWidget::shading(int s){
    shade = s;
    update();
    initializeGL();
}

void GLWidget::normal(int n){
    hasNormal = n;
    update();
    initializeGL();
}

void GLWidget::wheelEvent(QWheelEvent *event){
    if(scroll>=0.3){scroll += (event->delta()/1200.0);}
    else{scroll=0.3;}
    qDebug() << QString::number(scroll);
    update();
}

void GLWidget::advanceGears()
{
    if(isrotating){gear1Rot += 2 * 16;}
    updateGL();
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

void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}

bool GLWidget::read_file(QString fname,QString fextension)
{
	if(fextension == "obj") {
		read_OBJ(fname);
		return true;
	}
	else{  //not supported.
		return false;
	}
	return false;
}

int GLWidget::read_OBJ(QString filename) //starting vertex idex is 1, not zero!
{

	float centerX, centerY, centerZ;
	centerX = centerY = centerZ = 0.0;
	float maxX, maxY, maxZ, minX, minY, minZ;
	minX=minY=minZ= 1000000;
	maxX=maxY=maxZ= -1000000;
	float x, y, z;
	char c;
	char buf[80];
    ifstream in_file(filename.toAscii().data());

	while( (c=in_file.get()) != EOF){

		if(c=='#'){
			in_file.getline(buf,100);
		}
		else if(c=='v' || c=='V'){
			mesh->numVerts++;
			in_file.getline(buf,100);
		}
		else if(c=='f' || c=='F'){
			mesh->numFaces++;
			in_file.getline(buf,100);
		}
	}
	
	
	if(mesh->pt) delete [] mesh->pt;
	mesh->pt= new Point3d[mesh->numVerts];
	if(mesh->face) delete [] mesh->face;
	mesh->face = new Face[mesh->numFaces];
	in_file.close();


	//------------------ building.....
    ifstream infile(filename.toAscii().data());
	int vi=0; //start vertex index is zero!
	int fi=0; //start face index is zero!
	int _v0,_v1,_v2;
	while( (c=infile.get()) != EOF){

		if(c=='#'){ 
			infile.getline(buf,100);
		}
		else if(c=='v' || c=='V'){
			infile >> x >> y >> z;

			if(x< minX) minX = x; else if(x > maxX) maxX = x;
			if(y< minY) minY = y; else if(y > maxY) maxY = y;
			if(z< minZ) minZ = z; else if(z > maxZ) maxZ = z;
	
			mesh->pt[vi] = Point3d(x, y, z);
			centerX += x;
			centerY += y;
			centerZ += z;
			vi++; //vertex index
		}
		
		else if(c=='f' || c=='F'){

			infile >> _v0 >> _v1 >> _v2;
			_v0--; _v1--; _v2--;
			VertexID  VID[3];
			VID[0].vertIndex = _v0;
			mesh->face[fi].vert[0] = VID[0];
			VID[1].vertIndex = _v1;
			mesh->face[fi].vert[1] = VID[1];
			VID[2].vertIndex = _v2;
			mesh->face[fi].vert[2] = VID[2];

			fi++; //face index
		}


	}
	infile.close();

	//normalize mesh
	centerX /= mesh->numVerts;
	centerY /= mesh->numVerts;
	centerZ /= mesh->numVerts;
	
	float maxsize = (maxX - minX);
	if((maxY - minY) > maxsize) maxsize = maxY - minY;
	if((maxZ - minZ) > maxsize)	maxsize = maxZ - minZ;	
	
	for(int i = 0; i < mesh->numVerts; i++){
		mesh->pt[i].x = ((mesh->pt[i].x - centerX) * 100.00/maxsize); 
		mesh->pt[i].y = ((mesh->pt[i].y - centerY) * 100.00/maxsize);
		mesh->pt[i].z = ((mesh->pt[i].z - centerZ) * 100.00/maxsize); 
	}
		

	return 1; //success
}

void GLWidget::drawMeshPoints()
{
	if(!mesh) return;
	int i;
	float x, y, z;
	
	glDisable(GL_LIGHTING);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for( i=0; i< mesh->numVerts; i++){			
		x= (mesh->pt[i]).x;
		y= (mesh->pt[i]).y;
		z= (mesh->pt[i]).z;
		glVertex3d(x, y, z);	
	}
	glEnd();
	glEnable(GL_LIGHTING);	
	
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
