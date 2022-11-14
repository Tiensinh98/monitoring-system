#include <QtModules>
#include <monitoringsystem.h>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MonitoringSystem w(nullptr);
	w.show();
	app.exec();
}