#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include "choosefilewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QString name, QWidget *parent = nullptr );
    ~Widget();
    QString name_;


private:
    Ui::Widget *ui;
    QChartView *chartView;
    QChart *chart;
protected:
    void wheelEvent(QWheelEvent *event);

};
#endif // WIDGET_H
