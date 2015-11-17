#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "ui_mainwindow.h"

#include <QScrollArea>

class GLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();    

    GLWidget *glWidget;

private slots:
	void about();
	void openAndReadFile();
    void showStat();

    void clear();
    void setTime();
	
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

    QAction *clearAct;
    QAction *setAct;
    
    QWidget *centralWidget;
    QScrollArea *glWidgetArea;
};

#endif // MAINWINDOW_H
