#include "fullscreenwidget.h"
#include "ui_fullscreenwidget.h"

#include <QDebug>

FullScreenWidget::FullScreenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullScreenWidget)
{
    ui->setupUi(this);

    showFullScreen();
    setCursor(Qt::BlankCursor);
}

FullScreenWidget::~FullScreenWidget()
{
    delete ui;
}

void FullScreenWidget::paintEvent(QPaintEvent *e)
{
    qDebug() << "paintEvent";

    QPainter painter(this);

    painter.setPen(m_leftPen);
    painter.drawLine(m_leftLine);
    painter.setPen(m_rightPen);
    painter.drawLine(m_rightLine);

    e->accept();

}

 void FullScreenWidget::keyPressEvent(QKeyEvent *e)
 {
     if(e->key()== Qt::Key_Escape)
     {
         //emit fullscreenClosed();
         this->close();
     }
     else if(e->key() == Qt::Key_Left)
     {
         emit leftBtnPushed();
     }
     else if(e->key() == Qt::Key_Right)
     {
         emit rightBtnPushed();
     }
     else if(e->key() == Qt::Key_Up)
     {
         emit upBtnPushed();
     }
 }


 void FullScreenWidget::setLinesThickness(qreal lineThickness)
 {
     qDebug() << "setLinesThickness";

     m_leftPen.setWidthF(lineThickness);
     m_rightPen.setWidthF(lineThickness);
     update();
 }

 void FullScreenWidget::setLinesWhite()
 {
     qDebug() << "setLinesWhite";

     m_leftPen.setColor(Qt::white);
     m_rightPen.setColor(Qt::white);
     update();
 }

 void FullScreenWidget::setLinesBlue()
 {
     qDebug() << "setLinesBlue";

     m_leftPen.setColor(Qt::blue);
     m_rightPen.setColor(Qt::blue);
     update();
 }

void FullScreenWidget::setLinesRed()
{
    qDebug() << "setLinesRed";

    m_leftPen.setColor(Qt::red);
    m_rightPen.setColor(Qt::red);
    update();
}

void FullScreenWidget::setLeftLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    qDebug() << "setLeftLine";

    m_leftLine.setLine(x1,y1,x2,y2);
    update();
}

void FullScreenWidget::setRightLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    qDebug() << "setRightLine";

    m_rightLine.setLine(x1,y1,x2,y2);
    update();
}

void FullScreenWidget::setLeftLineBlue()
{

    qDebug() << "setLeftLineBlue";

    m_leftPen.setColor(Qt::blue);
    update();
}

void FullScreenWidget::setRightLineBlue()
{

    qDebug() << "setRightLineBlue";

    m_rightPen.setColor(Qt::blue);
    update();
}

void FullScreenWidget::closeEvent( QCloseEvent * e)
{
    emit fullscreenClosed();
    e->accept();
}






