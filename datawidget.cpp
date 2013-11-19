#include "datawidget.h"
#include "ui_tabwidget.h"
#include <QDebug>

DataWidget::DataWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget){
    setRowCount(0);
    setColCount(0);
    ui->setupUi(this);
    connect(ui->buttonClose,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->buttonClose_2,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->buttonNext,SIGNAL(clicked()),this,SLOT(setNextRecord()));
    connect(ui->buttonPrev,SIGNAL(clicked()),this,SLOT(setPrevRecord()));
}

void DataWidget::setColCount(int size) {
    colCount = size;
    return;
}

void DataWidget::setRowCount(int size) {
    rowCount = size;
    return;
}

void DataWidget::setCurrentRecord(int record) {
    // Clear fields first.
    ui->labelRecord->clear();
    ui->textCurrent->clear();

    // Input record.
    ui->labelRecord->setNum(record);
    for(int i = 1; i <= colCount; i++){
        ui->textCurrent->appendPlainText(dataStore->read(1,i).toString() + ": " + dataStore->read(record+1,i).toString());
    }
}

void DataWidget::setAllRecords(){
    ui->tableWidget->setColumnCount(colCount);  // must be run first
    ui->tableWidget->setRowCount(rowCount);     // must be run first
    QStringList headerList;
    for(int i= 1;i <=colCount;i++){
        headerList << dataStore->read(1,i).toString();
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerList);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setShowGrid(false);
    for(int i = 1; i <= rowCount; i++){
        for(int k = 1; k <= colCount;k++){
            ui->tableWidget->setItem(i-1,k-1,new QTableWidgetItem(dataStore->read(i+1,k).toString()));
        }
    }

}

void DataWidget::setNextRecord() {
    int current = ui->labelRecord->text().toInt();
    if(1 < current) {
        setCurrentRecord(current+1);
        if(current == rowCount-1){
            ui->buttonNext->setEnabled(false);
        }
    } else if (current == 1){
        setCurrentRecord(current+1);
        ui->buttonPrev->setEnabled(true);
    }
}

void DataWidget::setPrevRecord(){
    int current = ui->labelRecord->text().toInt();
    if (current >= 2){
        setCurrentRecord(current-1);
        if (current == 2) {
            ui->buttonPrev->setEnabled(false);
        }
    }
    if(!ui->buttonNext->isEnabled()){
        ui->buttonNext->setEnabled(true);
    }
}

void DataWidget::setData(QString dataPath){
    dataStore = new QXlsx::Document(dataPath);
    QXlsx::CellRange range(dataStore->dimension());
    int rows((int)range.rowCount()-1);
    int cols((int)range.columnCount());

    // Init data views.
    setRowCount(rows);
    setColCount(cols);

    setCurrentRecord(1);
    setAllRecords();
    ui->labelRecordTotal->setNum(rows);
    ui->buttonPrev->setEnabled(false);
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

DataWidget::~DataWidget() {
    close();
    delete ui;
}
