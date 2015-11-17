
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

    setWindowTitle("Sample 2D OpenGL program");
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
	QMessageBox::about(this, "About Sample 2D OpenGL program",
        "Sample 2D OpenGL, using "
        "OpenGL, Qt and C++.\n\n" 
        "P. Mongkolnam, 2014\n\n"
        "Modified by Axel 56130500236");
}


void MainWindow::createActions()
{
	openAct = new QAction("&Open", this);
	connect(openAct, SIGNAL(triggered()), this, SLOT(openAndReadFile()));

	exitAct = new QAction("E&xit", this);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction("&About", this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    
//    statAct = new QAction("&Stat", this);
//    connect(statAct, SIGNAL(triggered()), this, SLOT(showStat()));

    setAct = new QAction("&Set time",this);
    setAct->setStatusTip("Set the time");
    connect(setAct, SIGNAL(triggered()), this, SLOT(setTime()));

    clearAct = new QAction("&Reset", this);
    clearAct->setStatusTip("Reset the time");
    connect(clearAct, SIGNAL(triggered()), this, SLOT(clear()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(exitAct);

    optionsMenu = menuBar()->addMenu("&Options");
    optionsMenu->addAction(setAct);
    optionsMenu->addAction(clearAct);

    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(aboutAct);
}

void MainWindow::showStat()
{
//	StatDialog dialog(this);
//	dialog.display_stat(0,0,0); //must be updated before calling "exec())
//	if (dialog.exec()) {
//		//bring up Statistic dialog
//	}
}

void MainWindow::setTime(){
    StatDialog dialog(this);
    if (dialog.exec()) {
        //bring up Statistic dialog
    }
    glWidget->set(dialog.getS(),dialog.getM(),dialog.getH());
}

void MainWindow::clear(){
    glWidget->reset();
}



