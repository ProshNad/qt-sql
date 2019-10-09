#ifndef DBCLASS_H
#define DBCLASS_H
#include "QSql"
#include "QSqlDatabase"
#include "QSqlTableModel"
#include "QTableView"
#include "QString"
#include "QGridLayout"
#include "QTableView"
#include "QSqlRecord"

class Dbclass
{
private:
    QString name;
    QSqlTableModel *model=new QSqlTableModel;

public:
    Dbclass(QString name1, QTableView* view);
    void filt(QString fi, QTableView *view);
    void nofilt(QTableView *view);
    void del(int i, QTableView *view);
    void add(QSqlRecord r,QTableView *view);
    QSqlTableModel *mod();
};

#endif // DBCLASS_H
