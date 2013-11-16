#include "tabwidget.h"
#include "ui_tabwidget.h"
#include <QDebug>

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget)
{
    setRowCount(0);
    setColCount(0);
    ui->setupUi(this);
    connect(ui->buttonClose,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->buttonClose_2,SIGNAL(clicked()),this,SLOT(close()));
}

void TabWidget::setColCount(int size) {
    colCount = size;
    return;
}

void TabWidget::setRowCount(int size) {
    rowCount = size;
    return;
}

void TabWidget::setCurrentRecord(int record) {
    ui->labelRecord->setNum(record);
    for(int i = 1; i <= colCount; i++){
        ui->textCurrent->appendPlainText(dataStore->read(1,i).toString() + ": " + dataStore->read(record+1,i).toString());
    }
}

void TabWidget::setData(QString dataPath){
    dataStore = new QXlsx::Document(dataPath);
    QXlsx::CellRange range(dataStore->dimension());
    int rows((int)range.rowCount()-1);
    int cols((int)range.columnCount());

    // Init data views.
    setRowCount(rows);
    setColCount(cols);

    setCurrentRecord(1);
    ui->labelRecordTotal->setNum(rows);
    /*
    for (int i = 1; i <= rows; i++) {
        for (int k = 1; k <= cols; k++) {
            ui->textCurrent->appendPlainText(dataStore->read(1,k).toString() + ": " + dataStore->read(i+1,k).toString());
        }
    }

    qDebug() << "Test Colum A";
    qDebug() << dataStore->cellAt("A1")->value().toString();
    qDebug() << dataStore->cellAt("A2")->value().toString();
    qDebug() << dataStore->cellAt("A3")->value().toString();
    qDebug() << dataStore->cellAt("A4")->value().toString();
    qDebug() << "Test Colum B";
    qDebug() << dataStore->cellAt("B1")->value().toString();
    qDebug() << dataStore->cellAt("B2")->value().toString();
    qDebug() << dataStore->cellAt("B3")->value().toString();
    qDebug() << dataStore->cellAt("B4")->value().toString();

    // Keep idea around! Canceled due to CellRange is able to provide.
    QString arr2[10] = 0;
    int i = 1;
    bool proc = true;
    while (proc) {
        if(dataStore->cellAt(1,i) == 0x0) {
            break;
        }
        arr2[i-1].append(dataStore->cellAt(i,1)->value().toString());
        i++;
    }
    */
}

TabWidget::~TabWidget() {
    delete dataStore;
    delete ui;
}
