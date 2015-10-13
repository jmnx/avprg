#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeMidi();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initializeMidi(){
    QStringList connections = midiInput.connections(true);
    ui->comboBox->addItems(connections);
    if (connections.size() > 0){
        on_comboBox_activated(ui->comboBox->currentText());
    }

    connect(&midiInput, SIGNAL(midiNoteOn(const int, const int, const int)), this, SLOT(onMidiNoteOn(const int, const int, const int)));
    connect(&midiInput, SIGNAL(midiNoteOff(const int, const int, const int)), this, SLOT(onMidiNoteOff(const int, const int, const int)));

}

void MainWindow::on_comboBox_activated(const QString &string)
{
    midiInput.open(string);
}

void MainWindow::onMidiNoteOff(const int chan, const int note, const int vel){
    prependMessage(QString("note off: ch=%1 note=%2 vel=%3\n").arg(chan).arg(note).arg(vel));
}

void MainWindow::onMidiNoteOn(const int chan, const int note, const int vel){
    if (vel == 0){
        onMidiNoteOff(chan, note, vel);
    }
    prependMessage(QString("note on:  ch=%1 note=%2 vel=%3\n").arg(chan).arg(note).arg(vel));
}
void MainWindow::prependMessage(QString message){
    ui->plainTextEdit->moveCursor(QTextCursor::Start);
    ui->plainTextEdit->insertPlainText(message);
}

