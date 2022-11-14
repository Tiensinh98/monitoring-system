#include <QString>
#include <QtModules>

#include "variables.h"
#include "monitoringsystem.h"

MonitoringSystem::MonitoringSystem(QWidget *parent)
	: QMainWindow(parent)
{
    setupMainUi();
    stressChartWidget = main->findChild<QWidget*>("stressChartWidget");
    vonmisesChartWidget = main->findChild<QWidget*>("vonmisesChartWidget");
    tableWidget = main->findChild<QTableWidget*>("tableWidget");
    stressChart = new Chart;
    vonmisesChart = new Chart;
    setupChartUi(stressChartWidget, stressChart, STRESS_DIAGRAM_TITLE);
    setupChartUi(vonmisesChartWidget, vonmisesChart, VONMISES_DIAGRAM_TITLE);
    setWindowTitle(QString(WINDOW_TITLE));
    showMaximized();
}

void MonitoringSystem::setupMainUi() {
    QWidget* centralWidget = new QWidget;
    setCentralWidget(centralWidget);
    QFile file("monitoringsystem.ui");
    file.open(QFile::ReadOnly);
    QUiLoader loader;
    main = loader.load(&file, this);
    file.close();
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(main);
    setPalette(PALETTE);
}

void MonitoringSystem::setupChartUi(QWidget* parent, Chart* chart, const char* title) {
    std::vector<DataPoint> data;
    data.push_back(DataPoint(QDateTime(QDate(2022, 11, 14), QTime(7, 7)), 3));
    data.push_back(DataPoint(QDateTime(QDate(2022, 11, 14), QTime(8, 7)), 6));
    data.push_back(DataPoint(QDateTime(QDate(2022, 11, 14), QTime(9, 7)), 1));
    chart->plot(data, CType::LINE, "Series 1");
    chart->setTitle(QString(title));
    ChartView* chartView = new ChartView(chart);
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
