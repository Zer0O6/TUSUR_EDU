#include "MainWindow.h"
#include "Generator.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QPushButton* pushButton = new QPushButton();
    pushButton->setText("Push Button");
    ui.verticalLayout->addWidget(pushButton);
    connect(pushButton, &QPushButton::clicked, this, &MainWindow::ClickedSlot);

    QLineSeries* series = new QLineSeries();
    float t = 100.0F;
    float a = 50.0F;
    float w = 50.0F;
    Generator gen(a, w, 1, t);
    float step = gen.getStep();
    float sizeX = t / step;
    float* x = gen.get();
    for (int i = 0; i < sizeX; i++) {
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
    ui.horizontalLayout->addWidget(chartView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);
}
void MainWindow::ClickedSlot() {
    qDebug("click");
}

MainWindow::~MainWindow()
{}

