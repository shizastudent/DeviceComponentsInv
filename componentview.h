#ifndef COMPONENTVIEW_H
#define COMPONENTVIEW_H

#include <QWidget>
#include "generatewaybillview.h"
#include "dependencies.h"
#include <QSqlRelationalTableModel>


namespace Ui {
class componentview;
}

class componentview : public QWidget
{
    Q_OBJECT

public:
    void setHeaders();
    explicit componentview(QWidget *parent = nullptr);
    ~componentview();

private slots:
    void on_btnGenerateWaybillView_clicked();

    void on_btnAddComponent_clicked();

    void on_btnUpdateComponent_clicked();

    void on_btnDeleteComponent_clicked();

    void on_tableView_clicked(const QModelIndex &index);
    void slotCustomMenuRequested(QPoint pos);
    void slotRefresh();

private:
    Ui::componentview *ui;
    QSqlDatabase db1 = QSqlDatabase::database();
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this,db1);
    QSqlRelationalTableModel *model1 = new QSqlRelationalTableModel(this,db1);
    QSqlRelationalTableModel *model2 = new QSqlRelationalTableModel(this,db1);


    generatewaybillview *gw_v = new generatewaybillview;

};

#endif // COMPONENTVIEW_H
