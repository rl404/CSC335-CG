/********************************************************************************
** Form generated from reading ui file 'renderareawidget.ui'
**
** Created: Fri Aug 1 13:17:56 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RENDERAREAWIDGET_H
#define UI_RENDERAREAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_renderAreaWidgetClass
{
public:

    void setupUi(QWidget *renderAreaWidgetClass)
    {
    if (renderAreaWidgetClass->objectName().isEmpty())
        renderAreaWidgetClass->setObjectName(QString::fromUtf8("renderAreaWidgetClass"));
    renderAreaWidgetClass->resize(400, 300);

    retranslateUi(renderAreaWidgetClass);

    QMetaObject::connectSlotsByName(renderAreaWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *renderAreaWidgetClass)
    {
    renderAreaWidgetClass->setWindowTitle(QApplication::translate("renderAreaWidgetClass", "renderAreaWidget", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(renderAreaWidgetClass);
    } // retranslateUi

};

namespace Ui {
    class renderAreaWidgetClass: public Ui_renderAreaWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERAREAWIDGET_H
