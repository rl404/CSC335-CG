/****************************************************************************
**
** Trolltech hereby grants a license to use the Qt/Eclipse Integration
** plug-in (the software contained herein), in binary form, solely for the
** purpose of creating code to be used with Trolltech's Qt software.
**
** Qt Designer is licensed under the terms of the GNU General Public
** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
** right to use certain no GPL licensed software under the terms of its GPL
** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
**
** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** Since we now have the GPL exception I think that the "special exception
** is no longer needed. The license text proposed above (other than the
** special exception portion of it) is the BSD license and we have added
** the BSD license as a permissible license under the exception.
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollArea>
#include "statwidget.h"


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

    void shading0();
    void shading1();
    void shading2();

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

    void normal0();
    void normal1();

	
private:
    Ui::MainWindowClass ui;
  
    void createMenus();
    void createActions();
    QMenu *helpMenu;
    QMenu *fileMenu;

    QMenu *optionsMenu;
    QMenu *shadingMenu;
    QMenu *animationMenu;
    QMenu *colorMenu;
    QMenu *effectMenu;
    QMenu *materialMenu;
    QMenu *ambientMenu;
    QMenu *diffuseMenu;
    QMenu *specularMenu;
    QMenu *shininessMenu;
    QMenu *emissionMenu;
    QMenu *normalMenu;

    QAction *aboutAct;
    QAction *openAct;
    QAction *exitAct;
    QAction *statAct;
    QWidget *centralWidget;
    QScrollArea *glWidgetArea;      
    GLWidget *glWidget;
    StatWidget *statWidget;

    QActionGroup *shadingGroup;
    QAction *shading0Act;
    QAction *shading1Act;
    QAction *shading2Act;

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

    QActionGroup *normalGroup;
    QAction *normal0Act;
    QAction *normal1Act;


};

#endif // MAINWINDOW_H
