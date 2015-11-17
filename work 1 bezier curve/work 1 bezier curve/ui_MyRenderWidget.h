/********************************************************************************
** Form generated from reading UI file 'MyRenderWidget.ui'
**
** Created: Fri 24. Aug 15:29:40 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYRENDERWIDGET_H
#define UI_MYRENDERWIDGET_H

#include <QtCore/QVariant>
#include<QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>


QT_BEGIN_NAMESPACE

class Ui_MyRenderWidgetClass
{
public:

    void setupUi(QWidget *MyRenderWidgetClass)
    {
        if (MyRenderWidgetClass->objectName().isEmpty())
            MyRenderWidgetClass->setObjectName(QString::fromUtf8("MyRenderWidgetClass"));
        MyRenderWidgetClass->resize(400, 300);

        retranslateUi(MyRenderWidgetClass);

        QMetaObject::connectSlotsByName(MyRenderWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MyRenderWidgetClass)
    {
        MyRenderWidgetClass->setWindowTitle(QApplication::translate("MyRenderWidgetClass", "MyRenderWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class MyRenderWidgetClass: public Ui_MyRenderWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYRENDERWIDGET_H
