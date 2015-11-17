
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
    void reseteffect();

    void color0();
    void color1();
    void color2();
    void color3();
    void color10();

    void effect0();
    void effect1();
    void effect2();
    void effect10();

    void ambient0();
    void ambient1();
    void ambient2();

    void diffuse0();
    void diffuse1();

    void specular0();
    void specular1();

    void shininess0();
    void shininess1();
    void shininess2();

    void emission0();
    void emission1();
	
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
    QMenu *materialMenu;
    QMenu *ambientMenu;
    QMenu *diffuseMenu;
    QMenu *specularMenu;
    QMenu *shininessMenu;
    QMenu *emissionMenu;

    QAction *aboutAct;
    QAction *openAct;
    QAction *exitAct;
    QAction *statAct;

    QActionGroup *animationGroup;
    QAction *animationShownAct;
    QAction *animationHiddenAct;
    QAction *resetAct;
    QAction *reseteffectAct;

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

    QActionGroup *ambientGroup;
    QAction *ambient0Act;
    QAction *ambient1Act;
    QAction *ambient2Act;

    QActionGroup *diffuseGroup;
    QAction *diffuse0Act;
    QAction *diffuse1Act;

    QActionGroup *specularGroup;
    QAction *specular0Act;
    QAction *specular1Act;

    QActionGroup *shininessGroup;
    QAction *shininess0Act;
    QAction *shininess1Act;
    QAction *shininess2Act;

    QActionGroup *emissionGroup;
    QAction *emission0Act;
    QAction *emission1Act;

    QWidget *centralWidget;
    QScrollArea *glWidgetArea;   
    GLWidget *glWidget;  
};

#endif // MAINWINDOW_H
