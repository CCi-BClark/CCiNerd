#ifndef TARGETWIDGET_H
#define TARGETWIDGET_H

#include <QWidget>
#include "selectfield.h"

namespace Ui {
class TargetWidget;
}

class TargetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TargetWidget(QWidget *parent = 0);
    ~TargetWidget();

private slots:
    void btnAdd();
    void btnRemove();

private:
    Ui::TargetWidget *ui;
    SelectField *targets;
};

#endif // TARGETWIDGET_H
