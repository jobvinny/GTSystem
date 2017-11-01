#ifndef STUDENTLOGIN_H
#define STUDENTLOGIN_H

#include <QDialog>
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
namespace Ui {
class StudentLogin;
}

class StudentLogin : public QDialog
{
    Q_OBJECT

public:
    explicit StudentLogin(QWidget *parent = 0);
    ~StudentLogin();

private slots:
    void on_slogin_clicked();

    void on_scancel_clicked();

private:
    Ui::StudentLogin *ui;
    QSqlDatabase gtdb;
};

#endif // STUDENTLOGIN_H
