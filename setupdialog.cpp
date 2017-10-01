#include "setupdialog.h"
#include "ui_setupdialog.h"

SetupDialog::SetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupDialog)
{
    ui->setupUi(this);

    m_experiment = Experiment::getInstance();
    m_table = ui->tableWidget;

    m_table->setRowCount(NUMOFCOL);
    m_table->setColumnCount(2);

    m_table->setHorizontalHeaderLabels({"Key","Value"});

    m_table->verticalHeader()->setVisible(false);
    m_table->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    m_table->verticalHeader()->setDefaultSectionSize(24);

    m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    m_table->setColumnWidth(0,170);
    m_table->setColumnWidth(1,m_table->width() - 175);


    m_table->setItem(SCREENWIDTH       , 0, new  QTableWidgetItem("screenWidth (meters)"));
    m_table->setItem(LINETHICKNESS     , 0, new  QTableWidgetItem("lineThickness (meters)"));
    m_table->setItem(LENGTHSTEP        , 0, new  QTableWidgetItem("lengthStep (meters)"));
    m_table->setItem(MINLENGTH         , 0, new  QTableWidgetItem("minLength (meters)"));
    m_table->setItem(MAXLENGTH         , 0, new  QTableWidgetItem("maxLength (meters)"));
    m_table->setItem(DIFERRENTDISTANCES, 0, new  QTableWidgetItem("diferrentDistances [1-5]"));
    m_table->setItem(DISTANCE1         , 0, new  QTableWidgetItem("distance1 (meters)"));
    m_table->setItem(DISTANCE2         , 0, new  QTableWidgetItem("distance2 (meters)"));
    m_table->setItem(DISTANCE3         , 0, new  QTableWidgetItem("distance3 (meters)"));
    m_table->setItem(DISTANCE4         , 0, new  QTableWidgetItem("distance4 (meters)"));
    m_table->setItem(DISTANCE5         , 0, new  QTableWidgetItem("distance5 (meters)"));
    m_table->setItem(NUMBEROFTRIALS    , 0, new  QTableWidgetItem("numberOfTrials"));
    m_table->setItem(MAXANSWERTIME     , 0, new  QTableWidgetItem("maxAnswerTime (sec)"));
    m_table->setItem(SHOWANSWER        , 0, new  QTableWidgetItem("showAnswer (sec)"));
    m_table->setItem(SHOWBLACKSCREEN   , 0, new  QTableWidgetItem("showBlackScreen (sec)"));
    m_table->setItem(DATAPATH          , 0, new  QTableWidgetItem("dataPath"));
    m_table->setItem(TASKNAME          , 0, new  QTableWidgetItem("taskName"));

    m_table->setItem(SCREENWIDTH       , 1, new  QTableWidgetItem(""));
    m_table->setItem(LINETHICKNESS     , 1, new  QTableWidgetItem(""));
    m_table->setItem(LENGTHSTEP        , 1, new  QTableWidgetItem(""));
    m_table->setItem(MINLENGTH         , 1, new  QTableWidgetItem(""));
    m_table->setItem(MAXLENGTH         , 1, new  QTableWidgetItem(""));
    m_table->setItem(DIFERRENTDISTANCES, 1, new  QTableWidgetItem(""));
    m_table->setItem(DISTANCE1         , 1, new  QTableWidgetItem(""));
    m_table->setItem(DISTANCE2         , 1, new  QTableWidgetItem(""));
    m_table->setItem(DISTANCE3         , 1, new  QTableWidgetItem(""));
    m_table->setItem(DISTANCE4         , 1, new  QTableWidgetItem(""));
    m_table->setItem(DISTANCE5         , 1, new  QTableWidgetItem(""));
    m_table->setItem(NUMBEROFTRIALS    , 1, new  QTableWidgetItem(""));
    m_table->setItem(MAXANSWERTIME     , 1, new  QTableWidgetItem(""));
    m_table->setItem(SHOWANSWER        , 1, new  QTableWidgetItem(""));
    m_table->setItem(SHOWBLACKSCREEN   , 1, new  QTableWidgetItem(""));
    m_table->setItem(DATAPATH          , 1, new  QTableWidgetItem(""));
    m_table->setItem(TASKNAME          , 1, new  QTableWidgetItem(""));


    setupValues();

}

