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

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMessageBox>

#include <QtGui>
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	myWindowTitle = "sample 2D program ";
    setWindowTitle(myWindowTitle);
    resize(800, 500);
    
    centralWidget = new QWidget;
    setCentralWidget(centralWidget);	

    myWidget = new MyRenderWidget;
    myWidget->setFocusPolicy(Qt::StrongFocus); //for a keyboard press!
    
    
    QGridLayout *centralLayout = new QGridLayout;
    centralLayout->addWidget(myWidget, 0, 0,1,1);
    centralWidget->setLayout(centralLayout);
    
	createActions();
	createMenus();
}

MainWindow::~MainWindow()
{

}


void MainWindow::createActions()
{
	saveAct = new QAction("&Save", this);
	saveAct->setStatusTip("Save as *.crv file");
	connect(saveAct, SIGNAL(triggered()), this, SLOT(saveCRVfile()));

	exitAct = new QAction("E&xit", this);
	exitAct->setStatusTip("Quit this program");
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
  
    controlPointsShownAct = new QAction("&Shown", this);
    controlPointsShownAct->setStatusTip("Show control points");
    controlPointsShownAct->setCheckable(true);
    connect(controlPointsShownAct, SIGNAL(triggered()), this, SLOT(showInputData()));
    
    controlPointsHiddenAct = new QAction("&Hidden", this);
    controlPointsHiddenAct->setStatusTip("Hide control points");
    controlPointsHiddenAct->setCheckable(true);
    connect(controlPointsHiddenAct, SIGNAL(triggered()), this, SLOT(hideInputData()));
      
    controlPointsGroup = new QActionGroup(this);
    controlPointsGroup->addAction(controlPointsShownAct);
    controlPointsGroup->addAction(controlPointsHiddenAct);
    controlPointsShownAct->setChecked(true);

    bezierShownAct = new QAction("&Shown", this);
    bezierShownAct->setStatusTip("Show Bezier curve");
    bezierShownAct->setCheckable(true);
    connect(bezierShownAct, SIGNAL(triggered()), this, SLOT(showBezier()));

    bezierHiddenAct = new QAction("&Hidden", this);
    bezierHiddenAct->setStatusTip("Hide Bezier curve");
    bezierHiddenAct->setCheckable(true);
    connect(bezierHiddenAct, SIGNAL(triggered()), this, SLOT(hideBezier()));

    bezierGroup = new QActionGroup(this);
    bezierGroup->addAction(bezierShownAct);
    bezierGroup->addAction(bezierHiddenAct);
    bezierShownAct->setChecked(true);

   
    clearAct = new QAction("&Clear", this);
    clearAct->setStatusTip("Clear a display");
    connect(clearAct, SIGNAL(triggered()), this, SLOT(clearDisplay()));

    aboutAct = new QAction("&About", this);
    aboutAct->setStatusTip("About this program");
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    
    usageAct = new QAction("&Usage", this);
    usageAct->setStatusTip("How to control via mouse and keyboard.");
    connect(usageAct, SIGNAL(triggered()), this, SLOT(usage()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
       
    optionsMenu = menuBar()->addMenu("&Options");
 
    controlPointsMenu = optionsMenu->addMenu("&Control Points");
    controlPointsMenu->addAction(controlPointsShownAct);
    controlPointsMenu->addAction(controlPointsHiddenAct);

    bezierMenu = optionsMenu->addMenu("&Bezier Curve");
    bezierMenu->addAction(bezierShownAct);
    bezierMenu->addAction(bezierHiddenAct);
   
    
    optionsMenu->addAction(clearAct);
    
    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(usageAct);

}




void MainWindow::saveCRVfile()
{	
    QMessageBox::about(this, "Not implemented yet ",
            "Not implemented yet!");
}


void MainWindow::clearDisplay()
{
	myWidget->clearAndIntializeData();
}


void MainWindow::about()
{
    QMessageBox::about(this, "About sample 2D program ",
            "This sample program is implemented with "
            "Qt and C++.\n\n" 
            "P. Mongkolnam, 2011\n\n"
            "Modified by Axel 56130500236\n");

}

void MainWindow::usage()
{
    QMessageBox::about(this, "How to control ",

    		"     -Double click anywhere to generate the control points.\n"
    		"     -Double click on the existing control points to delete them.\n"
    		"     -Press and hold a mouse button on the control point and move\n"
    		"      the mouse to move the control point.\n"
    		"     -Press and hold a mouse button on any control point and move the mouse\n"
    		"      while pressing down the Ctr key or Space key to translate\n"
    		"      all the control points altogether.\n");

}


void MainWindow::showInputData()
{
	myWidget->showControlPoints();
}

void MainWindow::hideInputData()
{
	myWidget->hideControlPoints();
}

void MainWindow::showBezier()
{
    myWidget->showBezier();
}

void MainWindow::hideBezier()
{
    myWidget->hideBezier();
}



