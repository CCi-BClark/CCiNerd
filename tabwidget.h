#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"

namespace Ui {
class TabWidget;
}

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = 0);
    ~TabWidget();
    void setData(QString);

protected:
    void setColCount(int);
    void setRowCount(int);

private slots:

private:
    Ui::TabWidget *ui;
    QXlsx::Document *dataStore;
    int rowCount;
    int colCount;
};

#endif // TABWIDGET_H
