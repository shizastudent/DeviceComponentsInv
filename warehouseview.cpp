#include "warehouseview.h"
#include "ui_warehouseview.h"

warehouseview::warehouseview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warehouseview)
{
    ui->setupUi(this);
    model->setTable("warehouse");
    model->select();
    ui->tableView->setModel(model);
    ui->leAreaWarehouse->setValidator(new QIntValidator(1,9999));
    setHeaders();


}

warehouseview::~warehouseview()
{
    delete ui;
}



void warehouseview::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->leIdWarehouse->setText(index.sibling(row,0).data().toString());
    ui->leAddressWarehouse->setText(index.sibling(row,1).data().toString());
    ui->leAreaWarehouse->setText(index.sibling(row,2).data().toString());
    setHeaders();

}

void warehouseview::on_btnAddWarehouse_clicked()
{

    address=ui->leAddressWarehouse->text();
    area=ui->leAreaWarehouse->text().toInt();

    model->setTable("warehouse");
    if (address==""||ui->leAreaWarehouse->text()==""){
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поля адрес и площадь не могут быть пустыми"));
    }
    else {

        QSqlRecord record = model->record();
        record.remove(record.indexOf("idwarehouse"));
        record.setValue("addressWarehouse",address);
        record.setValue("areaWarehouse",area);
        if(model->insertRecord(-1, record)){
                qDebug()<<"successful insertion";
                model->submitAll();
            }
            else{
                QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Ошибка добавления"));
                db1.rollback();
            }
    }
    model->select();
    setHeaders();

}

void warehouseview::on_btnDeleteWarehouse_clicked()
{
    if ( model->removeRow(ui->tableView->currentIndex().row())){
        model->select();
        setHeaders();

    }
    else {
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Ничего не выбрано! Выберите склад из таблицы"));
    }
}

void warehouseview::on_btnEditWarehouse_clicked()
{

    address=ui->leAddressWarehouse->text();
    area=ui->leAreaWarehouse->text().toInt();
    model->setTable("warehouse");
    if (address==""||ui->leAreaWarehouse->text()==""){
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поля адрес и площадь не могут быть пустыми"));
    }
    else {
        QSqlRecord record = model->record();
        record.remove(record.indexOf("idwarehouse"));
        record.setValue("addressWarehouse",address);
        record.setValue("areaWarehouse",area);
        if (model->setRecord(ui->tableView->currentIndex().row(),record)){
            qDebug()<<"successful insertion";
            model->submitAll();
        }
        else{
            QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Ошибка изменения"));
            db1.rollback();
        }
    }
    model->select();

    setHeaders();



}

void warehouseview::setHeaders()
{
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Адрес"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Площадь, кв.м"));

}
