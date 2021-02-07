#ifndef GENERATEWAYBILLVIEW_H
#define GENERATEWAYBILLVIEW_H

#include <QWidget>
#include <dependencies.h>
#include <QSqlRelationalTableModel>
#include <QMenu>

namespace Ui {
class generatewaybillview;
}

class generatewaybillview : public QWidget
{
    Q_OBJECT

public:
    explicit generatewaybillview(QWidget *parent = nullptr);
    ~generatewaybillview();

private slots:
    void on_tvWaybills_clicked(const QModelIndex &index);

    void on_pushButton_clicked();
    void slotCustomMenuRequested(QPoint pos);
    void slotRefresh();

private:
    Ui::generatewaybillview *ui;
    QSqlDatabase db1 = QSqlDatabase::database();
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this,db1);
    QSqlRelationalTableModel *model1 = new QSqlRelationalTableModel(this,db1);
    QSqlRelationalTableModel *model2 = new QSqlRelationalTableModel(this,db1);

    void setHeaders();


};

#endif // GENERATEWAYBILLVIEW_H
