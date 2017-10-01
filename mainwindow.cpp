#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setupdialog.h"
#include <QSettings>

#include "experimenthandler.h"


#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_experiment = Experiment::getInstance();

    m_sSettingsFile = QDir::currentPath() + "/config.ini";

    qDebug() << m_sSettingsFile;

    // load ini file
    loadSettings();


    ui->subjectTextEdit->setText(m_experiment->getSubject());
    ui->blockSpinBox->setValue(m_experiment->getBlock());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setupBtn_clicked()
{
    //hide();
    SetupDialog setupDlg;
    setupDlg.setModal(true);
    setupDlg.exec();
}

void MainWindow::on_subjectTextEdit_textChanged()
{
    m_experiment->setSubject(ui->subjectTextEdit->toPlainText());
}

void MainWindow::on_blockSpinBox_valueChanged(int arg1)
{
    m_experiment->setBlock(arg1);
}

void MainWindow::on_goBtn_clicked()
{

    hide();
    m_fullScreen = new FullScreenWidget();
    connect( m_fullScreen, SIGNAL(fullscreenClosed()), this, SLOT(on_fullScreen_closed()) );

    m_handler = new ExperimentHandler(m_fullScreen,this);
}

void MainWindow::on_fullScreen_closed()
{
    qDebug() << "on_fullScreen_closed";

    show();
    delete m_handler;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    saveSettings();

    e->accept();
}


void MainWindow::saveSettings()
{
    QSettings settings( m_sSettingsFile, QSettings::IniFormat);

    settings.setValue("subject", m_experiment->getSubject());
    settings.setValue("block", m_experiment->getBlock());
    settings.setValue("screenWidth", m_experiment->getScreenWidth());
    settings.setValue("lineThickness", m_experiment->getLineThickness());
    settings.setValue("lengthStep", m_experiment->getLengthStep());
    settings.setValue("minLength", m_experiment->getMinLength());
    settings.setValue("maxLength", m_experiment->getMaxLength());
    settings.setValue("diferrentDistances", m_experiment->getDiferrentDistances());
    settings.setValue("distance1", m_experiment->getDistance1());
    settings.setValue("distance2", m_experiment->getDistance2());
    settings.setValue("distance3", m_experiment->getDistance3());
    settings.setValue("distance4", m_experiment->getDistance4());
    settings.setValue("distance5", m_experiment->getDistance5());
    settings.setValue("numberOfTrials", m_experiment->getNumberOfTrials());
    settings.setValue("maxAnswerTime", m_experiment->getMaxAnswerTime());
    settings.setValue("showAnswer", m_experiment->getShowAnswer());
    settings.setValue("dataPath", m_experiment->getDataPath());
    settings.setValue("taskName", m_experiment->getTaskName());

    //settings.sync();
}

void MainWindow::loadSettings()
{
    QSettings settings( m_sSettingsFile, QSettings::IniFormat);

    m_experiment->setSubject(settings.value("subject", "").toString());
    m_experiment->setBlock(settings.value("block", "").toUInt());
    m_experiment->setScreenWidth(settings.value("screenWidth", "").toDouble());
    m_experiment->setLineThickness(settings.value("lineThickness", "").toDouble());
    m_experiment->setLengthStep(settings.value("lengthStep", "").toDouble());
    m_experiment->setMinLength(settings.value("minLength", "").toDouble());
    m_experiment->setMaxLength(settings.value("maxLength", "").toDouble());
    m_experiment->setDiferrentDistances(settings.value("diferrentDistances", "").toUInt());
    m_experiment->setDistance1(settings.value("distance1", "").toDouble());
    m_experiment->setDistance2(settings.value("distance2", "").toDouble());
    m_experiment->setDistance3(settings.value("distance3", "").toDouble());
    m_experiment->setDistance4(settings.value("distance4", "").toDouble());
    m_experiment->setDistance5(settings.value("distance5", "").toDouble());
    m_experiment->setNumberOfTrials(settings.value("numberOfTrials", "").toUInt());
    m_experiment->setMaxAnswerTime(settings.value("maxAnswerTime", "").toDouble());
    m_experiment->setShowAnswer(settings.value("showAnswer", "").toDouble());
    m_experiment->setDataPath(settings.value("dataPath", "").toString());
    m_experiment->setTaskName(settings.value("taskName", "").toString());

}



