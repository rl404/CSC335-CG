
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

    resetAct = new QAction("&Reset", this);
    resetAct->setStatusTip("Reset the position");
    connect(resetAct, SIGNAL(triggered()), this, SLOT(reset()));

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
    effect0Act->setChecked(true);
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
    effectMenu->addAction(effect0Act);
    effectMenu->addAction(effect1Act);
    effectMenu->addAction(effect2Act);
    effectMenu->addAction(effect10Act);
    
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

void MainWindow::color0(){glWidget->color(0);}

void MainWindow::color1(){glWidget->color(1);}

void MainWindow::color2(){glWidget->color(2);}

void MainWindow::color3(){glWidget->color(3);}

void MainWindow::color10(){glWidget->color(10);}

void MainWindow::effect0(){ glWidget->effect(0);}

void MainWindow::effect1(){glWidget->effect(1);}

void MainWindow::effect2(){glWidget->effect(2);}

void MainWindow::effect10(){glWidget->effect(10);}

