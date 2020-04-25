#pragma once

struct Font {
	static void * get(char ch);
private:
	static void * getLetter(char ch);
	static void * getDigit(char ch);
};

