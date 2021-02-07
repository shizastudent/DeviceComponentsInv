#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include <QWidget>
#include "dependencies.h"

namespace Ui {
class deviceview;
}

class deviceview : public QWidget
{
    Q_OBJECT

public:
    explicit deviceview(QWidget *parent = nullptr);
    ~deviceview();

private slots:
    void on_btnAddDevice_clicked();

    void on_btnDeleteDevice_clicked();

    void on_btnUpdateDevice_clicked();

    void on_tvDevices_clicked(const QModelIndex &index);

private:
    Ui::deviceview *ui;
    QSqlDatabase db1 = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this,db1);
    void setHeaders();
    QString modelD;
    QString type;


};

#endif // DEVICEVIEW_H
