#ifndef REPAIRERVIEW_H
#define REPAIRERVIEW_H

#include <QWidget>

namespace Ui {
class repairerview;
}

class repairerview : public QWidget
{
    Q_OBJECT

public:
    explicit repairerview(QWidget *parent = nullptr);
    ~repairerview();

private:
    Ui::repairerview *ui;
};

#endif // REPAIRERVIEW_H
