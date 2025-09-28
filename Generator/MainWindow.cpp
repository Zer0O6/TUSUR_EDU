#include "MainWindow.h"
#include "Generator.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QLineSeries* series = new QLineSeries();
    float t = 100.0F;
    float a = 10.0F;
    float step = 0.25F;
    float sizeX = t / step;
    Generator gen(a, 100.0F, 1, t, step);
    float* x = gen.get();
    for (int i = 0; i < sizeX + 1; i++) {
        series->append(i*step, x[i]);
    }

    QChart* chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(-a-a*0.1, a+a*0.1);
    chart->axes(Qt::Horizontal).first()->setRange(0, t);
    chart->setVisible(true);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);

    setCentralWidget(chartView);
    gen.~Generator();
}

MainWindow::~MainWindow()
{}

