#include <chart.h>
#include <iostream>

Chart::Chart() : QChart() {
	xAxis = new QDateTimeAxis;
	xAxis->setFormat("h:mm:s");
	xAxis->setTickCount(5);
	yAxis = new QValueAxis;
	setTheme(QChart::ChartThemeQt);
}

QXYSeries* Chart::plot(const std::vector<DataPoint>& data, const CType& type, const std::string& title) {
	QXYSeries* mSeries = createSeries(type, title);
	for (DataPoint point : data) {
		mSeries->append(point.dateTime.toSecsSinceEpoch(), point.value);
	}
	addSeries(mSeries);
	setAxisX(xAxis, mSeries);
	setAxisY(yAxis, mSeries);
	
	return mSeries;
}

void Chart::plotSeries(const std::vector<DataPoint>& data, QXYSeries* series) {
	for (DataPoint point : data) {
		series->append(point.dateTime.toSecsSinceEpoch(), point.value);
	}
}


QXYSeries* Chart::createSeries(const CType& type, const std::string& title) {
	QXYSeries* series;
	if (type == CType::LINE) {
		series = new QLineSeries();
	}
	else {
		series = new QScatterSeries();
	}
	series->setName(QString::fromStdString(title));
	QObject::connect(
		series, &QXYSeries::hovered, this, 
		[=](const QPointF& point, bool state) { 
			this->handleHoveredSeries(point, state, series); 
		});
	return series;
}

void Chart::setRangexAxis(const QDateTime& max, long int timeInterval) {
	QDateTime min = max.addSecs(- timeInterval * 60.);
	xAxis->setRange(min, max);
}

void Chart::handleHoveredSeries(const QPointF& point, bool state, QXYSeries* series) {
	series->selectAllPoints();
	if (state) {
		series->setSelectedColor(QColor(0, 0, 0));
	}
	else {
		series->setSelectedColor(series->color());
	}
}

Chart::~Chart() {
	delete xAxis;
	delete yAxis;
}
