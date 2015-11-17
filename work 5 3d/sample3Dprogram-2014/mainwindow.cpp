
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

    setWindowTitle("Sample 3D program");
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
        "P. Mongkolnam, 2014");
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

void MainWindow::reset(){
    glWidget->reset();
}



