#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    tabWidget = new DataWidget;
    targetWidget = new TargetWidget;
    setFileLabel("No File Selected");

    // Create signal/slot to call data window.
    connect(ui->buttonStart,SIGNAL(clicked()),this,SLOT(btnData()));
    connect(ui->menuExit,SIGNAL(triggered()),this,SLOT(closeAll()));
    connect(ui->buttonSelectFile,SIGNAL(clicked()),this,SLOT(btnOpen()));
    connect(ui->buttonSelectTarget,SIGNAL(clicked()),this,SLOT(btnTargets()));
    //connect(targetWidget->ui,SIGNAL(),this,SLOT(btnTargets()));
}

void MainWindow::btnData() {
    tabWidget->show();
}

void MainWindow::closeAll() {
    tabWidget->close();
    close();
}

void MainWindow::setFileLabel(QString name) {
    ui->fileLabel->setText(name);
}

void MainWindow::enableDataView(bool status) {
    ui->buttonStart->setEnabled(status);
    ui->menuStart->setEnabled(status);
}

void MainWindow::enableTargetSelect(bool status){
    ui->buttonSelectTarget->setEnabled(status);
    ui->menuSelectTarget->setEnabled(status);
}

void MainWindow::btnTargets() {
    targetWidget->show();
    targetWidget->targets->setTargetFieldList(fileName.absoluteFilePath());
}

void MainWindow::btnOpen() {
    fileName = QFileDialog::getOpenFileName(this,tr("Open Excel File"), "/home/", tr("Excel Files (*.xlsx)"));
    tabWidget->setData(fileName.absoluteFilePath());

    setFileLabel(fileName.fileName());
    enableTargetSelect(true);
    enableDataView(true); //TODO Dont make active till targets are selected.  Waiting for data processing to finish.
}

MainWindow::~MainWindow() {
    delete tabWidget;
    delete targetWidget;
    delete ui;
}


