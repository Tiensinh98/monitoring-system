#pragma once
#include <QtCharts>
#include <QtWidgets>

class MonitoringSystem  : public QMainWindow
{
	Q_OBJECT

private:
	QWidget* main;
	QChart* stressChart;
	QChart* vonmisesChart;
	QOpenGLWidget* canvas;
	QWidget* stressChartWidget;
	QWidget* vonmisesChartWidget;
	QTableWidget* tableWidget;

public:
	explicit MonitoringSystem(QWidget *parent);

	void setupMainUi();

	void setupChartUi(QWidget* parent, QChart* chart, const char* title);

	~MonitoringSystem();

};