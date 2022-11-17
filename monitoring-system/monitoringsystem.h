#pragma once
#include <QtModules>
#include <Charts>
#include <vector>

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
	QPushButton* saveFiguresBtn;
	QPushButton* saveDataBtn;
	QPushButton* applyBtn;
	QPushButton* startBtn;
	QPushButton* pauseBtn;
	QPushButton* viewFitBtn;
	QPushButton* openDataDirBtn;
	QPushButton* openStressDirBtn;
	QPushButton* openVonmisesDirBtn;
	QPushButton* changeColorBarBtn;
	QLineEdit* dataDirLineEdit;
	QLineEdit* stressDirLineEdit;
	QLineEdit* vonmisesDirLineEdit;
	std::vector<ChartView*> chartViews;

public slots:
	void saveFigures();

	void saveDatas();

	void openDataDirDialog();

	void openStressDirDialog();

	void openVonmisesDirDialog();

public:
	explicit MonitoringSystem(QWidget *parent);

	void setupMainUi();

	void setupWidgets();

	void setupChartUi(QWidget* parent, Chart* chart, const char* title);

	~MonitoringSystem();

};