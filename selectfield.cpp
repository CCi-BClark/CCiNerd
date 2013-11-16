#include "selectfield.h"
#include "ui_selectfield.h"

SelectField::SelectField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectField)
{
    ui->setupUi(this);
}

SelectField::~SelectField()
{
    delete ui;
}
