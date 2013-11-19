#include "targetwidget.h"
#include "ui_targetwidget.h"

TargetWidget::TargetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TargetWidget){
    ui->setupUi(this);
    targets = new SelectField;
    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(btnAdd()));
}

void TargetWidget::btnAdd(){
    targets->show();
}

void TargetWidget::btnRemove(){

}

void TargetWidget::pushItem(QString data){
   ui->listTargets->addItem(data);
}

void TargetWidget::pullItem(void){
    ui->listTargets->selectedItems().detach();
}

TargetWidget::~TargetWidget(){
    close();
    delete ui;
}
