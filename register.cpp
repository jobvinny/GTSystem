#include "register.h"
#include "ui_register.h"
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
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
   /* gtdb = QSqlDatabase::addDatabase("QMYSQL");

    gtdb.setHostName("localhost");
    gtdb.setUserName("TechGuy");
    gtdb.setPassword("jobvinny");
    gtdb.setDatabaseName("gridtech");*/


}

Register::~Register()
{
    delete ui;
}

void Register::on_course_currentIndexChanged(const QString &arg1)
{
    QString choose = ui->course->currentText();
    if(choose == "Bsc.Computer Science"){
        ui->programid->setText("COMP");
        //courses
        ui->course1->setText("Research Methods");
        ui->courseid1->setText("COMP 324");
        ui->lecture1->setText("Mr.Mwathi");

        ui->course2->setText("Databases");
        ui->courseid2->setText("COMP 355");
        ui->lecture2->setText("Mr.Gogo");

        ui->course3->setText("Marketing");
        ui->courseid3->setText("COMP 382");
        ui->lecture3->setText("Mrs.Gakii");

        ui->course4->setText("Algorithm Design");
        ui->courseid4->setText("COMP 302");
        ui->lecture4->setText("Mr.Kinyua");

        ui->course5->setText("Computer Graphics");
        ui->courseid5->setText("COMP 344");
        ui->lecture5->setText("Mr.Otulla");

        ui->course6->setText("Artificial Intelligence");
        ui->courseid6->setText("COMP 308");
        ui->lecture6->setText("Mr.Ngereki");

    }
    else if(choose == "Bsc.Applied Computer Science"){
        ui->programid->setText("ACMP");
        //courses
        ui->course1->setText("C++ Programming");
        ui->courseid1->setText("ACMP 324");
        ui->lecture1->setText("Mr.Muthengi");

        ui->course2->setText("Databases");
        ui->courseid2->setText("ACMP 355");
        ui->lecture2->setText("Mr.Gogo");

        ui->course3->setText("Marketing");
        ui->courseid3->setText("ACMP 382");
        ui->lecture3->setText("Mr.Warutere");

        ui->course4->setText("Algorithm Design");
        ui->courseid4->setText("ACMP 302");
        ui->lecture4->setText("Mr.Kinyua");

        ui->course5->setText("Computer Graphics");
        ui->courseid5->setText("ACMP 344");
        ui->lecture5->setText("Mr.Osero");

        ui->course6->setText("Artificial Intelligence");
        ui->courseid6->setText("ACMP 308");
        ui->lecture6->setText("Mrs.Gakii");
    }
    else if (choose == "Choose program"){
        //set everything to null/empty
        ui->programid->setText("");
        //courses
        ui->course1->setText("");
        ui->courseid1->setText("");
        ui->lecture1->setText("");

        ui->course2->setText("");
        ui->courseid2->setText("");
        ui->lecture2->setText("");

        ui->course3->setText("");
        ui->courseid3->setText("");
        ui->lecture3->setText("");

        ui->course4->setText("");
        ui->courseid4->setText("");
        ui->lecture4->setText("");

        ui->course5->setText("");
        ui->courseid5->setText("");
        ui->lecture5->setText("");

        ui->course6->setText("");
        ui->courseid6->setText("");
        ui->lecture6->setText("");
       QMessageBox::critical(this,"GT_Dialog","Please select program");

    }
}

