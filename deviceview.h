#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include <QWidget>

namespace Ui {
class deviceview;
}

class deviceview : public QWidget
{
    Q_OBJECT

public:
    explicit deviceview(QWidget *parent = nullptr);
    ~deviceview();

private:
    Ui::deviceview *ui;
};

#endif // DEVICEVIEW_H
