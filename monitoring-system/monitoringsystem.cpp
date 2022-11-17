#include <QString>
#include <QtModules>

#define MONIORINGSYSTEM

#include "variables.h"
#include "monitoringsystem.h"

MonitoringSystem::MonitoringSystem(QWidget *parent)
	: QMainWindow(parent)
{
    setupMainUi();
    setupWidgets();
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

void MonitoringSystem::setupWidgets() {
    stressChartWidget = main->findChild<QWidget*>("stressChartWidget");
    vonmisesChartWidget = main->findChild<QWidget*>("vonmisesChartWidget");
    tableWidget = main->findChild<QTableWidget*>("tableWidget");
    saveFiguresBtn = main->findChild<QPushButton*>("saveFiguresBtn");
    saveDataBtn = main->findChild<QPushButton*>("saveDataBtn");
    applyBtn = main->findChild<QPushButton*>("applyBtn");
    startBtn = main->findChild<QPushButton*>("startBtn");
    pauseBtn = main->findChild<QPushButton*>("pauseBtn");
    viewFitBtn = main->findChild<QPushButton*>("viewFitBtn");
    openDataDirBtn = main->findChild<QPushButton*>("openDataDirBtn");
    openStressDirBtn = main->findChild<QPushButton*>("openStressDirBtn");
    openVonmisesDirBtn = main->findChild<QPushButton*>("openVonmisesDirBtn");
    dataDirLineEdit = main->findChild<QLineEdit*>("dataDirLineEdit");
    stressDirLineEdit = main->findChild<QLineEdit*>("stressDirLineEdit");
    vonmisesDirLineEdit = main->findChild<QLineEdit*>("vonmisesDirLineEdit");
    QObject::connect(saveFiguresBtn, &QPushButton::clicked, this, &MonitoringSystem::saveFigures);
    QObject::connect(saveDataBtn, &QPushButton::clicked, this, &MonitoringSystem::saveDatas);
    QObject::connect(openDataDirBtn, &QPushButton::clicked, this, &MonitoringSystem::openDataDirDialog);
    QObject::connect(openStressDirBtn, &QPushButton::clicked, this, &MonitoringSystem::openStressDirDialog);
    QObject::connect(openVonmisesDirBtn, &QPushButton::clicked, this, &MonitoringSystem::openVonmisesDirDialog);
    QObject::connect(startBtn, &QPushButton::clicked, this, &MonitoringSystem::saveFigures);
    QObject::connect(pauseBtn, &QPushButton::clicked, this, &MonitoringSystem::saveFigures);
    QObject::connect(viewFitBtn, &QPushButton::clicked, this, &MonitoringSystem::saveFigures);
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
    chartViews.push_back(chartView);
}

void MonitoringSystem::saveFigures() {
    QString dir = QFileDialog::getExistingDirectory(
        this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    for (ChartView *cv : chartViews) {
        cv->saveImage(dir);
    }
    qDebug() << "Saved Images\n";
}

void MonitoringSystem::saveDatas() {
    QString dir = QFileDialog::getExistingDirectory(
        this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    for (ChartView* cv : chartViews) {
        cv->dumpChartData(dir);
    }
    qDebug() << "Saved figure datas\n";
}

void MonitoringSystem::openDataDirDialog() {
    QString dir = QFileDialog::getExistingDirectory(
        this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    dataDirLineEdit->setText(dir);
}

void MonitoringSystem::openStressDirDialog() {
    QString dir = QFileDialog::getExistingDirectory(
        this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    stressDirLineEdit->setText(dir);
}

void MonitoringSystem::openVonmisesDirDialog() {
    QString dir = QFileDialog::getExistingDirectory(
        this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    vonmisesDirLineEdit->setText(dir);
}

MonitoringSystem::~MonitoringSystem()
{
    delete main;
    delete stressChart;
    delete vonmisesChart;
    delete stressChartWidget;
    delete vonmisesChartWidget;
    delete tableWidget;
    delete saveFiguresBtn;
    delete saveDataBtn;
    delete applyBtn;
    delete startBtn;
    delete pauseBtn;
    delete viewFitBtn;
    delete changeColorBarBtn;
    delete dataDirLineEdit;
    delete stressDirLineEdit;
    delete vonmisesDirLineEdit;
}
