#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QTabWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"

namespace Ui {
class TabWidget;
}

class DataWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit DataWidget(QWidget *parent = 0);
    ~DataWidget();
    void setData(QString);

protected:
    void setColCount(int);
    void setRowCount(int);
    void setCurrentRecord(int);
    void setAllRecords(void);

private slots:
    void setNextRecord();
    void setPrevRecord();

private:
    Ui::TabWidget *ui;
    QXlsx::Document *dataStore;
    int rowCount;
    int colCount;
};

#endif // DATAWIDGET_H
