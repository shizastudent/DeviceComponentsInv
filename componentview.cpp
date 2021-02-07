#include "componentview.h"
#include "ui_componentview.h"

void componentview::setHeaders()
{
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Модель"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Станок"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Склад"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Статус"));
    model->setRelation(model->fieldIndex("device_iddevice"),
                       QSqlRelation("device","iddevice","modelDevice"));
    model->setRelation(model->fieldIndex("warehouse_idwarehouse"),
                       QSqlRelation("warehouse","idwarehouse","addressWarehouse"));
    model->select();
    model1->select();
    model2->select();

}

componentview::componentview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::componentview)
{
    ui->setupUi(this);
    model->setTable("component");



    ui->tableView->setModel(model);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(slotCustomMenuRequested(QPoint)));

    model1->setTable("device");

    ui->comboBox->setModel(model1);
    model2->setTable("warehouse");

    ui->comboBox_2->setModel(model2);

    ui->comboBox->setModelColumn(0);
    ui->comboBox_2->setModelColumn(0);





    ui->tableView->resizeColumnsToContents();
    setHeaders();


}

componentview::~componentview()
{
    delete ui;
}

void componentview::on_btnGenerateWaybillView_clicked()
{
    gw_v->show();
}

void componentview::on_btnAddComponent_clicked()
{
    if (ui->leModelComponent->text()=="") {
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поле модель не может быть пустым"));
    }
    else {

        model->setTable("component");
        QSqlRecord record = model->record();
        record.remove(record.indexOf("idcomponenent"));
        record.setValue("modelComponent",ui->leModelComponent->text());
        record.setValue("device_iddevice",ui->comboBox->currentText());
        record.setValue("warehouse_idwarehouse",ui->comboBox_2->currentText());
        record.setValue("statusComponent","На складе");
        if(model->insertRecord(-1, record)){
                qDebug()<<"successful insertion";
                model->submitAll();
            }
            else{
                db1.rollback();
                QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Указанныго склада или станка не существует"));
            }
    }

    model->select();
    setHeaders();
}

void componentview::on_btnUpdateComponent_clicked()
{
    if (ui->leModelComponent->text()=="") {
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Поле модель не может быть пустым"));
    }
    else {
        model->setTable("component");
        QSqlRecord record = model->record();
        record.remove(record.indexOf("idcomponenent"));
        record.setValue("modelComponent",ui->leModelComponent->text());
        record.setValue("device_iddevice",ui->comboBox->currentText().toInt());
        record.setValue("warehouse_idwarehouse",ui->comboBox_2->currentText().toInt());
        record.setValue("statusComponent","На складе");

        model->setRecord(ui->tableView->currentIndex().row(),record);
            db1.rollback();
            QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Указанныго склада или станка не существует"));

    }
    model->select();


    setHeaders();

}

void componentview::on_btnDeleteComponent_clicked()
{
    if ( model->removeRow(ui->tableView->currentIndex().row())){
        model->select();
        setHeaders();

    }
    else {
        QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Для данной комплектующей создана накладная!"));
    }

}

void componentview::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->leModelComponent->setText(index.sibling(row,1).data().toString());
    ui->comboBox->setCurrentText(index.sibling(row,2).data().toString());
    ui->comboBox_2->setCurrentText(index.sibling(row,2).data().toString());



}

void componentview::slotCustomMenuRequested(QPoint pos)
{
    QMenu* menu = new QMenu(this);
     QAction * refresh = new QAction(trUtf8("Обновить"),this);


     connect(refresh,SIGNAL(triggered()),this, SLOT(slotRefresh()));


     menu->addAction(refresh);

     menu->popup(ui->tableView->viewport()->mapToGlobal(pos));

}

void componentview::slotRefresh()
{
    setHeaders();

}
