#ifndef TRIAL_H
#define TRIAL_H

#include <QtCore>


enum LongerLineAnswer_T
{
    e_none,
    e_left,
    e_right,
    e_equal
};


class Trial
{
public:
    Trial();


    bool                   isValid           (){ return m_valid;            };
    qreal                  getLatency        (){ return m_latency;          };
    qreal                  getDistance       (){ return m_distance;         };
    qreal                  getLengthLeftLine (){ return m_lengthLeftLine;   };
    qreal                  getLengthRightLine(){ return m_lengthRightLine;  };
    bool                   isCorrect         (){ return m_correct;          };
    LongerLineAnswer_T     getAnswer         (){ return m_answer;           };

    void setValid          (bool               valid          ){m_valid           = valid;          };
    void setLatency        (qreal              latency        ){m_latency         = latency;        };
    void setDistance       (qreal              distance       ){m_distance        = distance;       };
    void setLengthLeftLine (qreal              lengthLeftLine ){m_lengthLeftLine  = lengthLeftLine; };
    void setLengthRightLine(qreal              lengthRightLine){m_lengthRightLine = lengthRightLine;};
    void setCorrect        (bool               correct        ){m_correct         = correct;        };
    void setAnswer         (LongerLineAnswer_T answer         ){m_answer          = answer;         };


private:
    bool                   m_valid;
    qreal                  m_latency;
    qreal                  m_distance;
    qreal                  m_lengthLeftLine;
    qreal                  m_lengthRightLine;
    bool                   m_correct;
    LongerLineAnswer_T     m_answer;
};

#endif // TRIAL_H
