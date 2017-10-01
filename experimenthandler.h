#ifndef EXPERIMENTHANDLER_H
#define EXPERIMENTHANDLER_H

#include <QObject>
#include "fullscreenwidget.h"


class ExperimentHandler : public QObject
{
    Q_OBJECT

public:
    explicit ExperimentHandler(FullScreenWidget *screen, QObject *parent = nullptr);


private slots:
    void onTrialTimeout();
    void onShowAnswerTimeout();

    void onLeftBtnPushed();
    void onRightBtnPushed();
    void onUpBtnPushed();



private:

    void runNextTrial();
    void setUpTimers();
    void setUpScreenDetails();
    qreal toPixels(qreal meters);
    void setUpExperiment();
    void setUpEvents();
    void finishExperiment();
    void trialResults(LongerLineAnswer_T  answer);
    void writeCSVfile();
    void saveLatency();

    FullScreenWidget *m_screen;
    Experiment       *m_experiment;
    QTimer           *m_trialTimer;
    QTimer           *m_showAnswerTimer;

    qreal            m_pixelsPerMeter;
    uint             m_screenHeight;
    uint             m_screenWidth;
    uint             m_runningTrial;


};

#endif // EXPERIMENTHANDLER_H
