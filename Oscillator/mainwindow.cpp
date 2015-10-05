#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAudioInput>
#include <QAudioDecoder>
#include <QAudioFormat>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , audioPlayer(this)
    , check(false)

{
    ui->setupUi(this);
    initializeAudio();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initializeAudio(){
    on_frequencySlider_valueChanged(ui->frequencySlider->value());
    on_gainSlider_valueChanged(ui->gainSlider->value());

    audioPlayer.setAudioSource(&oscillatorSource);
}



void MainWindow::on_frequencySlider_valueChanged(int value)
{
    // 0 ... 100% --> 100Hz ... 10000Hz
    float scaledValue = 2 * value / 100.f + 2;
    float frequency = pow(10, scaledValue);

    ui->frequencyLabel->setText(QString::number((int)frequency));
    oscillatorSource.setFrequency(frequency);
}

void MainWindow::on_waveformCombobox_activated(int index)
{
    oscillatorSource.setSelectedOscillator(index);
}

void MainWindow::on_gainSlider_valueChanged(int value)
{
    oscillatorSource.setGain(value / 100.f);
}

void MainWindow::on_startButton_clicked()
{
    audioPlayer.start();
}

void MainWindow::on_pauseButton_clicked()
{
    audioPlayer.stop();
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{

    if(check == false) {
        audioPlayer.start();
    }
            if(event->key() == Qt::Key_C) {
                oscillatorSource.setFrequency(2093.00);
            }
            else if(event->key() == Qt::Key_D) {
                oscillatorSource.setFrequency(2349.32);
            }
            else if(event->key() == Qt::Key_E) {
                oscillatorSource.setFrequency(2637.02);
            }
            else if(event->key() == Qt::Key_F) {
                oscillatorSource.setFrequency(2793.83);
            }
            else if(event->key() == Qt::Key_G) {
                oscillatorSource.setFrequency(3135.96);
            }
            else if(event->key() == Qt::Key_A) {
                oscillatorSource.setFrequency(3520.00);
            }
            else if(event->key() == Qt::Key_H) {
                oscillatorSource.setFrequency(3951.07);
            }

            check = true;
}

void MainWindow::keyReleaseEvent(QKeyEvent * event) {
    audioPlayer.stop();
    check = false;
}
