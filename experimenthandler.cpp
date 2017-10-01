#include "experimenthandler.h"

#include <QDebug>

#include <QtGui>
#include <QtCore>

#include <qtimer.h>
#include <QDesktopWidget>
#include <QMessageBox>



#define SEC 1000


ExperimentHandler::ExperimentHandler(FullScreenWidget *screen,QObject *parent) :
    QObject(parent)
{
    m_screen = screen;
    m_experiment = Experiment::getInstance();

    setUpScreenDetails();
    setUpExperiment();
    setUpTimers();
    setUpEvents();


    m_runningTrial=0;
    runNextTrial();

}

void ExperimentHandler::onShowAnswerTimeout()
{
    m_runningTrial++;
    runNextTrial();
}


void ExperimentHandler::runNextTrial()
{

    qDebug() << "runNextTrial";

    if(m_experiment->getNumberOfTrials() <= m_runningTrial)
    {
        finishExperiment();
    }
    else
    {

        m_screen->setLinesWhite();

        Trial trial = m_experiment->getTrials().at(m_runningTrial);

        qreal centerX = m_screenWidth/2.0;
        qreal centerY = m_screenHeight/2.0;


        qreal distance = toPixels(trial.getDistance());
        qreal leftLine = toPixels(trial.getLengthLeftLine());
        qreal rightLine = toPixels(trial.getLengthRightLine());


        qreal leftX = centerX - distance/2;
        qreal rightX = centerX + distance/2;

        m_screen->setLeftLine(leftX, centerY - leftLine/2 ,leftX , centerY + leftLine/2);
        m_screen->setRightLine(rightX, centerY - rightLine/2, rightX, centerY + rightLine/2);

        m_trialTimer->start((int)(m_experiment->getMaxAnswerTime()*SEC));

    }

}

void ExperimentHandler::setUpTimers()
{
    m_trialTimer = new QTimer(this);
    m_showAnswerTimer = new QTimer(this);
    m_trialTimer->setSingleShot(true);
    m_showAnswerTimer->setSingleShot(true);
    connect(m_trialTimer, SIGNAL(timeout()),this, SLOT(onTrialTimeout()));
    connect(m_showAnswerTimer, SIGNAL(timeout()),this, SLOT(onShowAnswerTimeout()));
}


void ExperimentHandler::setUpScreenDetails()
{
   qreal screenWidth = m_experiment->getScreenWidth();

   QDesktopWidget widget;
   QRect rec = widget.availableGeometry(widget.primaryScreen());


   m_screenHeight = rec.height();
   m_screenWidth = rec.width();

   qDebug() << m_screenWidth << " x " << m_screenHeight ;


   m_pixelsPerMeter = m_screenWidth/screenWidth;

}

qreal ExperimentHandler::toPixels(qreal meters)
{
    return meters*m_pixelsPerMeter;
}



void ExperimentHandler::setUpExperiment()
{
    m_screen->setLinesThickness(toPixels(m_experiment->getLineThickness()));

    qreal maxLength = m_experiment->getMaxLength();
    qreal minLength = m_experiment->getMinLength();
    qreal lengthStep = m_experiment->getLengthStep();

    uint lengthNumbers = (int)((maxLength - minLength)/lengthStep) + 1;

    if(m_experiment->getTrials().size())
        m_experiment->getTrials().clear();

    for(uint i=0; i<m_experiment->getNumberOfTrials(); i++)
    {
        Trial trial;

        // generate random values for m_lengthLeftLine, m_lengthRightLine

        int randomValue = qrand() % lengthNumbers;
        qreal leftLine = randomValue*lengthStep + minLength;
        trial.setLengthLeftLine(leftLine);

        randomValue = qrand() % lengthNumbers;
        qreal rightLine = randomValue*lengthStep + minLength;
        trial.setLengthRightLine(rightLine);

        randomValue = qrand() % m_experiment->getDiferrentDistances() + 1;

        switch(randomValue)
        {
        case 1: trial.setDistance(m_experiment->getDistance1()); break;
        case 2: trial.setDistance(m_experiment->getDistance2()); break;
        case 3: trial.setDistance(m_experiment->getDistance3()); break;
        case 4: trial.setDistance(m_experiment->getDistance4()); break;
        case 5: trial.setDistance(m_experiment->getDistance5()); break;
        default:break;
        }

        m_experiment->getTrials().push_back(trial);
    }

}

