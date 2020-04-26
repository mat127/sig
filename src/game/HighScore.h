#pragma once
#include <string>

class HighScore {
private:

	static const std::string fileName;

	unsigned int value;

	bool save() const;
	bool load();

public:
	HighScore();
	void set(unsigned int value) {
		this->value = value;
	}
	unsigned int get() const {
		return this->value;
	}
	bool adjust(unsigned int score) {
		if (score <= this->value)
			return false;
		this->set(score);
		this->save();
		return true;
	}
};

