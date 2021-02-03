#include "deviceview.h"
#include "ui_deviceview.h"

deviceview::deviceview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deviceview)
{
    ui->setupUi(this);
}

deviceview::~deviceview()
{
    delete ui;
}
