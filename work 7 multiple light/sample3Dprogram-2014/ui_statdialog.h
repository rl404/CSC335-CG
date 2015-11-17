
#ifndef UI_STATDIALOG_H
#define UI_STATDIALOG_H


#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>

#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>


QT_BEGIN_NAMESPACE

class Ui_StatDialogClass
{
public:
    QPushButton *okButton;
    QLabel *label;

    void setupUi(QDialog *StatDialogClass)
    {
        if (StatDialogClass->objectName().isEmpty())
            StatDialogClass->setObjectName(QString::fromUtf8("StatDialogClass"));
        StatDialogClass->resize(137, 93);
        okButton = new QPushButton(StatDialogClass);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(30, 50, 71, 21));
        label = new QLabel(StatDialogClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 61, 41));

        retranslateUi(StatDialogClass);
        QObject::connect(okButton, SIGNAL(clicked()), StatDialogClass, SLOT(accept()));

        QMetaObject::connectSlotsByName(StatDialogClass);
    } // setupUi

    void retranslateUi(QDialog *StatDialogClass)
    {
        StatDialogClass->setWindowTitle(QApplication::translate("StatDialogClass", "Object Statistics", 0));
        okButton->setText(QApplication::translate("StatDialogClass", "OK", 0));
        label->setText(QApplication::translate("StatDialogClass", "Testing ...", 0));
        Q_UNUSED(StatDialogClass);
    } // retranslateUi

};

namespace Ui {
    class StatDialogClass: public Ui_StatDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATDIALOG_H
