#ifndef SEARCHDETAILS_H
#define SEARCHDETAILS_H

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
class SearchDetails;
}

class SearchDetails : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDetails(QWidget *parent = 0);
    ~SearchDetails();

private slots:
    void on_choose_currentIndexChanged(const QString &arg1);

    void on_sprogram_currentIndexChanged(const QString &arg1);

    void on_search_clicked();

    void on_sdelete_clicked();

    void on_slogout_clicked();

    void on_update_clicked();

private:
    Ui::SearchDetails *ui;
    QSqlDatabase gtdb;
};

#endif // SEARCHDETAILS_H
