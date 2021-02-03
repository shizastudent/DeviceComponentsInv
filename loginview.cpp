#include "loginview.h"
#include "ui_loginview.h"


loginview::loginview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginview)
{
    ui->setupUi(this);

}

loginview::~loginview()
{
    delete ui;
}

void loginview::on_btnLogin_clicked()
{




    QString login=ui->leLogin->text();
    QString password=ui->lePassword->text();
    if (db_m->authorizathion(login,password)==true)
    {
        QString role=db_m->CheckUserRole(login);
        if (role =="admin") {
            adminview *adm_v = new adminview;
            adm_v->show();
            this->hide();
        }
        if (role == "checkman") {
            checkmanview *chm_v = new checkmanview;
            chm_v->show();
            this->hide();

        }
    }


}
