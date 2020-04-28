#pragma once
#include <string>

#include "game/Drawable.h"
#include "util/Vector.h"

#define TEXT_WIDGET_DEFAULT_SIZE	16u
#define TEXT_WIDGET_DEFAULT_SPACING	1.3f

struct TextWidget : public Drawable {
	Vector<int> origin;
	unsigned int charSize;
	float spacingFactor;
	std::string text;

	TextWidget(const std::string & str) :
		origin(),
		charSize(TEXT_WIDGET_DEFAULT_SIZE),
		spacingFactor(TEXT_WIDGET_DEFAULT_SPACING),
		text(str) {}
	TextWidget() : TextWidget("") {}
	TextWidget(int x, int y, unsigned int charSize = TEXT_WIDGET_DEFAULT_SIZE) :
		origin(x,y), charSize(charSize), text() {}

	virtual void draw();

	void draw(const char * text, ...);
	void format(const char * format, ...);
	void format(const char * format, va_list args);

	void setCenter(int x, int y);
	int getWidth() const;
};

