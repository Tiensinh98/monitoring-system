#include <figure.h>

void FigureTools::save(ChartView* chartView, const QString& filepath) {
	QChart* chart = chartView->chart();
	QSize size = chart->size().toSize();
	QPixmap pic(size);
	chartView->render(new QPainter(&pic));
	pic.save(filepath + "/" + chart->title() + ".png");
}

void FigureTools::dump(QChart* chart, const QString& filepath) {

};

void FigureTools::pickle(FigureWrap& figureWrap, const char* filepath) {

}
