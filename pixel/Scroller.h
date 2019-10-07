#include "Tool.h"

#pragma once
class Scroller : public Tool {
private:
	bool scrolling;
	int lastX;
	int lastY;

public:
	Scroller();

	virtual void onMouseButton(int button, int action, int x, int y);
	virtual void onMouseMove(int x, int y);

};

