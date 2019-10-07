#include "Zoom.h"
#include "Application.h"

void Zoom::onScroll(double x, double y) {
	if (y < 0 && app::canvas->getZoom() < 1)
		app::canvas->setZoom(app::canvas->getZoom() * 0.5);
	else
		app::canvas->addZoom(y / 2);
}
