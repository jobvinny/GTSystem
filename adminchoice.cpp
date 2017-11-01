#include "adminchoice.h"
#include "ui_adminchoice.h"
#include "searchdetails.h"
#include "register.h"

AdminChoice::AdminChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminChoice)
{
    ui->setupUi(this);
}

AdminChoice::~AdminChoice()
{
    delete ui;
}

void AdminChoice::on_registerstudent_clicked()
{
    this->hide();
    Register gtreg;
    gtreg.exec();
}

void AdminChoice::on_operatedata_clicked()
{
    this->hide();
    SearchDetails gtsearch;
    gtsearch.exec();
}
