
#include "mainwindow.h"

#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "calcutate.h"
#include "time_proj.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *wnd = new MainWindow();

    wnd->show();

    return a.exec();
}
