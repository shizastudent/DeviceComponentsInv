#include "checkmanview.h"
#include "ui_checkmanview.h"

checkmanview::checkmanview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::checkmanview)
{
    ui->setupUi(this);
    ui->tabWidget->addTab(dev_v,"Станки");
    ui->tabWidget->addTab(war_v,"Склады");
    ui->tabWidget->addTab(comp_v,"Комплектующие");
    ui->tabWidget->addTab(rep_v,"Ремонтники");
}

checkmanview::~checkmanview()
{
    delete ui;
}
