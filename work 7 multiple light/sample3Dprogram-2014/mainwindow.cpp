
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

    setWindowTitle("Sample lightning program");
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

    QGridLayout *centralLayout = new QGridLayout;
    centralLayout->addWidget(glWidgetArea, 0, 0, 1, 1);   
    centralWidget->setLayout(centralLayout);    
}

MainWindow::~MainWindow()
{

}

void MainWindow::openAndReadFile()
{	
    QMessageBox::about(this, "Not implemented",
            "Not implemented yet!");	
}


void MainWindow::about()
{
    QMessageBox::about(this, "About the sample 3D program",
        "The Sample 3D, using "
        "OpenGL, Qt and C++.\n\n" 
        "P. Mongkolnam, 2014.\n\n"
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
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionsMenu = menuBar()->addMenu("&Options");
    optionsMenu->addAction(resetAct);

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
	dialog.display_stat(0,0,0); //must be updated before calling "exec())
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



