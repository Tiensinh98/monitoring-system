#pragma once
#include <chart.h>
#include <QtCharts>

class MChartView : public QChartView {

public:

	MChartView(MChart* chart);

	void zoomIn();

	void zoomOut();

	void zoomReset();

	void wheelEvent(QWheelEvent *event) override;

	void mouseMoveEvent(QMouseEvent*event) override;

	void mousePressEvent(QMouseEvent *event) override;

	~MChartView();

};