#include <string>
#include <fstream>

#include "HighScore.h"

const std::string HighScore::fileName = "hs.bin";

HighScore::HighScore() {
	if(!this->load())
		this->set(0u);
}

bool HighScore::save() const {
	std::ofstream os(fileName, std::ios::out | std::ios::binary);
	if(!os)
		return false;
	os.write((char*)&value, sizeof(value));
	os.close();
	return os.good();
}

bool HighScore::load() {
	std::ifstream is(fileName, std::ios::in | std::ios::binary);
	if(!is)
		return false;
	is.read((char*)&value, sizeof(value));
	is.close();
	return is.good();
}