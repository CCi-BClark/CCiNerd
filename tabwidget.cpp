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

void TabWidget::setData(QString dataPath){
    //qDebug() << dataPath;
    dataStore = new QXlsx::Document(dataPath);
    QXlsx::CellRange range(dataStore->dimension());
    QString rows(range.rowCount()-1);
    QString cols(range.columnCount());
    setRowCount(range.rowCount());
    setColCount(range.columnCount());

    ui->labelTotal->setText(rows);
    ui->labelCurrent->setText(cols);
    for (int i = 1; i<= range.rowCount(); i++) {
        for (int k = 1; k<= range.columnCount(); i++) {
            ui->textCurrent->insertPlainText(dataStore->read(i,k).toString());
        }
    }

    /*
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
