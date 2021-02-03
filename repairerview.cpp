#include "repairerview.h"
#include "ui_repairerview.h"

repairerview::repairerview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::repairerview)
{
    ui->setupUi(this);
}

repairerview::~repairerview()
{
    delete ui;
}
