
#ifndef STATDIALOG_H
#define STATDIALOG_H

#include <QtWidgets/QDialog>
#include "ui_statdialog.h"

class StatDialog : public QDialog
{
    Q_OBJECT

public:
    StatDialog(QWidget *parent = 0);
    ~StatDialog();

    void display_stat(int nVertices, int nEdges, int nFaces);
private:
    Ui::StatDialogClass ui;
};

#endif // STATDIALOG_H
