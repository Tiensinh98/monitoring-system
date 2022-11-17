#pragma once
#include <QtModules>

class Canvas : QOpenGLWidget {

public slots:
	void viewFit();

public:
	Canvas();

	void initializeGL() override;

	void resizeGL(int width, int height) override;

	void paintGL() override;

	void deleteBuffers();

	void mouseMoveEvent(QMouseEvent* event) override;

	void mousePressEvent(QMouseEvent* event) override;

	void mouseReleaseEvent(QMouseEvent* event) override;

	void wheelEvent(QWheelEvent* event) override;

	void keyPressEvent(QKeyEvent* event) override;

	void keyReleaseEvent(QKeyEvent* event) override;
};