void SetupDialog::setupValues()
{
    m_table->item(SCREENWIDTH		,1)->setText(QString::number(m_experiment->getScreenWidth()));
    m_table->item(LINETHICKNESS     ,1)->setText(QString::number(m_experiment->getLineThickness()));
    m_table->item(LENGTHSTEP        ,1)->setText(QString::number(m_experiment->getLengthStep()));
    m_table->item(MINLENGTH         ,1)->setText(QString::number(m_experiment->getMinLength()));
    m_table->item(MAXLENGTH         ,1)->setText(QString::number(m_experiment->getMaxLength()));
    m_table->item(DIFERRENTDISTANCES,1)->setText(QString::number(m_experiment->getDiferrentDistances()));
    m_table->item(DISTANCE1         ,1)->setText(QString::number(m_experiment->getDistance1()));
    m_table->item(DISTANCE2         ,1)->setText(QString::number(m_experiment->getDistance2()));
    m_table->item(DISTANCE3         ,1)->setText(QString::number(m_experiment->getDistance3()));
    m_table->item(DISTANCE4         ,1)->setText(QString::number(m_experiment->getDistance4()));
    m_table->item(DISTANCE5         ,1)->setText(QString::number(m_experiment->getDistance5()));
    m_table->item(NUMBEROFTRIALS    ,1)->setText(QString::number(m_experiment->getNumberOfTrials()));
    m_table->item(MAXANSWERTIME     ,1)->setText(QString::number(m_experiment->getMaxAnswerTime()));
    m_table->item(SHOWANSWER        ,1)->setText(QString::number(m_experiment->getShowAnswer()));
    m_table->item(SHOWBLACKSCREEN   ,1)->setText(QString::number(m_experiment->getShowBlackScreen()));
    m_table->item(DATAPATH          ,1)->setText(m_experiment->getDataPath());
    m_table->item(TASKNAME          ,1)->setText(m_experiment->getTaskName());
}

SetupDialog::~SetupDialog()
{
    delete ui;
}

void SetupDialog::closeEvent(QCloseEvent *e)
{
    saveValues();
    e->accept();
}

void SetupDialog::saveValues()
{
    m_experiment->setScreenWidth(m_table->item(SCREENWIDTH,1)->text().toDouble());
    m_experiment->setLineThickness(m_table->item(LINETHICKNESS,1)->text().toDouble());
    m_experiment->setLengthStep(m_table->item(LENGTHSTEP,1)->text().toDouble());
    m_experiment->setMinLength(m_table->item(MINLENGTH,1)->text().toDouble());
    m_experiment->setMaxLength(m_table->item(MAXLENGTH,1)->text().toDouble());
    m_experiment->setDiferrentDistances(m_table->item(DIFERRENTDISTANCES,1)->text().toUInt());
    m_experiment->setDistance1(m_table->item(DISTANCE1,1)->text().toDouble());
    m_experiment->setDistance2(m_table->item(DISTANCE2,1)->text().toDouble());
    m_experiment->setDistance3(m_table->item(DISTANCE3,1)->text().toDouble());
    m_experiment->setDistance4(m_table->item(DISTANCE4,1)->text().toDouble());
    m_experiment->setDistance5(m_table->item(DISTANCE5,1)->text().toDouble());
    m_experiment->setNumberOfTrials(m_table->item(NUMBEROFTRIALS,1)->text().toUInt());
    m_experiment->setMaxAnswerTime(m_table->item(MAXANSWERTIME,1)->text().toDouble());
    m_experiment->setShowAnswer(m_table->item(SHOWANSWER,1)->text().toDouble());
    m_experiment->setShowBlackScreen(m_table->item(SHOWBLACKSCREEN,1)->text().toDouble());
    m_experiment->setDataPath(m_table->item(DATAPATH,1)->text());
    m_experiment->setTaskName(m_table->item(TASKNAME,1)->text());
}






