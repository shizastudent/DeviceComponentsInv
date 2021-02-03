#ifndef WAREHOUSEVIEW_H
#define WAREHOUSEVIEW_H

#include <QWidget>

namespace Ui {
class warehouseview;
}

class warehouseview : public QWidget
{
    Q_OBJECT

public:
    explicit warehouseview(QWidget *parent = nullptr);
    ~warehouseview();

private:
    Ui::warehouseview *ui;
};

#endif // WAREHOUSEVIEW_H
