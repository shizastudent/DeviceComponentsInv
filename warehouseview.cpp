#include "warehouseview.h"
#include "ui_warehouseview.h"

warehouseview::warehouseview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warehouseview)
{
    ui->setupUi(this);
}

warehouseview::~warehouseview()
{
    delete ui;
}
