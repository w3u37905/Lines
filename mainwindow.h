#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fullscreenwidget.h"
#include "experiment.h"
#include "experimenthandler.h"
#include <QCloseEvent>


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
    void on_setupBtn_clicked();

    void on_subjectTextEdit_textChanged();

    void on_blockSpinBox_valueChanged(int arg1);

    void on_goBtn_clicked();

    void on_fullScreen_closed();

private:
    Ui::MainWindow *ui;
    FullScreenWidget *m_fullScreen;

    Experiment *m_experiment;
    ExperimentHandler *m_handler;
    QString m_sSettingsFile;


    void saveSettings();
    void loadSettings();

protected:
    void closeEvent(QCloseEvent *e);

};

#endif // MAINWINDOW_H
