#include "loginview.h"
#include "ui_loginview.h"


loginview::loginview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginview)
{
    ui->setupUi(this);
    ui->lePassword->setEchoMode(QLineEdit::Password);


}

loginview::~loginview()
{
    delete ui;
}

void loginview::on_btnLogin_clicked()
{


    int k=0;
    QString login=ui->leLogin->text();
    QString password=ui->lePassword->text();
    QSqlQuery *query = new QSqlQuery(db1);
    query->exec("SELECT loginUser, passwordUser, Role_nameRole FROM user");
    while (query->next()){
        QString dblogin=query->value(0).toString();
        QString dbpassword=query->value(1).toString();
        QString dbrole=query->value(2).toString();
        qDebug()<<dblogin<<dbpassword<<dbrole;
        if (dblogin==login&&dbpassword==password){
            k++;
            if (dbrole=="admin"){
                adminview *adm_v = new adminview;
                adm_v->show();
                this->hide();
            }
            if (dbrole=="checkman") {

                checkmanview *chm_v = new checkmanview;
                chm_v->show();
                this->hide();

            }



        }

    }
    if (k==0) QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("В доступе отказано! Проверьте правильность вводимых вами логина и пароля"));
    qDebug()<<"connected";


}
