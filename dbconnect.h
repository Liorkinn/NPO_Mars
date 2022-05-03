#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QWidget>
#include <QObject>
#include <QSqlDriver>
#include <QSql>
#include <QtSql>
namespace Ui {
class dbconnect;
}

class dbconnect : public QWidget
{
    Q_OBJECT

public:
    explicit dbconnect(QWidget *parent = nullptr);
    ~dbconnect();
    void ConnectDb();
    QSqlDatabase db;

private slots:
    void on_pushButton_clicked();

private:
    Ui::dbconnect *ui;
};

#endif // DBCONNECT_H
