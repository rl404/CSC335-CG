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
#include <QtGui>
#include "glwidget.h"
#include "mainwindow.h"
#include "statdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	createActions();
	createMenus();

    setWindowTitle("Sample 3D mesh program");
    resize(600, 600);

    centralWidget = new QWidget;
    setCentralWidget(centralWidget);
	glWidget = new GLWidget;

    glWidgetArea = new QScrollArea;
    glWidgetArea->setWidget(glWidget);
    glWidgetArea->setWidgetResizable(true);
    glWidgetArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    glWidgetArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    glWidgetArea->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    glWidgetArea->setMinimumSize(250, 250);

    statWidget = new StatWidget();

    QGridLayout *centralLayout = new QGridLayout;
    centralLayout->addWidget(glWidgetArea, 0, 0,5,5);
    centralLayout->addWidget(statWidget, 2,5,1,1);
    centralWidget->setLayout(centralLayout);
}

MainWindow::~MainWindow()
{

}

void MainWindow::openAndReadFile()
{
	QString fileName;
	fileName = QFileDialog::getOpenFileName(this,
	       "Open Obj", "d:/", "Obj Files (*.obj)");

	if(fileName.isEmpty()) return;
	bool successful_open;
	successful_open= glWidget->read_file(fileName,"obj");

	int nF = glWidget->mesh->numFaces;
	int nV = glWidget->mesh->numVerts;
	statWidget->display_stat(nV, nF);

}


void MainWindow::about()
{
	QMessageBox::about(this, "About Sample 3D mesh program",
        "The Sample 3D mesh, using "
        "OpenGL, Qt and C++.\n\n"
        "P. Mongkolnam, 2015\n\n"
        "Modified by Axel 56130500236.");
}


