#pragma once
#include <forward_list>

#include "game/GameObject.h"

class WidgetScreen {
private:
	std::forward_list<GameObject*> objects;
public:
	void add(GameObject * object) { objects.push_front(object); }
	bool show(int exitKey);
	void draw();
};

