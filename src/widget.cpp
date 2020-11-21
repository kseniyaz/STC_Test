#include "widget.h"
#include "ui_widget.h"
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QLineSeries>

Widget::Widget(QString name, QWidget *parent )
    : QWidget(parent), name_(name)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFile* file = new QFile(name_);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Ошибка файла", "Не удалось открыть файл", QMessageBox::Ok);
        delete file;
        return;
    }

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(file);
    xmlReader.readNext();

    QVector<double> X_coordinates(0);
    QVector<double> Y_coordinates(0);
    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement() && xmlReader.name() == "Point")
        {
            foreach(const QXmlStreamAttribute &attr, xmlReader.attributes())
            {
                auto attrName = attr.name().toString();
                auto attrValue = attr.value().toDouble();
                if (attrName == "X") X_coordinates.append(attrValue);
                if (attrName == "Y") Y_coordinates.append(attrValue);
            }
        }
        xmlReader.readNext();
    }
    qDebug() <<"X_coord: "  << X_coordinates;
    qDebug() <<"Y_coord: "  << Y_coordinates;
    file->close();
    delete file;
    chartView = new QChartView();
    ui->gridLayout->addWidget(chartView);

    QScatterSeries *series = new QScatterSeries();

    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);
    for(int item = 0; item < X_coordinates.size(); item++)
    {
        *series << QPointF(X_coordinates[item], Y_coordinates[item]);
    }

    chart = new QChart();
    chart->addSeries(series);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTickCount(0);
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTickCount(0);
    chart->addAxis(axisY, Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
    chartView->setChart(chart);
}


Widget::~Widget()
{
    delete ui;
}



void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0) chart->zoomIn();
    else chart->zoomOut();

    event->accept();
}

