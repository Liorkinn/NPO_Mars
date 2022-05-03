#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include "dbconnect.h"
#include <QSqlDriver>
#include <QSql>
#include <QtSql>
#include <QTableWidget>
#include <QLineEdit>
#include <QMessageBox>
#include "changecheck.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    database.ConnectDb();
    db = database.db;

    ui->comboBox->addItem("Gender", QVariant(1)); ui->comboBox->addItem("Education", QVariant(2)); ui->comboBox->addItem("Staff", QVariant(3));
    dbconnect *con = new dbconnect();
    con->show();

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    table = ui->tableView;
    ui->pushButton_3->setEnabled(false);
}

MainWindow::~MainWindow()
{   
    delete ui;
}

//SELECT count(*) FROM "Staff" WHERE gender_id = 1 AND education_id != 2;

void MainWindow::on_pushButton_clicked()
{
    QSqlTableModel* model = new QSqlTableModel(0,db);
    model->setTable(ui->comboBox->currentText());
    model->select();
    QTableView* view = new QTableView();
    ui->tableView->setModel(model);

    if(ui->comboBox->currentIndex() == 0  || ui->comboBox->currentIndex() == 1)
    {
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }else
    {
        ui->pushButton_2->setEnabled(true);     
    }
        ui->pushButton_3->setEnabled(false);
}

void MainWindow::on_pushButton_2_clicked()
{
    ChangeCheck *insert = new ChangeCheck(ui->tableView, ui->comboBox->currentText());
    insert->show();
    ui->pushButton_3->setEnabled(false);
}

//DELETE FROM "Staff" WHERE id = 45;


void MainWindow::on_pushButton_3_clicked()
{
    QModelIndex currentDiscount = ui->tableView->currentIndex();
    int id = ui->tableView->model()->data(ui->tableView->model()->index(currentDiscount.row(),0),0).value<int>();
    QMessageBox msgBox;
    msgBox.setText("Вы уверены что хотите удалить запись?");
    msgBox.setInformativeText("Yes - Delete information\nNo - Dont delete iinformation");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setIcon(QMessageBox::Critical);
    int res = msgBox.exec();
    if(res == QMessageBox::Ok)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM \"Staff\" WHERE id =:id");
        query.bindValue(":id", id);
        qDebug() << id;

        query.exec();
        QSqlQueryModel *models = new QSqlQueryModel();

        QSqlTableModel* model = new QSqlTableModel(0,db);
        model->setTable(ui->comboBox->currentText());
        model->select();
        QTableView* view = new QTableView();
        ui->tableView->setModel(model);
        ui->pushButton_3->setEnabled(false);
    }


}
//date_part('day', birth) = date_part('day', CURRENT_DATE + INTERVAL '1 DAY')
//AND date_part ('month', birth) = date_part('month', CURRENT_DATE + INTERVAL '1 DAY');

//1, SELECT count(*) FROM "Staff" WHERE gender_id = 1 AND education_id != 2 AND date(birth) < date('01.01.1991')

//2.. SELECT "Staff".name, "Staff".surname, "Staff".patronymic, "Staff".birth, "Gender".gender
//FROM "Staff"
//JOIN "Gender" ON "Gender".id = "Staff".gender_id
//WHERE date_part('year', CURRENT_DATE) = date_part('year', CURRENT_DATE + interval '10days')
 //  AND date_part('doy', birth)
 //      BETWEEN date_part('doy', CURRENT_DATE) AND date_part('doy', CURRENT_DATE + interval '10days')

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if(ui->comboBox->currentText() == "Staff")
    {
         ui->pushButton_3->setEnabled(true);
    }     
}