void Register::on_save_clicked()
{
    //database execution
        gtdb = QSqlDatabase::addDatabase("QMYSQL");

        gtdb.setHostName("localhost");
        gtdb.setUserName("TechGuy");
        gtdb.setPassword("jobvinny");
        gtdb.setDatabaseName("gridtech");
    //get values
    QString choose = ui->course->currentText();
    QString Studentreg = ui->regno->text();
    QString fname = ui->firstname->text();
    QString lname = ui->lastname->text();
    //String to hold table
    QString name = (fname +" "+lname);

    QString dofb = ui->dateofbirth->text();
    QString pid =  ui->programid->text();
    //course name
    QString cname1 = ui->course1->text();
    QString cname2 = ui->course2->text();
    QString cname3 = ui->course3->text();
    QString cname4 = ui->course4->text();
    QString cname5 = ui->course5->text();
    QString cname6 = ui->course6->text();
    //course id
    QString cid1 = ui->courseid1->text();
    QString cid2 = ui->courseid2->text();
    QString cid3 = ui->courseid3->text();
    QString cid4 = ui->courseid4->text();
    QString cid5 = ui->courseid5->text();
    QString cid6 = ui->courseid6->text();

    //Lecturer
    QString lec1 = ui->lecture1->text();
    QString lec2 = ui->lecture2->text();
    QString lec3 = ui->lecture3->text();
    QString lec4 = ui->lecture4->text();
    QString lec5 = ui->lecture5->text();
    QString lec6 = ui->lecture6->text();

    QSqlQuery qry;

    if((pid == "ACMP" || pid == "COMP")){
    if(gtdb.open()){
        //create a table for student details
        qry.prepare("CREATE TABLE "+Studentreg+"_K(reg_no varchar(30),"
                                               "Name varchar(30),"
                                               "dob varchar(30),"
                                               "program_name varchar(30),"
                                               "program_id varchar(30),"
                                              "PRIMARY KEY(reg_no));");
        if(qry.exec()){
            gtdb.close();
            //connection for table details
            if(gtdb.open()){
                qry.prepare("insert into "+Studentreg+"_K(reg_no,Name,dob,program_name,program_id) values"
                                    " ('"+Studentreg+"','"+name+"','"+dofb+"','"+choose+"','"+pid+"')");

                QMessageBox::information(this,"GT_Dialog"," Creating Queries For "+name+"");
                if(qry.exec()){
                     QMessageBox::information(this,"GT_Dialog"," Student "+Studentreg+" has been registered successifully");
                     gtdb.close();
                }
            }
            else{
                QMessageBox::information(this,"GT_Dialog","Failed in Creating Queries For "+name+"");
            }
            //connection create table coursea
            if(gtdb.open()){
                qry.prepare("CREATE TABLE "+Studentreg+"(course_name varchar(30),"
                                                         "course_id varchar(30),"
                                                         "lecturer varchar(20),"
                                                       "program_id varchar(30));");

                if(qry.exec()){
                    QMessageBox::information(this,"GT_Dialog","Creating Course Queries For "+name+"");
                    gtdb.close();
                    if(gtdb.open()){
                        qry.prepare("insert into "+Studentreg+"(course_name,course_id,lecturer,program_id) values "
                                    "('"+cname1+"','"+cid1+"','"+lec1+"','"+pid+"'),"
                                    "('"+cname2+"','"+cid2+"','"+lec2+"','"+pid+"'),"
                                    "('"+cname3+"','"+cid3+"','"+lec3+"','"+pid+"'),"
                                    "('"+cname4+"','"+cid4+"','"+lec4+"','"+pid+"'),"
                                    "('"+cname5+"','"+cid5+"','"+lec5+"','"+pid+"'),"
                                    "('"+cname6+"','"+cid6+"','"+lec6+"','"+pid+"')");
                        if(qry.exec()){
                            QMessageBox::information(this,"GT_Dialog","Student "+Studentreg+" Courses has been registered successifully");
                            gtdb.close();
                            QMessageBox::information(this,"GT-Dialog",""+name+"  has been registered successifully");
                        }
                    }
                }
            }
            else{
                QMessageBox::critical(this,"Enteries","Failed in Creating Course Queries For "+name+"");
            }
        }
        else{
            QMessageBox::critical(this,tr("GT_Dialog"),tr("Failed Register"));
            gtdb.close();
        }

        }
    else{
        QMessageBox::critical(this,tr("GT_Dialog"),tr("Connection Failed"));
    }

    }
    else{
         QMessageBox::critical(this,tr("GT_Dialog"),tr("Ensure all entries are entered"));
    }
}

void Register::on_cancel_clicked()
{
    //set everything to null/empty
    ui->regno->setText("");
    ui->firstname->setText("");
    ui->lastname->setText("");
    ui->programid->setText("");
    //courses
    ui->course1->setText("");
    ui->courseid1->setText("");
    ui->lecture1->setText("");

    ui->course2->setText("");
    ui->courseid2->setText("");
    ui->lecture2->setText("");

    ui->course3->setText("");
    ui->courseid3->setText("");
    ui->lecture3->setText("");

    ui->course4->setText("");
    ui->courseid4->setText("");
    ui->lecture4->setText("");

    ui->course5->setText("");
    ui->courseid5->setText("");
    ui->lecture5->setText("");

    ui->course6->setText("");
    ui->courseid6->setText("");
    ui->lecture6->setText("");
}

void Register::on_logout_clicked()
{
    this->hide();
}