void MainWindow::createActions()
{
	openAct = new QAction("&Open", this);
	connect(openAct, SIGNAL(triggered()), this, SLOT(openAndReadFile()));

	exitAct = new QAction("E&xit", this);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction("&About", this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    statAct = new QAction("&Stat", this);
    connect(statAct, SIGNAL(triggered()), this, SLOT(showStat()));

    resetAct = new QAction("&Reset position", this);
    resetAct->setStatusTip("Reset the position");
    connect(resetAct, SIGNAL(triggered()), this, SLOT(reset()));

    reseteffectAct = new QAction("&Reset", this);
    reseteffectAct->setStatusTip("Reset all material");
    connect(reseteffectAct, SIGNAL(triggered()), this, SLOT(reseteffect()));

    //ANIMATION-----------------------------------------------------
    animationShownAct = new QAction("&Shown", this);
    animationShownAct->setStatusTip("Show animation");
    animationShownAct->setCheckable(true);
    connect(animationShownAct, SIGNAL(triggered()), this, SLOT(showAnimation()));

    animationHiddenAct = new QAction("&Hidden", this);
    animationHiddenAct->setStatusTip("Hide animation");
    animationHiddenAct->setCheckable(true);
    connect(animationHiddenAct, SIGNAL(triggered()), this, SLOT(hideAnimation()));

    animationGroup = new QActionGroup(this);
    animationGroup->addAction(animationShownAct);
    animationGroup->addAction(animationHiddenAct);
    animationHiddenAct->setChecked(true);

    //COLOR-----------------------------------------------------
    color0Act = new QAction("&No light",this);
    color0Act->setStatusTip("No light");
    color0Act->setCheckable(true);
    connect(color0Act, SIGNAL(triggered()), this, SLOT(color0()));

    color1Act = new QAction("&Red",this);
    color1Act->setStatusTip("Red");
    color1Act->setCheckable(true);
    connect(color1Act, SIGNAL(triggered()), this, SLOT(color1()));

    color2Act = new QAction("&Green",this);
    color2Act->setStatusTip("Green");
    color2Act->setCheckable(true);
    connect(color2Act, SIGNAL(triggered()), this, SLOT(color2()));

    color3Act = new QAction("&Blue",this);
    color3Act->setStatusTip("Blue");
    color3Act->setCheckable(true);
    connect(color3Act, SIGNAL(triggered()), this, SLOT(color3()));

    color10Act = new QAction("&White",this);
    color10Act->setStatusTip("White");
    color10Act->setCheckable(true);
    connect(color10Act, SIGNAL(triggered()), this, SLOT(color10()));

    colorGroup = new QActionGroup(this);
    colorGroup->addAction(color0Act);
    colorGroup->addAction(color1Act);
    colorGroup->addAction(color2Act);
    colorGroup->addAction(color3Act);
    colorGroup->addAction(color10Act);
    color10Act->setChecked(true);

    //EFFECT-----------------------------------------------------
    effect0Act = new QAction("&No effect",this);
    effect0Act->setStatusTip("No effect");
    effect0Act->setCheckable(true);
    connect(effect0Act, SIGNAL(triggered()), this, SLOT(effect0()));

    effect1Act = new QAction("&Ambient",this);
    effect1Act->setStatusTip("Ambient");
    effect1Act->setCheckable(true);
    connect(effect1Act, SIGNAL(triggered()), this, SLOT(effect1()));

    effect2Act = new QAction("&Diffuse",this);
    effect2Act->setStatusTip("Diffuse");
    effect2Act->setCheckable(true);
    connect(effect2Act, SIGNAL(triggered()), this, SLOT(effect2()));

    effect10Act = new QAction("&All",this);
    effect10Act->setStatusTip("All effect");
    effect10Act->setCheckable(true);
    connect(effect10Act, SIGNAL(triggered()), this, SLOT(effect10()));

    effectGroup = new QActionGroup(this);
    effectGroup->addAction(effect0Act);
    effectGroup->addAction(effect1Act);
    effectGroup->addAction(effect2Act);
    effectGroup->addAction(effect10Act);
    effect10Act->setChecked(true);

    //AMBIENT-----------------------------------------------------
    ambient0Act = new QAction("&No Ambient",this);
    ambient0Act->setStatusTip("No Ambient");
    ambient0Act->setCheckable(true);
    connect(ambient0Act, SIGNAL(triggered()), this, SLOT(ambient0()));

    ambient1Act = new QAction("&Ambient",this);
    ambient1Act->setStatusTip("Ambient");
    ambient1Act->setCheckable(true);
    connect(ambient1Act, SIGNAL(triggered()), this, SLOT(ambient1()));

    ambient2Act = new QAction("&Ambient Color",this);
    ambient2Act->setStatusTip("Ambient Color");
    ambient2Act->setCheckable(true);
    connect(ambient2Act, SIGNAL(triggered()), this, SLOT(ambient2()));

    ambientGroup = new QActionGroup(this);
    ambientGroup->addAction(ambient0Act);
    ambientGroup->addAction(ambient1Act);
    ambientGroup->addAction(ambient2Act);
    ambient0Act->setChecked(true);

    //DIFFUSE-----------------------------------------------------
    diffuse0Act = new QAction("&No Diffuse",this);
    diffuse0Act->setStatusTip("No Diffuse");
    diffuse0Act->setCheckable(true);
    connect(diffuse0Act, SIGNAL(triggered()), this, SLOT(diffuse0()));

    diffuse1Act = new QAction("&Diffuse",this);
    diffuse1Act->setStatusTip("Diffuse");
    diffuse1Act->setCheckable(true);
    connect(diffuse1Act, SIGNAL(triggered()), this, SLOT(diffuse1()));

    diffuseGroup = new QActionGroup(this);
    diffuseGroup->addAction(diffuse0Act);
    diffuseGroup->addAction(diffuse1Act);
    diffuse0Act->setChecked(true);

    //SPECULAR-----------------------------------------------------
    specular0Act = new QAction("&No Specular",this);
    specular0Act->setStatusTip("No Specular");
    specular0Act->setCheckable(true);
    connect(specular0Act, SIGNAL(triggered()), this, SLOT(specular0()));

    specular1Act = new QAction("&Specular",this);
    specular1Act->setStatusTip("Specular");
    specular1Act->setCheckable(true);
    connect(specular1Act, SIGNAL(triggered()), this, SLOT(specular1()));

    specularGroup = new QActionGroup(this);
    specularGroup->addAction(specular0Act);
    specularGroup->addAction(specular1Act);
    specular0Act->setChecked(true);

    //SPECULAR-----------------------------------------------------
    shininess0Act = new QAction("&No Shininess",this);
    shininess0Act->setStatusTip("No Shininess");
    shininess0Act->setCheckable(true);
    connect(shininess0Act, SIGNAL(triggered()), this, SLOT(shininess0()));

    shininess1Act = new QAction("&Low Shininess",this);
    shininess1Act->setStatusTip("Low Shininess");
    shininess1Act->setCheckable(true);
    connect(shininess1Act, SIGNAL(triggered()), this, SLOT(shininess1()));

    shininess2Act = new QAction("&High Shininess",this);
    shininess2Act->setStatusTip("High Shininess");
    shininess2Act->setCheckable(true);
    connect(shininess2Act, SIGNAL(triggered()), this, SLOT(shininess2()));

    shininessGroup = new QActionGroup(this);
    shininessGroup->addAction(shininess0Act);
    shininessGroup->addAction(shininess1Act);
    shininessGroup->addAction(shininess2Act);
    shininess0Act->setChecked(true);

    //EMISSION-----------------------------------------------------
    emission0Act = new QAction("&No Emission",this);
    emission0Act->setStatusTip("No Emission");
    emission0Act->setCheckable(true);
    connect(emission0Act, SIGNAL(triggered()), this, SLOT(emission0()));

    emission1Act = new QAction("&Emission",this);
    emission1Act->setStatusTip("eEmission");
    emission1Act->setCheckable(true);
    connect(emission1Act, SIGNAL(triggered()), this, SLOT(emission1()));

    emissionGroup = new QActionGroup(this);
    emissionGroup->addAction(emission0Act);
    emissionGroup->addAction(emission1Act);
    emission0Act->setChecked(true);

    //SHADING-------------------------------------------------
    shading0Act = new QAction("&No shading", this);
    shading0Act->setStatusTip("No shading");
    shading0Act->setCheckable(true);
    connect(shading0Act, SIGNAL(triggered()), this, SLOT(shading0()));

    shading1Act = new QAction("&Flat shading", this);
    shading1Act->setStatusTip("Flat shading");
    shading1Act->setCheckable(true);
    connect(shading1Act, SIGNAL(triggered()), this, SLOT(shading1()));

    shading2Act = new QAction("&Smooth shading", this);
    shading2Act->setStatusTip("Smooth shading");
    shading2Act->setCheckable(true);
    connect(shading2Act, SIGNAL(triggered()), this, SLOT(shading2()));

    shadingGroup = new QActionGroup(this);
    shadingGroup->addAction(shading0Act);
    shadingGroup->addAction(shading1Act);
    shadingGroup->addAction(shading2Act);
    shading0Act->setChecked(true);

    //NORMAL----------------------------------------------------
    normal0Act = new QAction("&No normal",this);
    normal0Act->setStatusTip("No normal");
    normal0Act->setCheckable(true);
    connect(normal0Act, SIGNAL(triggered()), this, SLOT(normal0()));

    normal1Act = new QAction("&normal",this);
    normal1Act->setStatusTip("Has normal");
    normal1Act->setCheckable(true);
    connect(normal1Act, SIGNAL(triggered()), this, SLOT(normal1()));

    normalGroup = new QActionGroup(this);
    normalGroup->addAction(normal0Act);
    normalGroup->addAction(normal1Act);
    normal0Act->setChecked(true);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionsMenu = menuBar()->addMenu("&Options");
    optionsMenu->addAction(resetAct);

    normalMenu = optionsMenu->addMenu("&Normal");
    normalMenu->addAction(normal0Act);
    normalMenu->addAction(normal1Act);

    shadingMenu = optionsMenu->addMenu("&Shading");
    shadingMenu->addAction(shading0Act);
    shadingMenu->addAction(shading1Act);
    shadingMenu->addAction(shading2Act);


    animationMenu = optionsMenu->addMenu("&Animation");
    animationMenu->addAction(animationShownAct);
    animationMenu->addAction(animationHiddenAct);

    colorMenu = optionsMenu->addMenu("&Light color");
    colorMenu->addAction(color0Act);
    colorMenu->addAction(color1Act);
    colorMenu->addAction(color2Act);
    colorMenu->addAction(color3Act);
    colorMenu->addAction(color10Act);

    effectMenu = optionsMenu->addMenu("&Effect");
    //effectMenu->addAction(effect0Act);
    effectMenu->addAction(effect1Act);
    effectMenu->addAction(effect2Act);
    effectMenu->addAction(effect10Act);

    materialMenu = optionsMenu->addMenu("Material");
    materialMenu->addAction(reseteffectAct);

    ambientMenu = materialMenu->addMenu("&Ambient");
    ambientMenu->addAction(ambient0Act);
    ambientMenu->addAction(ambient1Act);
    ambientMenu->addAction(ambient2Act);

    diffuseMenu = materialMenu->addMenu("&Diffuse");
    diffuseMenu->addAction(diffuse0Act);
    diffuseMenu->addAction(diffuse1Act);

    specularMenu = materialMenu->addMenu("&Specular");
    specularMenu->addAction(specular0Act);
    specularMenu->addAction(specular1Act);

    shininessMenu = materialMenu->addMenu("&Shininess");
    shininessMenu->addAction(shininess0Act);
    shininessMenu->addAction(shininess1Act);
    shininessMenu->addAction(shininess2Act);

    emissionMenu = materialMenu->addMenu("&Emission");
    emissionMenu->addAction(emission0Act);
    emissionMenu->addAction(emission1Act);

    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(aboutAct);
}

void MainWindow::showStat()
{
	StatDialog dialog(this);
	int nF = glWidget->mesh->numFaces;
	int nV = glWidget->mesh->numVerts;
	dialog.display_stat(nV,nF); //must be updated before calling "exec())
	if (dialog.exec()) {
		//bring up Statistic dialog
	}
}


void MainWindow::showAnimation(){
    glWidget->setrotating(true);
}

void MainWindow::hideAnimation(){
    glWidget->setrotating(false);
}

void MainWindow::reset(){glWidget->reset();}
void MainWindow::reseteffect(){
    ambient0Act->setChecked(true);
    glWidget->ambient(0);

    diffuse0Act->setChecked(true);
    glWidget->diffuse(0);

    specular0Act->setChecked(true);
    glWidget->specular(0);

    shininess0Act->setChecked(true);
    glWidget->shininess(0);

    emission0Act->setChecked(true);
    glWidget->emission(0);
}

void MainWindow::color0(){glWidget->color(0);}
void MainWindow::color1(){glWidget->color(1);}
void MainWindow::color2(){glWidget->color(2);}
void MainWindow::color3(){glWidget->color(3);}
void MainWindow::color10(){glWidget->color(10);}

void MainWindow::effect0(){glWidget->effect(0);}
void MainWindow::effect1(){glWidget->effect(1);}
void MainWindow::effect2(){glWidget->effect(2);}
void MainWindow::effect10(){glWidget->effect(10);}

void MainWindow::ambient0(){glWidget->ambient(0);}
void MainWindow::ambient1(){glWidget->ambient(1);}
void MainWindow::ambient2(){glWidget->ambient(2);}

void MainWindow::diffuse0(){glWidget->diffuse(0);}
void MainWindow::diffuse1(){glWidget->diffuse(1);}

void MainWindow::specular0(){glWidget->specular(0);}
void MainWindow::specular1(){glWidget->specular(1);}

void MainWindow::shininess0(){glWidget->shininess(0);}
void MainWindow::shininess1(){glWidget->shininess(1);}
void MainWindow::shininess2(){glWidget->shininess(2);}

void MainWindow::emission0(){glWidget->emission(0);}
void MainWindow::emission1(){glWidget->emission(1);}

void MainWindow::shading0(){glWidget->shading(0);}
void MainWindow::shading1(){glWidget->shading(1);}
void MainWindow::shading2(){glWidget->shading(2);}

void MainWindow::normal0(){glWidget->normal(0);}
void MainWindow::normal1(){glWidget->normal(1);}

