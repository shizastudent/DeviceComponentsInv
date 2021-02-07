#include "deviceview.h"
#include "ui_deviceview.h"

deviceview::deviceview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deviceview)
{
    ui->setupUi(this);
    model->setTable("device");
    ui->tvDevices->setModel(model);
    model->select();
    ui->leOperationallife->setValidator(new QIntValidator(1,20));
    setHeaders();
}

deviceview::~deviceview()
{
    delete ui;
}

void deviceview::on_btnAddDevice_clicked()
{
    if (ui->leModelDevice->text()==""||ui->leTypeDevice->text()==""||ui->leOperationallife->text()==""){
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поля модель, тип, эксплуатационный срок не могут быть пустыми"));
    }
    else {

        model->setTable("device");
        QSqlRecord record = model->record();
        record.remove(record.indexOf("iddevice"));
        record.setValue("modelDevice",ui->leModelDevice->text());
        record.setValue("typeDevice",ui->leTypeDevice->text());
        record.setValue("beginofworkingDevice",ui->deBeginWDevice->date().toString(Qt::ISODate));
        record.setValue("endofworkingDevice",ui->deEndWDevice->date().toString(Qt::ISODate));
        record.setValue("operationallifeDevice",ui->leOperationallife->text().toInt());
        if(model->insertRecord(-1, record)){
                qDebug()<<"successful insertion";
                model->submitAll();
            }
            else{
                db1.rollback();
            }
    }
    model->select();
    setHeaders();
}

void deviceview::on_btnDeleteDevice_clicked()
{
    if ( model->removeRow(ui->tvDevices->currentIndex().row())){
        model->select();
        setHeaders();
    }
    else {
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Для того что бы удалить данный станок - сначала удалите все связанные с ним комплектующие"));
    }
    setHeaders();
}

void deviceview::on_btnUpdateDevice_clicked()
{
    if (ui->leModelDevice->text()==""||ui->leTypeDevice->text()==""||ui->leOperationallife->text()==""){
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поля модель, тип, эксплуатационный срок не могут быть пустыми"));
    }
    else {
        QSqlRecord record = model->record();
        record.remove(record.indexOf("iddevice"));
        record.setValue("modelDevice",ui->leModelDevice->text());
        record.setValue("typeDevice",ui->leTypeDevice->text());
        record.setValue("beginofworkingDevice",ui->deBeginWDevice->date().toString(Qt::ISODate));
        record.setValue("endofworkingDevice",ui->deEndWDevice->date().toString(Qt::ISODate));
        record.setValue("operationallifeDevice",ui->leOperationallife->text().toInt());
        if (model->setRecord(ui->tvDevices->currentIndex().row(),record)){
            model->submitAll();
        } else {
            db1.rollback();
        }
    }
    model->select();
    setHeaders();

}

void deviceview::on_tvDevices_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->leModelDevice->setText(index.sibling(row,1).data().toString());
    ui->leTypeDevice->setText(index.sibling(row,2).data().toString());
    ui->deBeginWDevice->setDate(index.sibling(row,3).data().toDate());
    ui->deEndWDevice->setDate(index.sibling(row,4).data().toDate());
    ui->leOperationallife->setText(index.sibling(row,5).data().toString());
    setHeaders();
}

void deviceview::setHeaders()
{
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Модель"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Тип"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Дата начала работы"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Дата списания"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Эксплутационный срок"));

}
