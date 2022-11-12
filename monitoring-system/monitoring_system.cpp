#include <QString>
#include <QtUiTools/QUiLoader>

#include "monitoring_system.h"
#include "variables.h"

MonitoringSystem::MonitoringSystem(QWidget *parent)
	: QMainWindow(parent)
{
    setupMainUi();
    stressChartWidget = main->findChild<QWidget*>("stressChartWidget");
    vonmisesChartWidget = main->findChild<QWidget*>("vonmisesChartWidget");
    tableWidget = main->findChild<QTableWidget*>("tableWidget");
    stressChart = new QChart();
    vonmisesChart = new QChart();
    setupChartUi(stressChartWidget, stressChart, STRESS_DIAGRAM_TITLE);
    setupChartUi(vonmisesChartWidget, vonmisesChart, VONMISES_DIAGRAM_TITLE);
    setWindowTitle(QString(WINDOW_TITLE));
    showMaximized();
}

void MonitoringSystem::setupMainUi() {
    QWidget* centralWidget = new QWidget;
    setCentralWidget(centralWidget);
    QFile file("monitoring_system.ui");
    file.open(QFile::ReadOnly);
    QUiLoader loader;
    main = loader.load(&file, this);
    file.close();
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(main);
    setPalette(PALETTE);
}

void MonitoringSystem::setupChartUi(QWidget* parent, QChart* chart, const char* title) {
    QLineSeries* series = new QLineSeries();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(QString(title));
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QVBoxLayout* stressChartlayout = new QVBoxLayout(parent);
    stressChartlayout->setContentsMargins(0, 0, 0, 0);
    stressChartlayout->addWidget(chartView);
}

MonitoringSystem::~MonitoringSystem()
{
    delete main;
    delete stressChart;
    delete vonmisesChart;
    delete stressChartWidget;
    delete vonmisesChartWidget;
    delete tableWidget;
}