void ExperimentHandler::setUpEvents()
{
    connect(m_screen, SIGNAL(leftBtnPushed()),this, SLOT(onLeftBtnPushed()));
    connect(m_screen, SIGNAL(rightBtnPushed()),this, SLOT(onRightBtnPushed()));
    connect(m_screen, SIGNAL(upBtnPushed()),this, SLOT(onUpBtnPushed()));

}

void ExperimentHandler::onLeftBtnPushed()
{
    qDebug()<< "onLeftBtnPushed";

    saveLatency();
    m_screen->setLeftLineBlue();
    m_trialTimer->stop();

    trialResults(e_left);

    m_showAnswerTimer->start((int)(m_experiment->getShowAnswer()*SEC));
}

void ExperimentHandler::onRightBtnPushed()
{
    qDebug()<< "onRightBtnPushed";

    saveLatency();
    m_screen->setRightLineBlue();
    m_trialTimer->stop();

    trialResults(e_right);

    m_showAnswerTimer->start((int)(m_experiment->getShowAnswer()*SEC));
}

void ExperimentHandler::onUpBtnPushed()
{
    qDebug()<< "onUpBtnPushed";

    saveLatency();
    m_screen->setLinesBlue();
    m_trialTimer->stop();

    trialResults(e_equal);

    m_showAnswerTimer->start((int)(m_experiment->getShowAnswer()*SEC));
}


void ExperimentHandler::onTrialTimeout()
{
    qDebug() << "onTrialTimeout";

    //Answer: None
    saveLatency();
    trialResults(e_none);

    m_screen->setLinesRed();
    m_showAnswerTimer->start((int)(m_experiment->getShowAnswer()*SEC));
}

void ExperimentHandler::trialResults(LongerLineAnswer_T  answer)
{
    //m_experiment->getTrials()[m_runningTrial].setAnswer(e_none);

    Trial &trial = m_experiment->getTrials()[m_runningTrial];;

    trial.setAnswer(answer);

    if(answer==e_none)
    {
        trial.setValid(false);
    }
    else
    {
        trial.setValid(true);
    }

    switch (answer)
    {
    case e_left:
    {
        if(trial.getLengthLeftLine() > trial.getLengthRightLine())
        {
            trial.setCorrect(true);
        }
        break;
    }
    case e_right:
    {
        if(trial.getLengthLeftLine() < trial.getLengthRightLine())
        {
            trial.setCorrect(true);
        }
        break;
    }
    case e_equal:
        if(trial.getLengthLeftLine() == trial.getLengthRightLine())
        {
            trial.setCorrect(true);
        }
        break;
    default: break;
    }


}

void ExperimentHandler::finishExperiment()
{
    // write results
    writeCSVfile();

    if (QMessageBox::Ok == QMessageBox(QMessageBox::Information, "Lines", "Thank you!", QMessageBox::Ok).exec())
    {
        m_screen->close();
    }
}


void ExperimentHandler::writeCSVfile()
{
    QString path(m_experiment->getDataPath());
    QString fileName;

    fileName = "/" + m_experiment->getTaskName() + " "
             + m_experiment->getSubject() + " "
             + "Block " + QString::number(m_experiment->getBlock()) + " "
             + QDateTime::currentDateTime().toString("dd-MM-yyyy hh-mm-ss")
             + ".csv";

    QFile file(path + fileName);

//    qDebug() << path + fileName ;

    if (file.open(QFile::WriteOnly|QFile::Truncate))
    {

        QTextStream stream(&file);

        stream << "Name;Block;TrialNum;Valid;Latency;Distance;LeftLineLength;RightLineLength;Answer;Correct\n";

        for(int i=0; i<m_experiment->getTrials().size(); i++)
        {
            Trial &trial = m_experiment->getTrials()[i];

            stream << m_experiment->getSubject()   << ";"
                   << m_experiment->getBlock()     << ";"
                   << (i+1)                        << ";"
                   << trial.isValid()              << ";"
                   << trial.getLatency()           << ";"
                   << trial.getDistance()          << ";"
                   << trial.getLengthLeftLine()    << ";"
                   << trial.getLengthRightLine()   << ";"
                   << trial.getAnswer()            << ";"
                   << trial.isCorrect()            << ";"
                   <<"\n";
        }
        file.close();
    }

}


void ExperimentHandler::saveLatency()
{
    Trial &trial = m_experiment->getTrials()[m_runningTrial];

    int msecLatency = m_trialTimer->interval() - m_trialTimer->remainingTime();
    qreal latency = (qreal)(msecLatency)/SEC;
    trial.setLatency(latency);
}







