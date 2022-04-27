#include "dbconnect.h"
#include "ui_dbconnect.h"
#include <QMessageBox>
dbconnect::dbconnect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dbconnect)
{
    ui->setupUi(this);
    dbconnect::setWindowFlags(Qt::WindowStaysOnTopHint);
    dbconnect::activateWindow();
//    while(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "" || ui->lineEdit_4->text() == "" || ui->lineEdit_5->text() == "")
//    {
//        ui->pushButton->setEnabled(false);;
//    }
}

dbconnect::~dbconnect()
{
    delete ui;
}
void dbconnect::ConnectDb()
{
//    db = QSqlDatabase::addDatabase("QPSQL");
//    db.setHostName("127.0.0.1");
//    db.setDatabaseName("User_base");
//    db.setPort(5432);
//    db.setUserName("postgres");
//    db.setPassword("123");

//    if(db.open())
//    {
//      qDebug() << "Connect Success";
//    }else
//    {
//      qDebug() << "Failed connection";
//    }
}

void dbconnect::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(ui->lineEdit->text());
    db.setDatabaseName(ui->lineEdit_2->text());
    db.setPort(ui->lineEdit_3->text().toInt());
    db.setUserName(ui->lineEdit_4->text());
    db.setPassword(ui->lineEdit_5->text());
    if(!db.open())
    {
       ui->label_6->setText("Ошибка. Проверьте данные и БД.");
    }else
    {
        ui->label_6->setText("Успешное подключение.");
    }
}

