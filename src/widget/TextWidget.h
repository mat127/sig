#pragma once
#include <string>

#include "game/GameObject.h"
#include "util/Vector.h"

struct TextWidget : public GameObject {
	Vector<int> origin;
	unsigned int charSize;
	float spacingFactor;
	std::string text;

	TextWidget(const std::string & str) : origin(), charSize(16), spacingFactor(1.3f), text(str) {}
	TextWidget() : TextWidget("") {}
	TextWidget(int x, int y, unsigned int charSize) : origin(x,y), charSize(charSize), text() {}

	virtual void draw();

	void draw(const char * text, ...);
	void format(const char * format, ...);
	void format(const char * format, va_list args);

	void setCenter(int x, int y);
	int getWidth() const;
};

