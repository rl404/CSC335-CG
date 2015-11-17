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

MyRenderWidget::MyRenderWidget(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    sec=0;
    min=0;
    hour=0;
}

MyRenderWidget::~MyRenderWidget()
{

}


void MyRenderWidget::paintEvent(QPaintEvent * /*event*/ )
{
    QPainter painter;
    painter.begin(this);
    
    QColor color(0,0,0,255);
    QMatrix m,n;

    QString secstr = QString::number(sec);
    QString minstr = QString::number(min);
    QString hourstr = QString::number(hour);

    QFont font("Arial",12);
    painter.setFont(font);
    painter.drawText(200,75,hourstr);
    painter.drawText(250,75,minstr);
    painter.drawText(300,75,secstr);
	
    //Shadow
    m.reset();
    m.translate(90,420);
    m.rotate(-35);
    m.shear(1,0.2);
    m.scale(0.5,0.5);

    painter.setMatrix(m);
    painter.setPen(Qt::gray);
    painter.setBrush(QColor(138, 121, 93,255));
    painter.drawEllipse(100,100,300,300);

    //Background
    m.reset();
    painter.setMatrix(m);
    painter.setPen(QColor(0,0,0,255));
    painter.setBrush(QColor(16,23,33,255));
    painter.drawEllipse(100,100,300,300);

    m.scale(0.8,0.8);
    painter.setMatrix(m);
    painter.setBrush(QColor(188,237,241,255));
    painter.drawEllipse(165,163,300,300);    

    //Number
    QPoint rotatedPoint;
    painter.setMatrix(m);
    for(int deg = 1; deg < 13; deg++){
        m.reset();
        m.translate(146,155);
        m.rotate(deg*30-135);

        rotatedPoint = QPoint(97,97)* m;
        n.reset();
        n.translate(rotatedPoint.x(), rotatedPoint.y());

        painter.setMatrix(n);
        painter.setPen(QColor(245,146,55,255));

        QString hour = QString::number(deg);
        QFont font("Arial",12);
        painter.setFont(font);
        painter.drawText(100,100,hour);
    }

    //Second Hand
    m.reset();
    m.translate(250,250);
    m.rotate(180+6*sec);
    m.translate(-100,-100);

    painter.setMatrix(m);
    painter.setPen(QColor(245,146,55,255));
    painter.drawLine(99,100,99,220);

    //Minute Hand
    m.reset();
    m.translate(250,250);
    m.rotate(-90+6*min);
    m.translate(-100,-100);

    painter.setMatrix(m);
    painter.setPen(QColor(245,146,55,255));
    painter.setBrush(QColor(245,146,55,255));
    painter.drawRect(100,100,130,5);

    //Hour Hand
    m.reset();
    m.translate(250,250);
    m.rotate(-90+30*hour+0.5*min);
    m.translate(-100,-100);

    painter.setMatrix(m);
    painter.setPen(QColor(245,146,55,255));
    painter.setBrush(QColor(245,146,55,255));
    painter.drawRect(100,100,100,10);
	
    //Center dot
    m.reset();
    painter.setMatrix(m);
    painter.setPen(QColor(0,0,0,255));
    painter.setBrush(QColor(16,23,33,255));
    painter.drawEllipse(245,245,20,20);

	painter.end();		
}

void MyRenderWidget::reset(){
    sec=0;min=0;hour=0;
    update();
}

void MyRenderWidget::random(){
    sec = qrand() % 60;
    min = qrand() % 60;
    hour = qrand() % 12;
    update();
}






