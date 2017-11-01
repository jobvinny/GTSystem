#include "viewdetails.h"
#include "ui_viewdetails.h"
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
ViewDetails::ViewDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewDetails)
{
    ui->setupUi(this);
    ui->Welcome->hide();
}

ViewDetails::~ViewDetails()
{
    delete ui;
}

void ViewDetails::on_check_clicked()
{
    QString username = ui->viewname->text();
    QString searchvalue = ui->viewreg->text();
     //database execution
         gtdb = QSqlDatabase::addDatabase("QMYSQL");

         gtdb.setHostName("localhost");
         gtdb.setUserName("TechGuy");
         gtdb.setPassword("jobvinny");
         gtdb.setDatabaseName("gridtech");

         QSqlQuery camarosearch;
         if(username != "" && searchvalue != ""){
         if(gtdb.open()){
              camarosearch.prepare("select  *  from "+searchvalue+"_K  where  reg_no = '"+searchvalue+"' && Name = '"+username+"' ");
              if(camarosearch.exec()){
                  QMessageBox::information(this,"GT_Dialog","Validating.....Please Wait");
                  if(camarosearch.next()){
                      //information
                      QMessageBox::information(this,"GT_Dialog","Loading Database Records");
                      ui->viewreg->setText("");
                      ui->Welcome->setText("Welcome " + username + ",this are your Details ");
                      ui->Welcome->show();
                      //information

                      //code for data retreving
                      camarosearch.prepare("select  *  from "+searchvalue+"_K  where  reg_no = '"+searchvalue+"' ");
                       QMessageBox::information(this,"GT-Dialog","Checking For Your Record..........");
                          if(camarosearch.exec()){
                           while(camarosearch.next()){
                               QMessageBox::information(this,"GT-Dialog","Retrieving Records..........");
                               ui->sregno->setText(camarosearch.value(0).toString());
                               ui->sfirstname->setText(camarosearch.value(1).toString());
                               ui->dobirth->setText(camarosearch.value(2).toString());
                               ui->programname->setText(camarosearch.value(3).toString());
                               ui->sprogramid->setText(camarosearch.value(4).toString());
                           }
                           gtdb.close();
                           gtdb.open();
                           QString acmp = "ACMP";
                           QString comp = "COMP";
                           camarosearch.prepare("select course_name,course_id,lecturer from "+searchvalue+"  where  program_id = '"+acmp+"' || program_id = '"+comp+"' ");
                           QMessageBox::information(this,"GT-Dialog","Checking For Course Record..........");
                           if(camarosearch.exec()){
                                QMessageBox::information(this,"GT-Dialog","Retrieving Course Records..........");
                               while(camarosearch.next()){

                                   ui->scourse1->setText(camarosearch.record().value(0).toString());
                                   ui->scourseid1->setText(camarosearch.record().value(1).toString());
                                   ui->slecture1->setText(camarosearch.record().value(2).toString());

                                   camarosearch.next();
                                   ui->scourse2->setText(camarosearch.record().value(0).toString());
                                   ui->scourseid2->setText(camarosearch.record().value(1).toString());
                                   ui->slecture2->setText(camarosearch.record().value(2).toString());

                                   camarosearch.next();
                                   ui->scourse3->setText(camarosearch.record().value(0).toString());
                                   ui->scourseid3->setText(camarosearch.record().value(1).toString());
                                   ui->slecture3->setText(camarosearch.record().value(2).toString());

                                   camarosearch.next();
                                   ui->scourse4->setText(camarosearch.record().value(0).toString());
                                   ui->scourseid4->setText(camarosearch.record().value(1).toString());
                                   ui->slecture4->setText(camarosearch.record().value(2).toString());

                                   camarosearch.next();
                                   ui->scourse5->setText(camarosearch.record().value(0).toString());
                                   ui->scourseid5->setText(camarosearch.record().value(1).toString());
                                   ui->slecture5->setText(camarosearch.record().value(2).toString());

                                   camarosearch.next();
                                   ui->scourse6->setText(camarosearch.record().value(0).toString());
                                   ui->scourseid6->setText(camarosearch.record().value(1).toString());
                                   ui->slecture6->setText(camarosearch.record().value(2).toString());
                                   break;
                           }
                               gtdb.close();
                          }
                           else{
                               QMessageBox::critical(this,"GT-Dialog","Sorry Course Records Missing In The DataBase");
                               gtdb.close();
                           }
                          }

                          else{
                              QMessageBox::critical(this,"GT-Dialog","Sorry Record Missing In The DataBase");
                              gtdb.close();
                          }
                      //end of code data retreving


                  }
                  else{
                      QMessageBox::critical(this,"GT_Dialog","An Error Occured Please Try Again");
                  }

              }
              else{
                  QMessageBox::critical(this,"GT_Dialog","Sorry Wrong Details");
                  gtdb.close();
                  ui->viewreg->setText("");
              }
         }
         else{
              QMessageBox::critical(this,"GT_Dialog","Connection Failed");
         }
         }
         else{
            QMessageBox::critical(this,"GT_Dialog","Please Enter Your Details...");
         }

}

void ViewDetails::on_logout_clicked()
{
    this->hide();
}
