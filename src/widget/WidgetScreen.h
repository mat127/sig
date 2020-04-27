#pragma once
#include <forward_list>
#include <windows.h>

#include "game/Drawable.h"

class WidgetScreen {
private:
	std::forward_list<Drawable*> objects;
public:
	void add(Drawable * object) { objects.push_front(object); }
	bool show(int exitKey = VK_SPACE);
	void draw();
};

