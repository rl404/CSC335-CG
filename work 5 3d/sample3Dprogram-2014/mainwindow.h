
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QScrollArea>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>

class GLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
	void about();
	void openAndReadFile();
	void showStat();

    void showAnimation();
    void hideAnimation();
    void reset();
	
private:
    Ui::MainWindowClass ui;
  
    void createMenus();
    void createActions();
    QMenu *helpMenu;
    QMenu *fileMenu;
    QMenu *optionsMenu;
    QMenu *animationMenu;
    QAction *aboutAct;
    QAction *openAct;
    QAction *exitAct;
    QAction *statAct; 
    QActionGroup *animationGroup;
    QAction *animationShownAct;
    QAction *animationHiddenAct;
    QAction *resetAct;
    QWidget *centralWidget;
    QScrollArea *glWidgetArea;   
    GLWidget *glWidget;  
};

#endif // MAINWINDOW_H
