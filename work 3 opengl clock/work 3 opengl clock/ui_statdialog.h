/********************************************************************************
** Form generated from reading UI file 'statdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATDIALOG_H
#define UI_STATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_StatDialogClass
{
public:
    QLabel *label;
    QDialogButtonBox *button;
    QLineEdit *hour;
    QLineEdit *minute;
    QLineEdit *second;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *StatDialogClass)
    {
        if (StatDialogClass->objectName().isEmpty())
            StatDialogClass->setObjectName(QStringLiteral("StatDialogClass"));
        StatDialogClass->resize(200, 120);
        label = new QLabel(StatDialogClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 200, 15));
        button = new QDialogButtonBox(StatDialogClass);
        button->setObjectName(QStringLiteral("button"));
        button->setGeometry(QRect(0, 90, 200, 25));
        button->setLayoutDirection(Qt::LeftToRight);
        button->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        button->setCenterButtons(true);
        hour = new QLineEdit(StatDialogClass);
        hour->setObjectName(QStringLiteral("hour"));
        hour->setGeometry(QRect(10, 50, 40, 25));
        minute = new QLineEdit(StatDialogClass);
        minute->setObjectName(QStringLiteral("minute"));
        minute->setGeometry(QRect(80, 50, 40, 25));
        second = new QLineEdit(StatDialogClass);
        second->setObjectName(QStringLiteral("second"));
        second->setGeometry(QRect(150, 50, 40, 25));
        label_2 = new QLabel(StatDialogClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 25, 40, 25));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(StatDialogClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 25, 40, 25));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(StatDialogClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 25, 40, 25));
        label_4->setAlignment(Qt::AlignCenter);

        retranslateUi(StatDialogClass);

        QMetaObject::connectSlotsByName(StatDialogClass);
    } // setupUi

    void retranslateUi(QDialog *StatDialogClass)
    {
        StatDialogClass->setWindowTitle(QApplication::translate("StatDialogClass", "Object Statistics", 0));
        label->setText(QApplication::translate("StatDialogClass", "Enter the time:", 0));
        label_2->setText(QApplication::translate("StatDialogClass", "Hour", 0));
        label_3->setText(QApplication::translate("StatDialogClass", "Minute", 0));
        label_4->setText(QApplication::translate("StatDialogClass", "Second", 0));
    } // retranslateUi

};

namespace Ui {
    class StatDialogClass: public Ui_StatDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATDIALOG_H
