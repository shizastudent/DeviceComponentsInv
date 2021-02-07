#include "adminview.h"
#include "ui_adminview.h"


adminview::adminview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminview)
{
    ui->setupUi(this);

    model->setTable("user");

    ui->tvUsers->setModel(model);
    model->select();
    setHeaders();



    ui->tvUsers->resizeColumnsToContents();



}

adminview::~adminview()
{
    delete ui;
}

void adminview::setHeaders()
{
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Логин"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Пароль"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Роль"));
}

void adminview::on_btnAddUser_clicked()
{
    login=ui->leLogin->text();
    password=ui->lePassword->text();
    role=ui->leRole->text();
    if (login=="" || password=="" || role==""){
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поля логин, пароль и роль не могут быть пустыми"));
    }
    else {

        QSqlRecord record = model->record();
        record.remove(record.indexOf("iduser"));
        record.setValue("loginUser",login);
        record.setValue("passwordUser",password);
        record.setValue("Role_nameRole",role);
        if(model->insertRecord(-1, record)){
                qDebug()<<"successful insertion";
                model->submitAll();
            }
            else{
                db1.rollback();
                QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Указанной роли не существует"));
            }
        model->select();
        setHeaders();
    }

}

void adminview::on_tvUsers_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->leLogin->setText(index.sibling(row,1).data().toString());
    ui->lePassword->setText(index.sibling(row,2).data().toString());
    ui->leRole->setText(index.sibling(row,3).data().toString());
}

void adminview::on_btnDeleteUser_clicked()
{
    if ( model->removeRow(ui->tvUsers->currentIndex().row())){
        model->select();
        setHeaders();

    }
    else {
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Ничего не выбрано! Выберите пользователя из таблицы"));
    }




}

void adminview::on_btnUpdateUser_clicked()
{
    login=ui->leLogin->text();
    password=ui->lePassword->text();
    role=ui->leRole->text();
    if (login=="" || password=="" || role==""){
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поля логин, пароль и роль не могут быть пустыми"));
    }
    else {
        QSqlRecord record = model->record();
        record.remove(record.indexOf("iduser"));
        record.setValue("loginUser",login);
        record.setValue("passwordUser",password);
        record.setValue("Role_nameRole",role);
        if (model->setRecord(ui->tvUsers->currentIndex().row(),record))
        {
            model->submitAll();
        }
        else
        {
            db1.rollback();
            QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Указанной роли не существует"));
        }
        model->select();
        setHeaders();
}

}
