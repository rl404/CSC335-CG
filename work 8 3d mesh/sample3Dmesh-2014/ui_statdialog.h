/********************************************************************************
** Form generated from reading UI file 'statdialog.ui'
**
** Created: Wed 28. Sep 11:24:03 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATDIALOG_H
#define UI_STATDIALOG_H

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
#include <QtWidgets/QVBoxLayout>

#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatDialogClass
{
public:
    QPushButton *okButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *vertexLabel;
    QLabel *faceLabel;

    void setupUi(QDialog *StatDialogClass)
    {
        if (StatDialogClass->objectName().isEmpty())
            StatDialogClass->setObjectName(QString::fromUtf8("StatDialogClass"));
        StatDialogClass->resize(200, 126);
        okButton = new QPushButton(StatDialogClass);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(60, 90, 71, 21));
        layoutWidget = new QWidget(StatDialogClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 171, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        vertexLabel = new QLabel(layoutWidget);
        vertexLabel->setObjectName(QString::fromUtf8("vertexLabel"));

        verticalLayout->addWidget(vertexLabel);

        faceLabel = new QLabel(layoutWidget);
        faceLabel->setObjectName(QString::fromUtf8("faceLabel"));

        verticalLayout->addWidget(faceLabel);


        retranslateUi(StatDialogClass);
        QObject::connect(okButton, SIGNAL(clicked()), StatDialogClass, SLOT(accept()));

        QMetaObject::connectSlotsByName(StatDialogClass);
    } // setupUi

    void retranslateUi(QDialog *StatDialogClass)
    {
        StatDialogClass->setWindowTitle(QApplication::translate("StatDialogClass", "Mesh Statistics", 0));
        okButton->setText(QApplication::translate("StatDialogClass", "OK", 0));
        vertexLabel->setText(QApplication::translate("StatDialogClass", "Vertices", 0));
        faceLabel->setText(QApplication::translate("StatDialogClass", "Faces", 0));
    } // retranslateUi

};

namespace Ui {
    class StatDialogClass: public Ui_StatDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATDIALOG_H
