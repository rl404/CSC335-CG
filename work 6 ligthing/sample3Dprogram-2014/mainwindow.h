
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

    void color0();
    void color1();
    void color2();
    void color3();
    void color10();

    void effect0();
    void effect1();
    void effect2();
    void effect10();
	
private:
    Ui::MainWindowClass ui;
  
    void createMenus();
    void createActions();
    QMenu *helpMenu;
    QMenu *fileMenu;

    QMenu *optionsMenu;
    QMenu *animationMenu;
    QMenu *colorMenu;
    QMenu *effectMenu;

    QAction *aboutAct;
    QAction *openAct;
    QAction *exitAct;
    QAction *statAct;

    QActionGroup *animationGroup;
    QAction *animationShownAct;
    QAction *animationHiddenAct;
    QAction *resetAct;

    QActionGroup *colorGroup;
    QAction *color0Act;
    QAction *color1Act;
    QAction *color2Act;
    QAction *color3Act;
    QAction *color10Act;

    QActionGroup *effectGroup;
    QAction *effect0Act;
    QAction *effect1Act;
    QAction *effect2Act;
    QAction *effect10Act;

    QWidget *centralWidget;
    QScrollArea *glWidgetArea;   
    GLWidget *glWidget;  
};

#endif // MAINWINDOW_H
