#include <chartview.h>

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

}

void ChartView::mouseMoveEvent(QMouseEvent* event) {

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

ChartView::~ChartView() {

}