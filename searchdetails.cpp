#include "searchdetails.h"
#include "ui_searchdetails.h"
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
SearchDetails::SearchDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDetails)

{
    ui->setupUi(this);

}

SearchDetails::~SearchDetails()
{
    delete ui;
}

void SearchDetails::on_choose_currentIndexChanged(const QString &arg1)
{

}

void SearchDetails::on_sprogram_currentIndexChanged(const QString &arg1)
{
    QString sectionop = ui->sprogram->currentText();
    if(sectionop == "Bsc.Applied Computer Science"){
        ui->sprogramid->setText("ACMP");
        ui->camaroprogram->setText("Bsc.Applied Computer Science");
        //courses
        ui->scourse1->setText("C++ Programming");
        ui->scourseid1->setText("ACMP 324");
        ui->slecture1->setText("Mr.Muthengi");

        ui->scourse2->setText("Databases");
        ui->scourseid2->setText("ACMP 355");
        ui->slecture2->setText("Mr.Gogo");

        ui->scourse3->setText("Marketing");
        ui->scourseid3->setText("ACMP 382");
        ui->slecture3->setText("Mr.Warutere");

        ui->scourse4->setText("Algorithm Design");
        ui->scourseid4->setText("ACMP 302");
        ui->slecture4->setText("Mr.Kinyua");

        ui->scourse5->setText("Computer Graphics");
        ui->scourseid5->setText("ACMP 344");
        ui->slecture5->setText("Mr.Osero");

        ui->scourse6->setText("Artificial Intelligence");
        ui->scourseid6->setText("ACMP 308");
        ui->slecture6->setText("Mrs.Gakii");
    }
    if(sectionop == "Bsc.Computer Science"){
        ui->sprogramid->setText("COMP");
        ui->camaroprogram->setText("Bsc.Computer Science");
        //courses
        ui->scourse1->setText("Research Methods");
        ui->scourseid1->setText("COMP 324");
        ui->slecture1->setText("Mr.Mwathi");

        ui->scourse2->setText("Databases");
        ui->scourseid2->setText("COMP 355");
        ui->slecture2->setText("Mr.Gogo");

        ui->scourse3->setText("Marketing");
        ui->scourseid3->setText("COMP 382");
        ui->slecture3->setText("Mrs.Gakii");

        ui->scourse4->setText("Algorithm Design");
        ui->scourseid4->setText("COMP 302");
        ui->slecture4->setText("Mr.Kinyua");

        ui->scourse5->setText("Computer Graphics");
        ui->scourseid5->setText("COMP 344");
        ui->slecture5->setText("Mr.Otulla");

        ui->scourse6->setText("Artificial Intelligence");
        ui->scourseid6->setText("COMP 308");
        ui->slecture6->setText("Mr.Ngereki");
    }
    else if (sectionop == "Choose Program "){
        ui->camaroprogram->setText("");
        //set everything to null/empty
        ui->sprogramid->setText("");
        //courses
        ui->scourse1->setText("");
        ui->scourseid1->setText("");
        ui->slecture1->setText("");

        ui->scourse2->setText("");
        ui->scourseid2->setText("");
        ui->slecture2->setText("");

        ui->scourse3->setText("");
        ui->scourseid3->setText("");
        ui->slecture3->setText("");

        ui->scourse4->setText("");
        ui->scourseid4->setText("");
        ui->slecture4->setText("");

        ui->scourse5->setText("");
        ui->scourseid5->setText("");
        ui->slecture5->setText("");

        ui->scourse6->setText("");
        ui->scourseid6->setText("");
        ui->slecture6->setText("");
       QMessageBox::information(this,"GT-Dialog","Please select program");

    }
}

void SearchDetails::on_search_clicked()
{
   QString searchvalue = ui->txtsearch->text();
    //database execution
        gtdb = QSqlDatabase::addDatabase("QMYSQL");

        gtdb.setHostName("localhost");
        gtdb.setUserName("TechGuy");
        gtdb.setPassword("jobvinny");
        gtdb.setDatabaseName("gridtech");

        QSqlQuery camarosearch;
          if(searchvalue != ""){
          if(gtdb.open()){
              QString acmp = "ACMP";
              QString comp = "COMP";
          camarosearch.prepare("select  *  from "+searchvalue+"_K  where  program_id = '"+acmp+"' || program_id = '"+comp+"' ");
           QMessageBox::information(this,"GT-Dialog","Checking For Record..........");
              if(camarosearch.exec()){
               while(camarosearch.next()){
                   QMessageBox::information(this,"GT-Dialog","Retrieving Records..........");
                   ui->sregno->setText(camarosearch.value(0).toString());
                   ui->sfirstname->setText(camarosearch.value(1).toString());
                   ui->dateofbirth->setText(camarosearch.value(2).toString());
                   ui->camaroprogram->setText(camarosearch.value(3).toString());
                   ui->sprogramid->setText(camarosearch.value(4).toString());
               }
               gtdb.close();
               gtdb.open();

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
                  ui->sregno->setText("");
                  ui->sfirstname->setText("");
                  ui->dateofbirth->setText("");
                  ui->camaroprogram->setText("");
                  //set everything to null/empty
                  ui->sprogramid->setText("");
                  //courses
                  ui->scourse1->setText("");
                  ui->scourseid1->setText("");
                  ui->slecture1->setText("");

                  ui->scourse2->setText("");
                  ui->scourseid2->setText("");
                  ui->slecture2->setText("");

                  ui->scourse3->setText("");
                  ui->scourseid3->setText("");
                  ui->slecture3->setText("");

                  ui->scourse4->setText("");
                  ui->scourseid4->setText("");
                  ui->slecture4->setText("");

                  ui->scourse5->setText("");
                  ui->scourseid5->setText("");
                  ui->slecture5->setText("");

                  ui->scourse6->setText("");
                  ui->scourseid6->setText("");
                  ui->slecture6->setText("");
              }



          }

          else{
              QMessageBox::critical(this,"GT-Dialog","Failed To Connect To Database");
          }
          }
          else{
              QMessageBox::critical(this,"GT-Dialog","Please Fill in The Fields");
          }
}

