#include "repairerview.h"
#include "ui_repairerview.h"

repairerview::repairerview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::repairerview)
{
    ui->setupUi(this);
    model->setTable("repairer");
    ui->tvRepairers->setModel(model);
    model->select();
    setHeaders();
}

repairerview::~repairerview()
{
    delete ui;
}

void repairerview::on_btnAddRepairer_clicked()
{
    fio=ui->leFIORepairer->text();
    if (fio==""){
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поле ФИО не может быть пустым"));
    }
    else {
        model->setTable("repairer");
        QSqlRecord record = model->record();
        record.remove(record.indexOf("idrepairer"));
        record.setValue("fioRepairer",fio);
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

void repairerview::on_btndDeleteRepairer_clicked()
{
    model->removeRow(ui->tvRepairers->currentIndex().row());
    model->select();
    setHeaders();
}

void repairerview::on_tvRepairers_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->leIdRepairer->setText(index.sibling(row,0).data().toString());
    ui->leFIORepairer->setText(index.sibling(row,1).data().toString());
    setHeaders();

}

void repairerview::setHeaders()
{
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ФИО"));

}
