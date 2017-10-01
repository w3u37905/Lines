#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <qstring.h>
#include <qvector.h>
#include "trial.h"


class Experiment
{
public:

    static Experiment *getInstance();

    //getters
    QString        getSubject           (){ return m_subject;            };
    uint           getBlock             (){ return m_block;              };
    qreal          getScreenWidth       (){ return m_screenWidth;        };
    qreal          getLineThickness     (){ return m_lineThickness;      };
    qreal          getLengthStep        (){ return m_lengthStep;         };
    qreal          getMinLength         (){ return m_minLength;          };
    qreal          getMaxLength         (){ return m_maxLength;          };
    uint           getDiferrentDistances(){ return m_diferrentDistances; };
    qreal          getDistance1         (){ return m_distance1;          };
    qreal          getDistance2         (){ return m_distance2;          };
    qreal          getDistance3         (){ return m_distance3;          };
    qreal          getDistance4         (){ return m_distance4;          };
    qreal          getDistance5         (){ return m_distance5;          };
    uint           getNumberOfTrials    (){ return m_numberOfTrials;     };
    qreal          getMaxAnswerTime     (){ return m_maxAnswerTime;      };
    qreal          getShowAnswer        (){ return m_showAnswer;         };
    QString        getDataPath          (){ return m_dataPath;           };
    QString        getTaskName          (){ return m_taskName;           };
    QVector<Trial>&getTrials            (){ return m_trials;             };

    //setters
    void setSubject            (QString subject              ){m_subject            = subject;              };
    void setBlock              (uint    block                ){m_block              = block;                };
    void setScreenWidth        (qreal   screenWidth          ){m_screenWidth        = screenWidth;          };
    void setLineThickness      (qreal   lineThickness        ){m_lineThickness      = lineThickness;        };
    void setLengthStep         (qreal   lengthStep           ){m_lengthStep         = lengthStep;           };
    void setMinLength          (qreal   minLength            ){m_minLength          = minLength;            };
    void setMaxLength          (qreal   maxLength            ){m_maxLength          = maxLength;            };
    void setDiferrentDistances (uint    diferrentDistances   ){m_diferrentDistances = diferrentDistances;   };
    void setDistance1          (qreal   distance1            ){m_distance1          = distance1;            };
    void setDistance2          (qreal   distance2            ){m_distance2          = distance2;            };
    void setDistance3          (qreal   distance3            ){m_distance3          = distance3;            };
    void setDistance4          (qreal   distance4            ){m_distance4          = distance4;            };
    void setDistance5          (qreal   distance5            ){m_distance5          = distance5;            };
    void setNumberOfTrials     (uint    numberOfTrials       ){m_numberOfTrials     = numberOfTrials;       };
    void setMaxAnswerTime      (qreal   maxAnswerTime        ){m_maxAnswerTime      = maxAnswerTime;        };
    void setShowAnswer         (qreal   showAnswer           ){m_showAnswer         = showAnswer;           };
    void setDataPath           (QString dataPath             ){m_dataPath           = dataPath;             };
    void setTaskName           (QString taskName             ){m_taskName           = taskName;             };
    void setTrials             (QVector<Trial> &trials){m_trials = trials;}

private:
    Experiment();
    Experiment(Experiment const&){};
    Experiment& operator=(Experiment const&){};

    static Experiment *m_instance;

    //DB

    QString         m_subject;
    uint            m_block;
    qreal           m_screenWidth;
    qreal           m_lineThickness;
    qreal           m_lengthStep;
    qreal           m_minLength;
    qreal           m_maxLength;
    uint            m_diferrentDistances;
    qreal           m_distance1;
    qreal           m_distance2;
    qreal           m_distance3;
    qreal           m_distance4;
    qreal           m_distance5;
    uint            m_numberOfTrials;
    qreal           m_maxAnswerTime;
    qreal           m_showAnswer;
    QString         m_dataPath;
    QString         m_taskName;
    QVector<Trial>  m_trials;

};

#endif // EXPERIMENT_H
