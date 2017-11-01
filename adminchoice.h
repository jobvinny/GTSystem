#ifndef ADMINCHOICE_H
#define ADMINCHOICE_H

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
class AdminChoice;
}

class AdminChoice : public QDialog
{
    Q_OBJECT

public:
    explicit AdminChoice(QWidget *parent = 0);
    ~AdminChoice();

private slots:
    void on_registerstudent_clicked();

    void on_operatedata_clicked();

private:
    Ui::AdminChoice *ui;
    QSqlDatabase gtdb;
};

#endif // ADMINCHOICE_H
