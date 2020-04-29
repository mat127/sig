#include <cstdio>


#include "lib/leetlib.h"

#include "TextWidget.h"
#include "util/Font.h"

void TextWidget::draw() {
	Vector<int> position(this->origin);
	for (const char & c : this->text) {
		if (!isspace(c)) {
			void * glyph = Font::get(c);
			DrawSprite(
				glyph,
				(float)position.x, (float)position.y,
				(float)this->charSize, (float)this->charSize,
				0.f,
				0xffffffff
			);
		}
		position.x += (int)(this->charSize * this->spacingFactor);
	}
}

void TextWidget::draw(const char * format, ...) {
	va_list args;
	va_start(args, format);
	this->format(format, args);
	va_end(args);
	this->draw();
}

void TextWidget::format(const char * format, va_list args) {
	char buffer[256];
	vsnprintf(buffer, sizeof(buffer), format, args);
	this->text = buffer;
}

void TextWidget::format(const char * format, ...) {
	va_list args;
	va_start(args, format);
	this->format(format, args);
	va_end(args);
}

void TextWidget::setCenter(int x, int y) {
	this->origin.set(x, y);
	this->origin.x -= this->getWidth() / 2;
}

int TextWidget::getWidth() const {
	size_t charCount = this->text.length();
	return (int)(this->charSize * this->spacingFactor * charCount);
}
