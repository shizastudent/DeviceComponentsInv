#include "adminview.h"
#include "ui_adminview.h"

adminview::adminview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminview)
{
    ui->setupUi(this);
}

adminview::~adminview()
{
    delete ui;
}
