#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include "dependencies.h"
#include "adminview.h"
#include "checkmanview.h"
#include <QDialog>

namespace Ui {
class loginview;
}

class loginview : public QDialog
{
    Q_OBJECT

public:
    explicit loginview(QWidget *parent = nullptr);
    ~loginview();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::loginview *ui;
    database *db_m=new database;
};

#endif // LOGINVIEW_H
