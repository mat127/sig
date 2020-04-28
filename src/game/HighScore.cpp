#include <string>
#include <fstream>

#include "SpaceInvadersConfig.h"
#include "HighScore.h"

const std::string HighScore::fileName = SIG_HIGH_SCORE_FILENAME;

HighScore::HighScore() {
	if(!this->load())
		this->value = 0u;
}

bool HighScore::save() const {
	std::ofstream os(fileName, std::ios::out | std::ios::binary);
	if(!os)
		return false;
	// do not care about byte ordering - just win platform
	os.write((char*)&value, sizeof(value));
	os.close();
	return os.good();
}

bool HighScore::load() {
	std::ifstream is(fileName, std::ios::in | std::ios::binary);
	if(!is)
		return false;
	// do not care about byte ordering - just win platform
	is.read((char*)&value, sizeof(value));
	is.close();
	return is.good();
}

bool HighScore::adjust(unsigned int score) {
	if (score <= this->value)
		return false;
	this->value = score;
	this->save();
	return true;
}
