#include "studentlogin.h"
#include "ui_studentlogin.h"
#include "viewdetails.h"
//connection of db
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsql.h>
#include <QtSql/qsqldatabase.h>
StudentLogin::StudentLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentLogin)
{
    ui->setupUi(this);

}

StudentLogin::~StudentLogin()
{
    delete ui;
}

void StudentLogin::on_slogin_clicked()
{
    QString studenname = ui->susername->text();
    QString studepassword = ui->spassword->text();
    //database execution
        gtdb = QSqlDatabase::addDatabase("QMYSQL");

        gtdb.setHostName("localhost");
        gtdb.setUserName("TechGuy");
        gtdb.setPassword("jobvinny");
        gtdb.setDatabaseName("gridtech");

        QSqlQuery qry;
        if(gtdb.open()){
            if(studenname != "" && studepassword != ""){
          /*qry.prepare("select  *  from "+studenname+"  join units on "+studenname+".reg_no = "+studepassword+".reg_no "
                    "  where  "+studenname+".reg_no = '"+studepassword+"' &&  "+studenname+".Name = '"+studenname+"'");*/
      qry.prepare("select  *  from "+studepassword+"_K  where  reg_no = '"+studepassword+"' && Name = '"+studenname+"' ");
        QMessageBox::information(this,"GT_Dialog","Validating.....Please Wait");
            if(qry.exec()){
                if(qry.next()){
                    this->hide();
                    QMessageBox::information(this,"GT_Dialog","Logged in Successifully");

                    ViewDetails view;
                    view.exec();
                    gtdb.close();
                }
                else{
                    QMessageBox::critical(this,"GT_Dialog","Sorry Wrong Details");
                    ui->spassword->setText("");
                    gtdb.close();
                }

            }
            else{
                QMessageBox::critical(this,"GT_Dialog","Sorry Entries Not Found");
                ui->spassword->setText("");
            }
        }
            else{
                QMessageBox::critical(this,"GT_Dialog","Please Fill in the fields");
            }

        }

        else{
            QMessageBox::critical(this,"GT_Dialog","Connection Failed");
        }
    //end
   // this->hide();

}

void StudentLogin::on_scancel_clicked()
{
    this->hide();
}
