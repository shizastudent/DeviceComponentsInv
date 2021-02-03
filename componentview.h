#ifndef COMPONENTVIEW_H
#define COMPONENTVIEW_H

#include <QWidget>
#include "generatewaybillview.h"

namespace Ui {
class componentview;
}

class componentview : public QWidget
{
    Q_OBJECT

public:
    explicit componentview(QWidget *parent = nullptr);
    ~componentview();

private slots:
    void on_btnGenerateWaybillView_clicked();

private:
    Ui::componentview *ui;
    generatewaybillview *gw_v = new generatewaybillview;

};

#endif // COMPONENTVIEW_H
