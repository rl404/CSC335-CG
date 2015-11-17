
#ifndef STATDIALOG_H
#define STATDIALOG_H

#include <QtWidgets>
#include "ui_statdialog.h"

class StatDialog : public QDialog
{
    Q_OBJECT

public:
    StatDialog(QWidget *parent = 0);
    ~StatDialog();

    int s,m,h;

    int getH(),getM(),getS();

private slots:
    void on_button_rejected();
    void on_button_accepted();

private:
    Ui::StatDialogClass ui;
};

#endif // STATDIALOG_H
