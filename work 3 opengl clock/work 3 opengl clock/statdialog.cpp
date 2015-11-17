#include "statdialog.h"

StatDialog::StatDialog(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

StatDialog::~StatDialog()
{

}

void StatDialog::on_button_rejected()
{
    h=0;m=0;s=0;
    this->close();
}

void StatDialog::on_button_accepted()
{
    QString hS = ui.hour->text();
    h = hS.toInt();

    QString mS = ui.minute->text();
    m = mS.toInt();

    QString sS = ui.second->text();
    s = sS.toInt();

    if(h>=24 || m>=60 || s>=60 || hS.isEmpty() || mS.isEmpty() || sS.isEmpty()){
        QMessageBox::about(this,"Error","Please enter with the correct number.");
    }else{
        this->close();
    }
}

int StatDialog::getH(){
    return h;
}

int StatDialog::getM(){
    return m;
}


int StatDialog::getS(){
    return s;
}

