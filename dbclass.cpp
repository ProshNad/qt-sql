#include "dbclass.h"
#include "QTableView"
#include "QGridLayout"
#include "QDebug"
Dbclass::Dbclass(QString name1, QTableView *view)
{
    name=name1;
    model->setTable(name1);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    view->setModel(model);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();

}

void Dbclass::filt(QString fi,QTableView *view)
{
    model->select();
    model->setFilter(fi);
    view->setModel(model);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
    model->select();
}

void Dbclass::nofilt(QTableView *view)
{
    model->setFilter("");
    model->select();
    view->setModel(model);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
}

void Dbclass::del(int i,QTableView *view)
{

   model->removeRow(i);
   model->select();
   view->setModel(model);
   view->resizeColumnsToContents();
   view->resizeRowsToContents();
}

void Dbclass::add(QSqlRecord r,QTableView *view)
{
  model->insertRecord(-1, r);
  model->submitAll();
  model->select();
  view->setModel(model);
  view->resizeColumnsToContents();
  view->resizeRowsToContents();

}
QSqlTableModel* Dbclass::mod()
{
    return model;
}
