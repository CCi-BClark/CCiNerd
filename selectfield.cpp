#include "selectfield.h"
#include "ui_selectfield.h"

SelectField::SelectField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectField) {
    ui->setupUi(this);

    connect(ui->cmbTargetType,SIGNAL(currentIndexChanged(int)),this,SLOT(toggleType()));
}

void SelectField::setTargetFieldList(QString dataLocation) {
    dataStore = new QXlsx::Document(dataLocation);
    ui->cmbTargetField->clear();

    for(int i = 1; i <= dataStore->dimension().columnCount(); i++){
        ui->cmbTargetField->addItem(dataStore->read(1,i).toString());
    }
}

SelectField::~SelectField() {
    close();
    delete ui;
}

void SelectField::toggleType() {
    if(ui->cmbTargetType->currentText() == "Field"){
        ui->cmbTargetField->setVisible(true);
        ui->labelTargetField->setVisible(true);
    } else if (ui->cmbTargetType->currentText() == "Button"){
        ui->cmbTargetField->setVisible(false);
        ui->labelTargetField->setVisible(false);
    }
}
