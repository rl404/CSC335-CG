#include "setwindow.h"
#include <QWidget>
#include <QLayout>

setwindow::setwindow(){
    setWindowTitle(tr("Set Time"));
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    resize(300,300);

//    QGridLayout *timeLayout = new QGridLayout;
//    QLabel *title = new QLabel(tr("Enter:"),this);
//    QLabel *time = new QLabel(tr("Second : Minute : Hour"),this);

//    timeLayout->addWidget(title,0,0);
//    timeLayout->addWidget(time,1,1);

}
