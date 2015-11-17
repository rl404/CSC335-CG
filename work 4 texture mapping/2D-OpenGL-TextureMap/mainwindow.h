

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>

#include "ui_mainwindow.h"
#include "MyImage.h"
#include <QLabel>
#include <QScrollArea>

class GLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
	void about();
	void openImageFile();
	void showStat();
	
private:
    Ui::MainWindowClass ui;
  
    void createMenus();
    void createActions();
    QMenu *helpMenu;
    QMenu *fileMenu;
    QMenu *optionsMenu;
    QAction *aboutAct;
    QAction *openAct;
    QAction *exitAct;
    QAction *statAct; 
    QWidget *centralWidget;
    QScrollArea *glWidgetArea;   
    GLWidget *glWidget;
    QLabel *imgLabel; //for holding image. And used as a widget.
    MyImage *myImg; // my image class

};

#endif // MAINWINDOW_H
