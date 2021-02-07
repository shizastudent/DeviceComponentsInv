#ifndef WAREHOUSEVIEW_H
#define WAREHOUSEVIEW_H

#include <QWidget>
#include <QSqlTableModel>
#include "dependencies.h"


namespace Ui {
class warehouseview;
}

class warehouseview : public QWidget
{
    Q_OBJECT

public:
    explicit warehouseview(QWidget *parent = nullptr);
    ~warehouseview();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_btnAddWarehouse_clicked();

    void on_btnDeleteWarehouse_clicked();

    void on_btnEditWarehouse_clicked();

private:
    Ui::warehouseview *ui;
    void setHeaders();
    QSqlDatabase db1 = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this,db1);

    QString address;
    int area;
};

#endif // WAREHOUSEVIEW_H
