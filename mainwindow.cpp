#include "mainwindow.h"
#include "ui_mainwindow.h"
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

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "studentlogin.h"
#include "adminlogin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_studentdetails_clicked()
{
    StudentLogin sl;
    sl.exec();
}

void MainWindow::on_registerstudent_clicked()
{
   QMessageBox::information(this,"GT SYSTEM INFORMATION","The system was designed by the GridTech Company");
}

void MainWindow::on_dataoperations_clicked()
{
   AdminLogin adm;
   adm.exec();
}
