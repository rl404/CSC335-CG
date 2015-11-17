/****************************************************************************
**
** Trolltech hereby grants a license to use the Qt/Eclipse Integration
** plug-in (the software contained herein), in binary form, solely for the
** purpose of creating code to be used with Trolltech's Qt software.
**
** Qt Designer is licensed under the terms of the GNU General Public
** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
** right to use certain no GPL licensed software under the terms of its GPL
** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
**
** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** Since we now have the GPL exception I think that the "special exception
** is no longer needed. The license text proposed above (other than the
** special exception portion of it) is the BSD license and we have added
** the BSD license as a permissible license under the exception.
**
****************************************************************************/

#include "MyRenderWidget.h"
#include <QtGui>
#include <fstream>
#include <QPen>
#include <QPainter>
#include <math.h>


MyRenderWidget::MyRenderWidget(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);
	
	translateRotateKeyPressed = false;
	controlPointsShown = true;
    bezierShown = true;
	found_index= -1;
}

MyRenderWidget::~MyRenderWidget()
{

}


void MyRenderWidget::paintEvent(QPaintEvent * /*event*/ )
{
    QPainter painter;
    painter.begin(this);
    
    QColor color(0,0,0,255);
    //painter.setPen(color);
	int i;
    int x1, x2, y1, y2;
	
	if(controlPointsShown){
		painter.setPen(Qt::green);
        for( i=0; i < ControlPoints.size(); i++){
            painter.drawEllipse(ControlPoints[i], 5, 5);
		}
        painter.setPen(Qt::red);
		for( i=0; i < ControlPoints.size()-1; i++){
			x1 = ControlPoints[i].x();
			y1 = ControlPoints[i].y();
			x2 = ControlPoints[i+1].x();
			y2 = ControlPoints[i+1].y();
			painter.drawLine(x1,y1,x2,y2);
		}
	}

    if(bezierShown){
        if(!controlPointsShown){
            painter.setPen(Qt::yellow);
            for( i=0; i < ControlPoints.size(); i++){
                painter.drawEllipse(ControlPoints[i], 5, 5);
            }
        }

        painter.setPen(Qt::blue);
        for( double t=0.0; t <= 1; t += 0.01){
            painter.drawLine(cx(t),cy(t), cx(t+0.01),cy(t+0.01));
            //painter.drawPoint(cx(t), cy(t));
        }
    }
			
	painter.end();		
}

double MyRenderWidget::cx(double t){
    double  c = 0;
    for(int i = 0;i <ControlPoints.size();i++){
        c = c + (ControlPoints[i].x() * bernstein(i,ControlPoints.size()-1,t));
    }
    return c;
}

double MyRenderWidget::cy(double t){
    double  c = 0;
    for(int i = 0;i <ControlPoints.size();i++){
        c = c + (ControlPoints[i].y() * bernstein(i,ControlPoints.size()-1,t));
    }
    return c;
}

double MyRenderWidget::fact(double n){
    double  a = 1;
    while(n>0){
        a = a * n;
        n--;
    }
    return a;
}

double MyRenderWidget::bernstein(double i,double n,double t){
    double a = fact(n)/(fact(n-i)*fact(i));
    double b = a * pow(t,i) * pow((1-t),(n-i));
    return b;
}

void MyRenderWidget::keyPressEvent(QKeyEvent *event)
{
	switch(event->key()){
	case Qt::Key_Control:
	case Qt::Key_Alt:
	case Qt::Key_Shift:
	case Qt::Key_Space:
		translateRotateKeyPressed = true;
		break;
	default:
		break;
	}
}

void MyRenderWidget::keyReleaseEvent(QKeyEvent *event)
{
	translateRotateKeyPressed = false;	
}


void MyRenderWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	int epsilon= 10;
	QPoint point;
	double trueLength;
	
	found_index= -1;
    lastPos = event->pos();
    for(int i=0; i < ControlPoints.size(); i++){
    	point = ControlPoints[i] - lastPos;
    	trueLength = sqrt(pow(point.x(), 2) + pow(point.y(), 2));
    	if (trueLength < epsilon){
    		found_index = i;
    		break;
    	}
    }
    
    if(found_index == -1){
    	ControlPoints.append(lastPos);   	
    }
    else{
    	ControlPoints.remove(found_index); 	
    }
    
    update();	//important
}


void MyRenderWidget::mousePressEvent(QMouseEvent *event)
{
	int epsilon= 10;
	QPoint point;
	double trueLength;
	
	found_index= -1;
    lastPos = event->pos();
        
    for(int i=0; i < ControlPoints.size(); i++){
    	point = ControlPoints[i] - lastPos;
    	trueLength = sqrt(pow(point.x(), 2) + pow(point.y(), 2));
    	if (trueLength < epsilon){
    		found_index = i;
    		break;
    	}
    }
    update();   //important
}


void MyRenderWidget::mouseReleaseEvent(QMouseEvent *event)
{  
	lastPos = event->pos();  
	update(); //important
}


void MyRenderWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
   
	if(found_index == -1) return;   
    if(translateRotateKeyPressed){
 	   if (event->buttons() & Qt::RightButton){
 		   ;//for future rotation
 	   }
 	   else if(event->buttons() & Qt::LeftButton){
 		   setTranslation(-dx,-dy,0);
 	   }
    } 
    else{
	    ControlPoints.replace(found_index, lastPos);
    }

    
    lastPos = event->pos();  
    
    update();  //important 
}


void MyRenderWidget::setTranslation(int dx,int dy,int dz){
	
	QPoint point(dx,dy);
    for(int i=0; i < ControlPoints.size(); i++){
    	ControlPoints[i]= ControlPoints[i] - point;
    }
}


//-------------------------

void MyRenderWidget::clearAndIntializeData()
{
	ControlPoints.clear();
	update();
}



bool MyRenderWidget::writeOutputData(QString filename)
{		

	return true;
}



void MyRenderWidget::showControlPoints()
{

	controlPointsShown = true;
	update();
}

void MyRenderWidget::hideControlPoints()
{

	controlPointsShown = false;
	update();
}

void MyRenderWidget::showBezier()
{

    bezierShown = true;
    update();
}

void MyRenderWidget::hideBezier()
{

    bezierShown = false;
    update();
}



