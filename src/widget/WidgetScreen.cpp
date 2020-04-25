#include "lib/leetlib.h"

#include "WidgetScreen.h"

bool WidgetScreen::show(int exitKey) {
	while (!IsKeyDown(exitKey)) {
		if (WantQuit() || IsKeyDown(VK_ESCAPE))
			return false;
		this->draw();
		Flip();
	}
	return true;
}

void WidgetScreen::draw() {
	for (auto o : objects) {
		o->draw();
	}
}