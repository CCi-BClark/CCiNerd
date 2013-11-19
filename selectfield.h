#ifndef SELECTFIELD_H
#define SELECTFIELD_H

#include <QWidget>
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"

namespace Ui {
class SelectField;
}

class SelectField : public QWidget
{
    Q_OBJECT

public:
    explicit SelectField(QWidget *parent = 0);
    void setTargetFieldList(QString dataLocation);

    ~SelectField();

public slots:
    void toggleType(void);

protected:

private:
    Ui::SelectField *ui;
    QXlsx::Document *dataStore;
    int *headers;
};

#endif // SELECTFIELD_H
