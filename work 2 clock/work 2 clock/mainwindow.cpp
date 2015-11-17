
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
    myWindowTitle = "Axel's clock";
    setWindowTitle(myWindowTitle);
    resize(600, 600);
    
    centralWidget = new QWidget;
    setCentralWidget(centralWidget);	

    myWidget = new MyRenderWidget;
    myWidget->setFocusPolicy(Qt::StrongFocus); //for a keyboard press!
    
    myTime = new setwindow();
    //myTime->setFocusPolicy(Qt::StrongFocus);
    
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
	exitAct = new QAction("E&xit", this);
	exitAct->setStatusTip("Quit this program");
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

   
    setAct = new QAction("&Random",this);
    setAct->setStatusTip("Random the time");
    connect(setAct, SIGNAL(triggered()), this, SLOT(setTime()));

    clearAct = new QAction("&Clear", this);
    clearAct->setStatusTip("Clear a display");
    connect(clearAct, SIGNAL(triggered()), this, SLOT(clearDisplay()));

    aboutAct = new QAction("&About", this);
    aboutAct->setStatusTip("About this program");
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
       
    optionsMenu = menuBar()->addMenu("&Options");
    optionsMenu->addAction(setAct);
    optionsMenu->addAction(clearAct);
    
    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(aboutAct);

}

void MainWindow::saveCRVfile()
{	
    QMessageBox::about(this, "Not implemented yet ",
            "Not implemented yet!");
}

void MainWindow::setTime(){
    myWidget->random();
    //myTime->show();
}

void MainWindow::clearDisplay()
{
    myWidget->reset();
}


void MainWindow::about()
{
    QMessageBox::about(this, "About sample 2D transformation ",
            "This sample program is implemented with "
            "Qt and C++.\n\n" 
            "P. Mongkolnam, 2014\n\n"
            "Modified by Axel 56130500236 \n");

}

void MainWindow::usage()
{
    QMessageBox::about(this, "Not implemented yet ",
            "Not implemented yet!");

}





