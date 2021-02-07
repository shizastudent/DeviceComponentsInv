#ifndef REPAIRERVIEW_H
#define REPAIRERVIEW_H

#include <QWidget>
#include "dependencies.h"

namespace Ui {
class repairerview;
}

class repairerview : public QWidget
{
    Q_OBJECT

public:
    explicit repairerview(QWidget *parent = nullptr);
    ~repairerview();

private slots:
    void on_btnAddRepairer_clicked();

    void on_btndDeleteRepairer_clicked();

    void on_tvRepairers_clicked(const QModelIndex &index);

private:
    void setHeaders();
    Ui::repairerview *ui;
    QSqlDatabase db1 = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this,db1);
    QString fio;

};

#endif // REPAIRERVIEW_H
