#pragma once
#include <chart.h>
#include <QtModules>
#ifndef CHARTVIEW_H
#define CHARTVIEW_H

class ChartView : public QChartView {
public:
	ChartView(Chart* chart): QChartView(chart) {
		setBackgroundBrush(QBrush(QColor(255, 0, 0, 127)));
	}

	void zoomIn();

	void zoomOut();

	void zoomReset();

	void wheelEvent(QWheelEvent *event) override;

	void mousePressEvent(QMouseEvent *event) override;

	void saveImage(const QString& filepath);

	void dumpChartData(const QString& filepath);

	void pickleChart(const char* filepath);

	~ChartView();

};
#endif // CHARTVIEW_H