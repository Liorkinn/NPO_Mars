#include "changecheck.h"
#include "ui_changecheck.h"
#include <QSqlDriver>
#include <QSql>
#include <QtSql>
#include <QTableWidget>
#include <QLineEdit>
#include "dbconnect.h"
#include <string>
#include <QMessageBox>
#include "mainwindow.h"
ChangeCheck::ChangeCheck(QTableView *table, QString box,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeCheck)
{
    ui->setupUi(this);
    db = database.db;
    comboboxed();
    comboboxedtwo();
    tabled = table;
    boxed = box;
}


void ChangeCheck::comboboxed()
{
    QSqlQueryModel *models = new QSqlQueryModel();
    models->setQuery("SELECT id, gender FROM \"Gender\"");
    ui->comboBox->setModel(models);
    ui->comboBox->setModelColumn(1);
}
void ChangeCheck::comboboxedtwo()
{
    QSqlQueryModel *models = new QSqlQueryModel();

    models->setQuery("SELECT id, education FROM \"Education\"");
    ui->comboBox_2->setModel(models);
    ui->comboBox_2->setModelColumn(1);
}
ChangeCheck::~ChangeCheck()
{
       delete ui;
}

void ChangeCheck::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO \"Staff\" (name, surname, patronymic, birth, education_id, gender_id) VALUES (:name, :surname, :patronymic, :birth, :education, :gender);");
    query.bindValue(":name", ui->lineEdit->text());  
    query.bindValue(":surname", ui->lineEdit_2->text());
    query.bindValue(":patronymic", ui->lineEdit_3->text());
    query.bindValue(":birth", ui->dateEdit->date());
    query.bindValue(":gender", (ui->comboBox->currentIndex())+1);
    query.bindValue(":education", (ui->comboBox_2->currentIndex())+1);
   // query.exec();
    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Ok);

    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "")
    {
        msgBox.setText("Error");
        msgBox.setInformativeText("Ошибка добавления. Имеются пустые поля.");
        msgBox.exec();
        return;
    }


    if(query.exec())
    {
       msgBox.setText("Успех");
       msgBox.setInformativeText("Запись добавлена.");
       msgBox.exec();
    }
    emit update();




   QSqlTableModel* model = new QSqlTableModel(0,db);
   model->setTable(boxed);
   model->select();
   QTableView* view = new QTableView();
   tabled->setModel(model);
    //qDebug() << (ui->comboBox_2->currentIndex())+1;

  //  query.exec();
}

