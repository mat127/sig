#include <ctype.h>
#include <stdexcept>

#include "Font.h"
#include "SkinLoader.h"

void * Font::get(char ch) {
	if (isdigit(ch))
		return getDigit(ch);
	else if (islower(ch))
		return getLetter(ch);
	else
		throw std::runtime_error("invalid character glyph requested");
}

void * Font::getDigit(char ch) {
	char buffer[256];
	snprintf(buffer, sizeof(buffer), "gfx/num%c.png", ch);
	return SkinLoader::getSkin(buffer);
}

void * Font::getLetter(char ch) {
	char buffer[256];
	snprintf(buffer, sizeof(buffer), "gfx/%clet.png", ch);
	return SkinLoader::getSkin(buffer);
}
