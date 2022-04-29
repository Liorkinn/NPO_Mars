#ifndef CHANGECHECK_H
#define CHANGECHECK_H

#include <QWidget>
#include <QSql>
#include <QtSql>
#include <QTableWidget>
#include <QLineEdit>
#include "dbconnect.h"
#include <QPushButton>

namespace Ui {
class ChangeCheck;
}

class ChangeCheck : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeCheck(QTableView *table, QString box,QWidget *parent = nullptr);
    ~ChangeCheck();
    void comboboxed();
    void comboboxedtwo();
    QTableView *tabled;

    QString boxed;
private slots:
    void on_pushButton_clicked();

signals:
    void update();

private:
    Ui::ChangeCheck *ui;
    QSqlDatabase db;
    dbconnect database;
};

#endif // CHANGECHECK_H
