#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "time_proj.h"
#include <QLCDNumber>
#include <QLabel>
#include <QMainWindow>
#include <QTime>
#include <QTimeEdit>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimeEdit *Tmr;
    SortedTime *time_sort;

private:
    Ui::MainWindow *ui;
    QLabel *lbl;
    QTime time_tmp;
    QTimer *timer;

private slots:
    void on_Stop_clicked();
    void on_Start_clicked();
    void slotTimeout();
};

#endif // MAINWINDOW_H
