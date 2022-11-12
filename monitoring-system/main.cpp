#include <QtWidgets/QApplication>
#include <monitoring_system.h>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MonitoringSystem w(nullptr);
	w.show();
	app.exec();
}