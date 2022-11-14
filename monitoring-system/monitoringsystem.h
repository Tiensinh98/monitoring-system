#pragma once
#include <QtModules>
#include <Charts>


class MonitoringSystem  : public QMainWindow
{
	Q_OBJECT

private:
	QWidget* main;
	Chart* stressChart;
	Chart* vonmisesChart;
	QOpenGLWidget* canvas;
	QWidget* stressChartWidget;
	QWidget* vonmisesChartWidget;
	QTableWidget* tableWidget;

public:
	explicit MonitoringSystem(QWidget *parent);

	void setupMainUi();

	void setupChartUi(QWidget* parent, Chart* chart, const char* title);

	~MonitoringSystem();

};