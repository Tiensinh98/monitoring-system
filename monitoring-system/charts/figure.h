#pragma once
#include <QtModules>
#ifndef FIGURE_H
#define FIGURE_H
#include <chartview.h>

struct FigureWrap {

};

class FigureTools {
public:

	static void save(ChartView* chartView, const QString& filepath);

	static void dump(QChart* chart, const QString& filepath);

	static void pickle(FigureWrap& figureWrap, const char* filepath);

};


#endif //FIGURE_H