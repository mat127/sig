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
				position.x, position.y,
				this->charSize, this->charSize,
				0.f,
				0xffffffff
			);
		}
		position.x += this->charSize;
	}
}

void TextWidget::draw(const char * text) {
	this->text = text;
	this->draw();
}
