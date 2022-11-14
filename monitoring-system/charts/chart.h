#pragma once
#include <string>
#include <vector>
#include <QtModules>

struct DataPoint {
public:
	QDateTime dateTime;
	float value;

	DataPoint(const QDateTime& d, float v) {
		dateTime = d;
		value = v;
	}
};

enum class CType {LINE, SCATTER};


class Chart : public QChart {
private:
	QDateTimeAxis* xAxis;
	QValueAxis* yAxis;

public:

	Chart();

	QXYSeries* plot(const std::vector<DataPoint>& data, const CType& type, const std::string& title);

	void plotSeries(const std::vector<DataPoint>& data, QXYSeries* series);

	QXYSeries* createSeries(const CType& type, const std::string& title);

	void setRangexAxis(const QDateTime& max, int timeInterval);


};

