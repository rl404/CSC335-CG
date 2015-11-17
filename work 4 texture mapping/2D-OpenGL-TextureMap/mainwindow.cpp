
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

    setWindowTitle("2D OpenGL Texture Mapping");
    resize(800, 800);
	 
    centralWidget = new QWidget;
    setCentralWidget(centralWidget);	
	glWidget = new GLWidget;
	
    glWidgetArea = new QScrollArea;
    glWidgetArea->setWidget(glWidget);
    glWidgetArea->setWidgetResizable(true);
    glWidgetArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    glWidgetArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    glWidgetArea->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    glWidgetArea->setMinimumSize(350, 350);

    QGridLayout *centralLayout = new QGridLayout;
    centralLayout->addWidget(glWidgetArea, 0, 0, 1, 1);   
    centralWidget->setLayout(centralLayout);    

    imgLabel = 0;
    myImg = 0;
}

MainWindow::~MainWindow()
{

}

void MainWindow::openImageFile()
{	
	QString fileName;
	fileName = QFileDialog::getOpenFileName(this,
	       "Open JPEG", "./", "JPEG Files (*.jpg)");

	if(fileName.isEmpty()) return;


	if(imgLabel) delete imgLabel;
	imgLabel = 0;

	myImg = new MyImage();
	imgLabel = new QLabel; //for storing and displaying image
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor)); //freeze the cursor
	bool successful_open = false;
    successful_open= myImg->openImageFile(fileName, imgLabel);
	QApplication::restoreOverrideCursor(); //return the cursor to normal

	if(!successful_open){
		delete imgLabel;
		imgLabel = 0;
		delete myImg;
		myImg = 0;
	}
	//send image to our widget to be further processed.
	glWidget->createTexture(myImg->image);
}


void MainWindow::about()
{
	QMessageBox::about(this, "About 2D OpenGL Texture Mapping Program",
        "Using OpenGL, Qt and C++.\n\n"
        "P. Mongkolnam, 2014\n\n"
        "Modified by Axel 56130500236");
}


void MainWindow::createActions()
{
	openAct = new QAction("&Open", this);
	connect(openAct, SIGNAL(triggered()), this, SLOT(openImageFile()));

	exitAct = new QAction("E&xit", this);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction("&About", this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    
    statAct = new QAction("&Stat", this);
    connect(statAct, SIGNAL(triggered()), this, SLOT(showStat()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    //optionsMenu = menuBar()->addMenu("&Options");
    //optionsMenu->addAction(statAct);
    
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



