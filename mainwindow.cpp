#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QSql"
#include "QSqlDatabase"
#include "QSqlTableModel"
#include "QTableView"
#include "dbclass.h"
#include "QInputDialog"
#include "QSqlRecord"


QList<Dbclass> ob;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");
    db.setHostName("localhost");
    db.setUserName("root");

    db.setDatabaseName("basecorp");
    if(!db.open()){
        qDebug()<<"No";
    }
    else
        qDebug()<<"Yes";
    Dbclass t1(QString("work"),ui->tableView);
    Dbclass t2(QString("emplr"),ui->tableView_2);
    ob.append(t1);
    ob.append(t2);




}



void MainWindow::on_pushButton_7_clicked()
{
   ob[0].filt(QString( "%1 ='%2'")
              .arg(ui->lineEdit->text())
              .arg((ui->lineEdit_3->text())),
              ui->tableView);
}

void MainWindow::on_pushButton_9_clicked()
{
  ob[0].nofilt(ui->tableView);
}

void MainWindow::on_pushButton_8_clicked()
{

    ob[1].filt(QString( "%1 ='%2'")
               .arg(ui->lineEdit_2->text())
               .arg((ui->lineEdit_4->text())),
               ui->tableView_2);
}

void MainWindow::on_pushButton_10_clicked()
{
    ob[1].nofilt(ui->tableView_2);
}

void MainWindow::on_pushButton_4_clicked()
{
    int i = QInputDialog::getInt(this, QString::fromUtf8("Удаление строки"),
                             QString::fromUtf8("Введите номер строки:"), 25, 0, 100, 1);
    ob[0].del(i-1,ui->tableView);
}

void MainWindow::on_pushButton_6_clicked()
{
    int i = QInputDialog::getInt(this, QString::fromUtf8("Удаление строки"),
                             QString::fromUtf8("Введите номер строки:"), 25, 0, 100, 1);
    ob[1].del(i-1,ui->tableView_2);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString text1 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("№:"),
                                 QLineEdit::Normal);
    QString text2 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("ФИО Заказчика:"),
                                 QLineEdit::Normal);
    QString text3 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("Адрес:"),
                                 QLineEdit::Normal);
    QString text4 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("Вид работ:"),
                                 QLineEdit::Normal);
    QString text5 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("Дата:"),
                                 QLineEdit::Normal);
    QSqlRecord record=ob[0].mod()->record();
        record.setValue("№", text1);
        record.setValue("Заказчик", text2);
        record.setValue("Адрес", text3);
        record.setValue("Вид работ", text4);
        record.setValue("Дата", text5);
        ob[0].add(record,ui->tableView);

}

void MainWindow::on_pushButton_5_clicked()
{
    QString text1 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("№:"),
                                 QLineEdit::Normal);
    QString text2 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("ФИО:"),
                                 QLineEdit::Normal);
    QString text3 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("Должность:"),
                                 QLineEdit::Normal);
    QString text4 = QInputDialog::getText(this,
                                 QString::fromUtf8("Заполнение полей"),
                                 QString::fromUtf8("Адрес:"),
                                 QLineEdit::Normal);

    QSqlRecord record=ob[1].mod()->record();
        record.setValue("№", text1);
        record.setValue("ФИО", text2);
        record.setValue("Должность", text3);
        record.setValue("Адрес", text4);
        ob[1].add(record,ui->tableView_2);

}
