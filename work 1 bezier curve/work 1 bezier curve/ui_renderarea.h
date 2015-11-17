/********************************************************************************
** Form generated from reading ui file 'renderarea.ui'
**
** Created: Fri Aug 1 12:47:04 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RENDERAREA_H
#define UI_RENDERAREA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderAreaClass
{
public:

    void setupUi(QWidget *RenderAreaClass)
    {
    if (RenderAreaClass->objectName().isEmpty())
        RenderAreaClass->setObjectName(QString::fromUtf8("RenderAreaClass"));
    RenderAreaClass->resize(400, 300);

    retranslateUi(RenderAreaClass);

    QMetaObject::connectSlotsByName(RenderAreaClass);
    } // setupUi

    void retranslateUi(QWidget *RenderAreaClass)
    {
    RenderAreaClass->setWindowTitle(QApplication::translate("RenderAreaClass", "RenderArea", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(RenderAreaClass);
    } // retranslateUi

};

namespace Ui {
    class RenderAreaClass: public Ui_RenderAreaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERAREA_H
