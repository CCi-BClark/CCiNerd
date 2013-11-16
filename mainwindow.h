#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include "tabwidget.h"
#include "targetwidget.h"

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
    void btnData();                             // Call tabWidget.
    void btnTargets();                          // Call targetWidget.
    void btnOpen();                         // Select xlsx file data.

private:
    Ui::MainWindow *ui;
    QFileInfo fileName;
    TabWidget *tabWidget;                       // Create data view.
    TargetWidget *targetWidget;                 // Create add tagets view.
};

#endif // MAINWINDOW_H
