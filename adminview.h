#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>
#include <QSqlTableModel>
#include "dependencies.h"

namespace Ui {
class adminview;
}

class adminview : public QWidget
{
    Q_OBJECT

public:
    explicit adminview(QWidget *parent = nullptr);
    ~adminview();
    void setHeaders();

private slots:
    void on_btnAddUser_clicked();

    void on_tvUsers_clicked(const QModelIndex &index);

    void on_btnDeleteUser_clicked();

    void on_btnUpdateUser_clicked();
signals:

private:
    Ui::adminview *ui;

    QSqlDatabase db1 = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this,db1);


    QString login;
    QString password;
    QString role;
};

#endif // ADMINVIEW_H
