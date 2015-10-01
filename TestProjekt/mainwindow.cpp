#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

int wert = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    wert++;
    QString sWert = QString::number(wert);
    ui->pushButton->setText("Klick: "+sWert);
}
