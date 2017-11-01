#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "mainwindow.h"
#include "register.h"
#include "searchdetails.h"
#include <QMessageBox>
#include "adminchoice.h"

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

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);

}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_acancel_clicked()
{
    this->hide();
    MainWindow gtwindow;
    gtwindow.show();
}

void AdminLogin::on_alogin_clicked()
{
    QString adminname = ui->ausername->text();
    QString adminpassword = ui->apassword->text();
    //database execution
        gtdb = QSqlDatabase::addDatabase("QMYSQL");

        gtdb.setHostName("localhost");
        gtdb.setUserName("TechGuy");
        gtdb.setPassword("jobvinny");
        gtdb.setDatabaseName("gridtech");

        QSqlQuery qry;
        if(gtdb.open()){
            if(adminname != "" && adminpassword != ""){
          qry.prepare("select  *  from logindetails  where  username = '"+adminname+"' && password = '"+adminpassword+"' ");

            if(qry.exec()){
                QMessageBox::information(this,"GT_Dialog","Validating.....Please Wait");
                if(qry.next()){
                    gtdb.close();
                    this->hide();
                    QMessageBox::information(this,"GT_Dialog","Logged in Successifully");

                    AdminChoice gtchoice;
                    gtchoice.exec();
                }
                else{
                    QMessageBox::critical(this,"GT_Dialog","Sorry Wrong Details");
                    gtdb.close();
                    ui->apassword->setText("");
                }

            }
        }
            else{
                QMessageBox::critical(this,"GT_Dialog","Please Fill in the fields");
            }

        }

        else{
            QMessageBox::critical(this,"GT_Dialog","Connection Failed");
        }

}
