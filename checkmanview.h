#ifndef CHECKMANVIEW_H
#define CHECKMANVIEW_H

#include <QWidget>
#include "deviceview.h"
#include "componentview.h"
#include "warehouseview.h"
#include "repairerview.h"

namespace Ui {
class checkmanview;
}

class checkmanview : public QWidget
{
    Q_OBJECT

public:
    explicit checkmanview(QWidget *parent = nullptr);
    ~checkmanview();

private:
    Ui::checkmanview *ui;
    deviceview *dev_v = new deviceview;
    componentview *comp_v = new componentview;
    warehouseview *war_v = new warehouseview;
    repairerview *rep_v = new repairerview;
};

#endif // CHECKMANVIEW_H
