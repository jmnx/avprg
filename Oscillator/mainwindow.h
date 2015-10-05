#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QFile>
#include <QAudioOutput>
#include "audioplayer.h"
#include "oscillatorsource.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private slots:

    void on_frequencySlider_valueChanged(int value);

    void on_waveformCombobox_activated(int index);

    void on_gainSlider_valueChanged(int value);

    void on_startButton_clicked();

    void on_pauseButton_clicked();

private:
    void initializeAudio();
    Ui::MainWindow *ui;
    OscillatorSource oscillatorSource;
    AudioPlayer audioPlayer;
    bool check;
};

#endif // MAINWINDOW_H
