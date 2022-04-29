#include "mainwindow.h"
#include <QApplication>
#include <QSqlDriver>
#include <QSql>
#include <QtSql>
#include <QTableWidget>
#include <QLineEdit>
#include "dbconnect.h"

int main(int argc, char *argv[])
{    
       QApplication a(argc, argv);

        MainWindow w;      
        w.show();
        return a.exec();


}
