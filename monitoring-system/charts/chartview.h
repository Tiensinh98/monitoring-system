#pragma once
#include <chart.h>
#include <QtModules>

class ChartView : public QChartView {
public:

	ChartView(Chart* chart): QChartView(chart) {
		setBackgroundBrush(QBrush(QColor(255, 0, 0, 127)));
	}

	void zoomIn();

	void zoomOut();

	void zoomReset();

	void wheelEvent(QWheelEvent *event) override;

	void mouseMoveEvent(QMouseEvent*event) override;

	void mousePressEvent(QMouseEvent *event) override;

	~ChartView();

};


class MyPushButton : public QPushButton {
public:
	MyPushButton(const QString& text, QWidget* parent = 0) : QPushButton(text, parent) {}
};