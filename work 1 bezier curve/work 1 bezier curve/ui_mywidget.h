/********************************************************************************
** Form generated from reading ui file 'mywidget.ui'
**
** Created: Fri Aug 1 12:30:10 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidgetClass
{
public:

    void setupUi(QWidget *MyWidgetClass)
    {
    if (MyWidgetClass->objectName().isEmpty())
        MyWidgetClass->setObjectName(QString::fromUtf8("MyWidgetClass"));
    MyWidgetClass->resize(400, 300);

    retranslateUi(MyWidgetClass);

    QMetaObject::connectSlotsByName(MyWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MyWidgetClass)
    {
    MyWidgetClass->setWindowTitle(QApplication::translate("MyWidgetClass", "MyWidget", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MyWidgetClass);
    } // retranslateUi

};

namespace Ui {
    class MyWidgetClass: public Ui_MyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
