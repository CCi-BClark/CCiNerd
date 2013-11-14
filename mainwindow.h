#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include "tabwidget.h"
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void setFileLabel(QString name = " ");
    void enableTargetSelect(bool);
    void enableDataView(bool);

protected slots:
    void closeAll();

private slots:
    void btnData();                             // Call data window.
    void btnOpen();                             // Open xlsx file.

private:
    Ui::MainWindow *ui;
    QFileInfo fileName;
    TabWidget *tabWidget;                       // Create data window object.
    QXlsx::Document *file;
};

#endif // MAINWINDOW_H
