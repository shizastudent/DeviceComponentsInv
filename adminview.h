#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>

namespace Ui {
class adminview;
}

class adminview : public QWidget
{
    Q_OBJECT

public:
    explicit adminview(QWidget *parent = nullptr);
    ~adminview();

private:
    Ui::adminview *ui;
};

#endif // ADMINVIEW_H
