#include "targetwidget.h"
#include "ui_targetwidget.h"

TargetWidget::TargetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TargetWidget)
{
    ui->setupUi(this);
    targets = new SelectField;

    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(btnAdd()));
}

void TargetWidget::btnAdd(){
    targets->show();
}

void TargetWidget::btnRemove(){

}

TargetWidget::~TargetWidget()
{
    delete ui;
}
