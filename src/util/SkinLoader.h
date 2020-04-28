#pragma once
#include <map>

class SkinLoader {
private:
	static std::map<std::string,void *> _loaded;
public:
	static void * getSkin(const std::string & fileName);
	static void * loadSkin(const std::string & fileName);
};

