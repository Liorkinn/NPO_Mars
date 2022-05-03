#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QtSql>
#include <QTableWidget>
#include <QLineEdit>
#include "dbconnect.h"
#include "changecheck.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTableView * table;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:

    Ui::MainWindow *ui;
    QSqlDatabase db;
    dbconnect database;



};
#endif // MAINWINDOW_H
