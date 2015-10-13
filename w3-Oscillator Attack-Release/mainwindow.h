#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:

    void on_frequencySlider_valueChanged(int value);

    void on_waveformCombobox_activated(int index);

    void on_gainSlider_valueChanged(int value);
    void on_note_1_clicked(bool checked);
    void on_note_2_clicked(bool checked);
    void on_note_3_clicked(bool checked);
    void on_note_4_clicked(bool checked);
    void on_note_5_clicked(bool checked);
    void on_note_6_clicked(bool checked);
    void on_note_7_clicked(bool checked);
    void on_note_8_clicked(bool checked);
    void on_note_9_clicked(bool checked);
    void on_note_10_clicked(bool checked);
    void on_note_11_clicked(bool checked);
    void on_note_12_clicked(bool checked);


private:
    void initializeAudio();
    Ui::MainWindow *ui;
    OscillatorSource oscillatorSource;
    AudioPlayer audioPlayer;
};

#endif // MAINWINDOW_H