void SearchDetails::on_sdelete_clicked()
{
    QString searchvalue = ui->udrecord->text();
     //database execution
         gtdb = QSqlDatabase::addDatabase("QMYSQL");

         gtdb.setHostName("localhost");
         gtdb.setUserName("TechGuy");
         gtdb.setPassword("jobvinny");
         gtdb.setDatabaseName("gridtech");

         QSqlQuery camarosearch;
         if(searchvalue != ""){
             if(gtdb.open()){
                 camarosearch.prepare("DROP Table "+searchvalue+"_K");
                 QMessageBox::information(this,"GT-Dialog","Quering Data For Deletion.....");
                 if(camarosearch.exec()){
                     QMessageBox::information(this,"GT-Dialog","Deleting Student Personal Details.....");
                     gtdb.close();
                     if(gtdb.open()){
                         camarosearch.prepare("DROP Table "+searchvalue+"");
                         if(camarosearch.exec()){
                           QMessageBox::information(this,"GT-Dialog","Deleting Course Entries.....");
                           gtdb.close();
                           QMessageBox::information(this,"GT-Dialog","Record "+searchvalue+" deleted Successifully.....");
                           ui->udrecord->setText("");
                           ui->sregno->setText("");
                           ui->sfirstname->setText("");
                           ui->dateofbirth->setText("");
                           ui->camaroprogram->setText("");
                           //set everything to null/empty
                           ui->sprogramid->setText("");
                           //courses
                           ui->scourse1->setText("");
                           ui->scourseid1->setText("");
                           ui->slecture1->setText("");

                           ui->scourse2->setText("");
                           ui->scourseid2->setText("");
                           ui->slecture2->setText("");

                           ui->scourse3->setText("");
                           ui->scourseid3->setText("");
                           ui->slecture3->setText("");

                           ui->scourse4->setText("");
                           ui->scourseid4->setText("");
                           ui->slecture4->setText("");

                           ui->scourse5->setText("");
                           ui->scourseid5->setText("");
                           ui->slecture5->setText("");

                           ui->scourse6->setText("");
                           ui->scourseid6->setText("");
                           ui->slecture6->setText("");
                         }
                         else{
                             QMessageBox::critical(this,"GT-Dialog","Error Occured During Deletion");
                         }
                     }
                 }
                 else{
                    QMessageBox::critical(this,"GT-Dialog","Data Missing Can't Query");
                 }
             }
             else{
                  QMessageBox::critical(this,"GT-Dialog","Failed To Connect To Database");
             }
         }
         else{
              QMessageBox::critical(this,"GT-Dialog","Please Fill in The Fields");
         }
}

void SearchDetails::on_slogout_clicked()
{
    this->hide();
}

void SearchDetails::on_update_clicked()
{
    //get values to update from text fields
    QString registration = ui->sregno->text();
    QString names = ui->sfirstname->text();
    QString birth = ui->dateofbirth->text();
    QString dataupdate = ui->udrecord->text();
    QString fetchprogram;
    //database execution
        gtdb = QSqlDatabase::addDatabase("QMYSQL");

        gtdb.setHostName("localhost");
        gtdb.setUserName("TechGuy");
        gtdb.setPassword("jobvinny");
        gtdb.setDatabaseName("gridtech");

        QSqlQuery updatevalue;
        if(dataupdate != "" && registration != "" && names != "" && birth != ""){
        if(gtdb.open()){
            //updatevalue.prepare("select  *  from "+dataupdate+"_K  where  program_id = '"+fetchprogram+"' ");
            //hold the fetched value
            //QString fprogram = fetchprogram;
           if(updatevalue.exec()){
               QMessageBox::information(this,"GT-Dialog","Prepairing For Updates.....");
               gtdb.close();
               if(gtdb.open()){
                   QString acmp = "ACMP";
                   QString comp = "COMP";
                   updatevalue.prepare("update "+dataupdate+"_K set Name = '"+names+"', dob = '"+birth+"' where program_id = '"+acmp+"' || program_id = '"+comp+"'");
                   if(updatevalue.exec()){
                        QMessageBox::information(this,"GT-Dialog","Updating.....");
                        gtdb.close();
                        QMessageBox::information(this,"GT-Dialog","Updated Successifully.....");
                   }
                   else{
                     QMessageBox::critical(this,"GT-Dialog","Failed To Update.....");
                   }
               }

           }
           else{
               QMessageBox::critical(this,"GT-Dialog","Error Occured.....");
               gtdb.close();
           }
        }
        else{
           QMessageBox::critical(this,"GT-Dialog","Failed To Connect To Database");
        }
        }
        else{
            QMessageBox::critical(this,"GT-Dialog","Please Fill ");
        }

}
