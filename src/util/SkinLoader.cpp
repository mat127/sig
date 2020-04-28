#include "lib/leetlib.h"

#include "SkinLoader.h"

std::map<std::string,void *> SkinLoader::_loaded;

void * SkinLoader::getSkin(const std::string & fileName) {
	auto it = _loaded.find(fileName);
	if (it != _loaded.end())
		return it->second;
	return loadSkin(fileName);
}

void * SkinLoader::loadSkin(const std::string & fileName) {
	auto skin = LoadSprite(fileName.c_str());
	SkinLoader::_loaded[fileName] = skin;
	return skin;
}