#include "experiment.h"

Experiment *Experiment::m_instance = nullptr;


Experiment::Experiment() :
    m_subject(""),
    m_block(1),
    m_screenWidth(0.6),
    m_lineThickness(0.01),
    m_lengthStep(0.001),
    m_minLength(0.2),
    m_maxLength(0.3),
    m_diferrentDistances(3),
    m_distance1(0.1),
    m_distance2(0.05),
    m_distance3(0.2),
    m_distance4(0.12),
    m_distance5(0.15),
    m_numberOfTrials(10),
    m_maxAnswerTime(10),
    m_showAnswer(0.5),
    m_showBlackScreen(0.5),
    m_dataPath(""),
    m_taskName("Lines")
{
}

Experiment *Experiment::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new Experiment();
    }

    return m_instance;
}
