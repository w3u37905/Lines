#ifndef FULLSCREENWIDGET_H
#define FULLSCREENWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QKeyEvent>

#include "experiment.h"

namespace Ui {
class FullScreenWidget;
}

class FullScreenWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FullScreenWidget(QWidget *parent = 0);
    ~FullScreenWidget();


    void setLinesThickness(qreal lineThickness);
    void setLinesWhite();
    void setLinesBlue();
    void setLinesRed();
    void setLinesBlack();
    void setLeftLineBlue();
    void setRightLineBlue();

    void setLeftLine(qreal x1, qreal y1, qreal x2, qreal y2);
    void setRightLine(qreal x1, qreal y1, qreal x2, qreal y2);



private:
    Ui::FullScreenWidget *ui;

    QPen     m_leftPen;
    QPen     m_rightPen;
    QLineF   m_leftLine;
    QLineF   m_rightLine;

protected:

    //Event Handlers
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void closeEvent ( QCloseEvent * e);

signals:
    void fullscreenClosed();
    void leftBtnPushed();
    void rightBtnPushed();
    void upBtnPushed();


};

#endif // FULLSCREENWIDGET_H
