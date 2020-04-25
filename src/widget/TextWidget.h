#pragma once
#include <string>

#include "game/GameObject.h"
#include "util/Vector.h"

struct TextWidget : public GameObject {
	Vector<int> origin;
	unsigned int charSize;
	std::string text;

	TextWidget(const std::string & str) : origin(), charSize(16), text(str) {}
	TextWidget() : TextWidget("") {}

	virtual void draw();

	void draw(const char * text);
};

