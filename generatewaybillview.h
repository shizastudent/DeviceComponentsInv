#ifndef GENERATEWAYBILLVIEW_H
#define GENERATEWAYBILLVIEW_H

#include <QWidget>

namespace Ui {
class generatewaybillview;
}

class generatewaybillview : public QWidget
{
    Q_OBJECT

public:
    explicit generatewaybillview(QWidget *parent = nullptr);
    ~generatewaybillview();

private:
    Ui::generatewaybillview *ui;
};

#endif // GENERATEWAYBILLVIEW_H
