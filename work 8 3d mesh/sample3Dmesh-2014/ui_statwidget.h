/********************************************************************************
** Form generated from reading UI file 'statwidget.ui'
**
** Created: Wed 28. Sep 11:24:03 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATWIDGET_H
#define UI_STATWIDGET_H


#include <QWidget>

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_StatWidgetClass
{
public:
    QLabel *VertexLabel;
    QLabel *FaceLabel;

    void setupUi(QWidget *StatWidgetClass)
    {
        if (StatWidgetClass->objectName().isEmpty())
            StatWidgetClass->setObjectName(QString::fromUtf8("StatWidgetClass"));
        StatWidgetClass->resize(123, 88);
        VertexLabel = new QLabel(StatWidgetClass);
        VertexLabel->setObjectName(QString::fromUtf8("VertexLabel"));
        VertexLabel->setGeometry(QRect(9, 9, 175, 16));
        FaceLabel = new QLabel(StatWidgetClass);
        FaceLabel->setObjectName(QString::fromUtf8("FaceLabel"));
        FaceLabel->setGeometry(QRect(9, 49, 175, 16));

        retranslateUi(StatWidgetClass);

        QMetaObject::connectSlotsByName(StatWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *StatWidgetClass)
    {
        StatWidgetClass->setWindowTitle(QApplication::translate("StatWidgetClass", "StatWidget", 0));
        VertexLabel->setText(QApplication::translate("StatWidgetClass", "Vertices:", 0));
        FaceLabel->setText(QApplication::translate("StatWidgetClass", "Faces:", 0));
    } // retranslateUi

};

namespace Ui {
    class StatWidgetClass: public Ui_StatWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATWIDGET_H
