/********************************************************************************
** Form generated from reading UI file 'statdialog.ui'
**
** Created: Sat Oct 13 19:33:30 2012
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

QT_BEGIN_NAMESPACE

class Ui_StatDialogClass
{
public:
    QPushButton *okButton;
    QLabel *label;
    QRadioButton *radioButton;
    QCheckBox *checkBox;

    void setupUi(QDialog *StatDialogClass)
    {
        if (StatDialogClass->objectName().isEmpty())
            StatDialogClass->setObjectName(QString::fromUtf8("StatDialogClass"));
        StatDialogClass->resize(186, 126);
        okButton = new QPushButton(StatDialogClass);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(30, 50, 71, 21));
        label = new QLabel(StatDialogClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 61, 41));
        radioButton = new QRadioButton(StatDialogClass);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(40, 80, 82, 17));
        checkBox = new QCheckBox(StatDialogClass);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(110, 20, 70, 17));

        retranslateUi(StatDialogClass);
        QObject::connect(okButton, SIGNAL(clicked()), StatDialogClass, SLOT(accept()));

        QMetaObject::connectSlotsByName(StatDialogClass);
    } // setupUi

    void retranslateUi(QDialog *StatDialogClass)
    {
        StatDialogClass->setWindowTitle(QApplication::translate("StatDialogClass", "Object Statistics", 0));
        okButton->setText(QApplication::translate("StatDialogClass", "OK", 0));
        label->setText(QApplication::translate("StatDialogClass", "Testing ...", 0));
        radioButton->setText(QApplication::translate("StatDialogClass", "RadioButton", 0));
        checkBox->setText(QApplication::translate("StatDialogClass", "CheckBox", 0));
    } // retranslateUi

};

namespace Ui {
    class StatDialogClass: public Ui_StatDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATDIALOG_H
