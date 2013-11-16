#ifndef SELECTFIELD_H
#define SELECTFIELD_H

#include <QWidget>

namespace Ui {
class SelectField;
}

class SelectField : public QWidget
{
    Q_OBJECT

public:
    explicit SelectField(QWidget *parent = 0);
    ~SelectField();

private:
    Ui::SelectField *ui;
};

#endif // SELECTFIELD_H
