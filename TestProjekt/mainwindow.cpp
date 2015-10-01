#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "oscillatorsource.h"
#include <QString>
#include <QFileDialog>
#include <QAudioInput>
#include <QAudioDecoder>
#include <QAudioFormat>

int wert = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , audioPlayer(this)

{
    initializeAudio();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeAudio(){
    audioPlayer.setAudioSource(&oscillatorSource);
    audioPlayer.start();
}

void MainWindow::on_pushButton_clicked()
{
    wert++;
    QString sWert = QString::number(wert);
    ui->pushButton->setText("Klick: "+sWert);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    oscillatorSource.setAmplitude(value / 100.);
}

void MainWindow::on_pushButton_2_clicked()
{

}
