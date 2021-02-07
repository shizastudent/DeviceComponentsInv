#include "generatewaybillview.h"
#include "ui_generatewaybillview.h"

generatewaybillview::generatewaybillview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::generatewaybillview)
{
    ui->setupUi(this);
    model->setTable("waybill");

    ui->tvWaybills->setModel(model);
    model->select();
    ui->tvWaybills->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tvWaybills,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(slotCustomMenuRequested(QPoint)));

    model1->setTable("component");
    model1->select();
    ui->comboBox->setModel(model1);
    ui->comboBox->setModelColumn(0);

    model2->setTable("repairer");
    model2->select();
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setModelColumn(0);










    ui->lePriceonDate->setValidator(new QIntValidator(1,9999));

    setHeaders();
}

generatewaybillview::~generatewaybillview()
{
    delete ui;
}

void generatewaybillview::on_tvWaybills_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->dateEdit->setDate(index.sibling(row,1).data().toDate());
    ui->comboBox->setCurrentText(index.sibling(row,4).data().toString());
    ui->comboBox_2->setCurrentText(index.sibling(row,3).data().toString());
    ui->lePriceonDate->setText(index.sibling(row,2).data().toString());


}

void generatewaybillview::on_pushButton_clicked()
{
    int devid=0;
    int warid=0;
    int k = 0;
    QString statcomp;



    QSqlQuery *query = new QSqlQuery(db1);

    query->exec("SELECT component_idcomponent FROM waybill");
    while (query->next()){
        QString id = query->value(0).toString();
        if (id==ui->comboBox->currentText()){
            k++;
        }
    }

    if (k==0){

        query->exec("SELECT device_iddevice, warehouse_idwarehouse, statusComponent FROM component WHERE idcomponent='"+ui->comboBox->currentText()+"'");

        while (query->next()){
            devid=query->value(0).toInt();
            warid=query->value(1).toInt();
            statcomp=query->value(2).toString();

        }
        qDebug()<<devid<<warid<<statcomp;
        model->setTable("waybill");
        QSqlRecord record = model->record();
        record.remove(record.indexOf("idwaybill"));
        record.setValue("dateWaybill",ui->dateEdit->date().toString(Qt::ISODate));
        record.setValue("priceondate",ui->lePriceonDate->text().toInt());
        record.setValue("repairer_idrepairer",ui->comboBox_2->currentText().toInt());
        record.setValue("component_idcomponent",ui->comboBox->currentText().toInt());
        record.setValue("component_device_iddevice",devid);
        record.setValue("component_warehouse_idwarehouse",warid);

        if (model->insertRecord(-1, record)){
                query->exec("UPDATE component SET statusComponent = 'В работе' WHERE idcomponent='"+ui->comboBox->currentText()+"'");

                qDebug()<<"successful insertion";
                model->submitAll();
            }
            else{
                qDebug()<<"Не получилось";

                db1.rollback();
                QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Указанного ремонтника или компонента не существует"));

            }
    }
        else {
            QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("На данную комплектующую уже оформлена накладная"));
        }
    model->select();
    setHeaders();

}

void generatewaybillview::slotCustomMenuRequested(QPoint pos)
{
    QMenu* menu = new QMenu(this);
    QAction * refresh = new QAction(trUtf8("Обновить"),this);


    connect(refresh,SIGNAL(triggered()),this, SLOT(slotRefresh()));


    menu->addAction(refresh);

    menu->popup(ui->tvWaybills->viewport()->mapToGlobal(pos));
}

void generatewaybillview::setHeaders()
{

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Номер"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Дата накладной"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Цена"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Ремонтник"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Комплектующая"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Станок"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Склад"));
    model->setRelation(model->fieldIndex("component_idcomponent"),
                       QSqlRelation("component","idcomponent","modelComponent"));
    model->setRelation(model->fieldIndex("component_device_iddevice"),
                       QSqlRelation("device","iddevice","modelDevice"));
    model->setRelation(model->fieldIndex("component_warehouse_idwarehouse"),
                       QSqlRelation("warehouse","idwarehouse","addressWarehouse"));
    model->setRelation(model->fieldIndex("repairer_idrepairer"),
                       QSqlRelation("repairer","idrepairer","fioRepairer"));
    model->select();
    model1->select();
    model2->select();


}

void generatewaybillview::slotRefresh()
{
    setHeaders();

}
