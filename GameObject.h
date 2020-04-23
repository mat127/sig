#pragma once
class GameObject {
public:
	GameObject();
	~GameObject();
	virtual void draw() = 0;
};

