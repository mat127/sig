#pragma once
#include <string>

struct HighScore {
	unsigned int value;

	HighScore();
	bool adjust(unsigned int score);

private:
	static const std::string fileName;

	bool save() const;
	bool load();
};

