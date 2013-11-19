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
    SelectField *targets;

protected:
    void pushItem(QString data);
    void pullItem(void);

private slots:
    void btnAdd();
    void btnRemove();

private:
    Ui::TargetWidget *ui;
};

#endif // TARGETWIDGET_H
