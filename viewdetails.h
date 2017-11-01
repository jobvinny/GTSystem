#ifndef VIEWDETAILS_H
#define VIEWDETAILS_H

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
class ViewDetails;
}

class ViewDetails : public QDialog
{
    Q_OBJECT

public:
    explicit ViewDetails(QWidget *parent = 0);
    ~ViewDetails();

private slots:
    void on_check_clicked();

    void on_logout_clicked();

private:
    Ui::ViewDetails *ui;
    QSqlDatabase gtdb;
};

#endif // VIEWDETAILS_H
