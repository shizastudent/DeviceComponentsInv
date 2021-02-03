#include "componentview.h"
#include "ui_componentview.h"

componentview::componentview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::componentview)
{
    ui->setupUi(this);
}

componentview::~componentview()
{
    delete ui;
}

void componentview::on_btnGenerateWaybillView_clicked()
{
    gw_v->show();
}
