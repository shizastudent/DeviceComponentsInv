#include "generatewaybillview.h"
#include "ui_generatewaybillview.h"

generatewaybillview::generatewaybillview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::generatewaybillview)
{
    ui->setupUi(this);
}

generatewaybillview::~generatewaybillview()
{
    delete ui;
}
