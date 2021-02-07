#include "checkmanview.h"
#include "ui_checkmanview.h"

checkmanview::checkmanview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::checkmanview)
{
    ui->setupUi(this);
    ui->tabWidget->insertTab(1,dev_v,"Станки");

    ui->tabWidget->insertTab(3,comp_v,"Комплектующие");
    ui->tabWidget->insertTab(4,rep_v,"Ремонтники");
    ui->tabWidget->insertTab(2,war_v,"Склады");
}

checkmanview::~checkmanview()
{
    delete ui;
}

void checkmanview::on_tabWidget_tabBarClicked(int index)
{


}
