#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include <QTableWidget>

#include "experiment.h"
#include <QCloseEvent>

namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupDialog(QWidget *parent = 0);
    ~SetupDialog();

private:

    void setupValues();
    void saveValues();



    Ui::SetupDialog *ui;

    QTableWidget *m_table;
    Experiment *m_experiment;

    enum KEY
    {
        SCREENWIDTH,
        LINETHICKNESS,
        LENGTHSTEP,
        MINLENGTH,
        MAXLENGTH,
        DIFERRENTDISTANCES,
        DISTANCE1,
        DISTANCE2,
        DISTANCE3,
        DISTANCE4,
        DISTANCE5,
        NUMBEROFTRIALS,
        MAXANSWERTIME,
        SHOWANSWER,
        DATAPATH,
        TASKNAME
    };


protected:

    void closeEvent(QCloseEvent *e);

};

#endif // SETUPDIALOG_H
