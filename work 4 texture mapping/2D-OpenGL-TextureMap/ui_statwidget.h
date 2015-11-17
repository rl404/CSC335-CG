/********************************************************************************
** Form generated from reading ui file 'statwidget.ui'
**
** Created: Tue Aug 26 13:24:35 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STATWIDGET_H
#define UI_STATWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatWidgetClass
{
public:
    QLabel *VertexLabel;
    QLabel *EdgeLabel;
    QLabel *FaceLabel;
    QLabel *label;

    void setupUi(QWidget *StatWidgetClass)
    {
    if (StatWidgetClass->objectName().isEmpty())
        StatWidgetClass->setObjectName(QString::fromUtf8("StatWidgetClass"));
    StatWidgetClass->resize(180, 121);
    VertexLabel = new QLabel(StatWidgetClass);
    VertexLabel->setObjectName(QString::fromUtf8("VertexLabel"));
    VertexLabel->setGeometry(QRect(9, 9, 175, 16));
    EdgeLabel = new QLabel(StatWidgetClass);
    EdgeLabel->setObjectName(QString::fromUtf8("EdgeLabel"));
    EdgeLabel->setGeometry(QRect(9, 29, 175, 16));
    FaceLabel = new QLabel(StatWidgetClass);
    FaceLabel->setObjectName(QString::fromUtf8("FaceLabel"));
    FaceLabel->setGeometry(QRect(9, 49, 175, 16));
    label = new QLabel(StatWidgetClass);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 80, 61, 16));

    retranslateUi(StatWidgetClass);

    QMetaObject::connectSlotsByName(StatWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *StatWidgetClass)
    {
    StatWidgetClass->setWindowTitle(QApplication::translate("StatWidgetClass", "StatWidget", 0, QApplication::UnicodeUTF8));
    VertexLabel->setText(QApplication::translate("StatWidgetClass", "Vertices:", 0, QApplication::UnicodeUTF8));
    EdgeLabel->setText(QApplication::translate("StatWidgetClass", "Edges:", 0, QApplication::UnicodeUTF8));
    FaceLabel->setText(QApplication::translate("StatWidgetClass", "Faces:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("StatWidgetClass", "Testing...", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(StatWidgetClass);
    } // retranslateUi

};

namespace Ui {
    class StatWidgetClass: public Ui_StatWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATWIDGET_H
