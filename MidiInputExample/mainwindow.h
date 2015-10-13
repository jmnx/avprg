#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "midiinput.h"

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
    void onMidiNoteOff(const int chan, const int note, const int vel);
    void onMidiNoteOn(const int chan, const int note, const int vel);
    void on_comboBox_activated(const QString &arg1);
private:
    void initializeMidi();
    void prependMessage(QString message);
private:
    Ui::MainWindow *ui;
    drumstick::rt::MIDIInput midiInput;
};

#endif // MAINWINDOW_H
