#define _CRT_SECURE_NO_WARNINGS
#include "mainwindow.h"
#include "calcutate.h"
#include "time_proj.h"

#include "ui_mainwindow.h"

#include <ctime> // подключаем необходимый заголовочный файл
#include <QApplication>
#include <QLCDNumber>
#include <QProcess>
#include <QTimeEdit>
#include <QTimer>

time_t time_zero;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //TODO move to static section
    struct tm t;
    t.tm_year = 2013 - 1900;
    t.tm_mon = 0;
    t.tm_mday = 0;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = 0;
    time_zero = mktime(&t);
    ////////////////////////////////

    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete lbl;
}

void MainWindow::on_Stop_clicked()
{
    QProcess::startDetached("shutdown -a");
    Tmr = ui->Tmr;

    QDateTime dt;
    dt.setTime_t(time_zero); // конвертируем Unix-время в обычный формат даты
    Tmr->setDateTime(dt);
    timer->stop();
    ui->lbl->setText("00:00:00");
}

void MainWindow::on_Start_clicked()
{
    Tmr = ui->Tmr;

    int HOUR = Tmr->time().hour();
    int MIN = Tmr->time().minute();
    int SEC = Tmr->time().second();

    Calculating result;
    int SecondsToEnd = result.get_needed_time(HOUR, MIN, SEC);
    char *array_time = new char[10];
    _itoa(SecondsToEnd, array_time, 10);
    std::string str_time = std::string(array_time);
    std::string shutdown_str = "shutdown -s -t " + str_time;
    QProcess::startDetached(shutdown_str.c_str());
    time_tmp = Tmr->time();
    timer->start(1000);
};

void MainWindow::slotTimeout()
{
    time_tmp = time_tmp.addSecs(-1);
    ui->lbl->setText(time_tmp.toString());
}
