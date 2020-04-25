#include "lib/leetlib.h"

#include "SkinLoader.h"

std::map<std::string,void *> SkinLoader::loaded;

void * SkinLoader::getSkin(const std::string & fileName) {
	auto it = loaded.find(fileName);
	if (it != loaded.end())
		return it->second;
	return loadSkin(fileName);
}

void * SkinLoader::loadSkin(const std::string & fileName) {
	auto skin = LoadSprite(fileName.c_str());
	SkinLoader::loaded[fileName] = skin;
	return skin;
}