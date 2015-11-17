
#ifndef MYRENDERWIDGET_H
#define MYRENDERWIDGET_H

#include "ui_MyRenderWidget.h"
#include <QString>



class MyRenderWidget : public QWidget
{
    Q_OBJECT

public:
    MyRenderWidget(QWidget *parent = 0);
    ~MyRenderWidget();

    int sec,min,hour;

    void reset();
    void random();
    bool writeOutputData(QString filename);
    
protected:
    void paintEvent(QPaintEvent *event);
    
private:

     Ui::MyRenderWidgetClass ui;
};

#endif // MYRENDERWIDGET_H
