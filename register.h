#ifndef REGISTER_H
#define REGISTER_H

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
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
    void on_course_currentIndexChanged(const QString &arg1);

    void on_save_clicked();

    void on_cancel_clicked();

    void on_logout_clicked();

private:
    Ui::Register *ui;
    QSqlDatabase gtdb;
};

#endif // REGISTER_H
