#include <chart.h>

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
	return series;
}

void Chart::setRangexAxis(const QDateTime& max, int timeInterval) {
	QDateTime min = max.addSecs(-timeInterval * 60);
	xAxis->setRange(min, max);
}
