#include <chartview.h>
#include <figure.h>

void ChartView::zoomIn() {
    chart()->zoomIn();
}

void ChartView::zoomOut() {
    chart()->zoomOut();
}

void ChartView::zoomReset() {
    chart()->zoomReset();
}

void ChartView::wheelEvent(QWheelEvent* event) {
    QPoint numDegrees = event->angleDelta();
    if (numDegrees.y() > 0) chart()->zoomIn();
    else chart()->zoomOut();
}

void ChartView::mousePressEvent(QMouseEvent* event) {
    if (event->buttons() == Qt::RightButton) {
        QMenu* contextMenu = new QMenu(this);
        QAction* zoomInAction = contextMenu->addAction("Zoom In");
        QAction* zoomOutAction = contextMenu->addAction("Zoom Out");
        QAction* action = contextMenu->exec(this->mapToGlobal(QPoint(event->x(), event->y())));
        if (action == zoomInAction) zoomIn();
        if (action == zoomOutAction) zoomOut();
    }
}

void ChartView::saveImage(const QString& filepath) {
    FigureTools::save(this, filepath);
}

void ChartView::dumpChartData(const QString& filepath) {
    FigureTools::dump(chart(), filepath);
}

void ChartView::pickleChart(const char* filepath) {
    FigureWrap figureWrap;
    FigureTools::pickle(figureWrap, filepath);
}

ChartView::~ChartView() {

}