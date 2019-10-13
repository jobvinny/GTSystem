#include "mainwindow.h"
#include <QApplication>
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
int main(int argc, char *argv[]) // main() function is here! :D
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
