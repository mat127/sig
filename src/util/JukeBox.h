#pragma once
class JukeBox {
private:
	JukeBox() {}

	static void * _shoot;
	static void * _alienExplosion;
	static void * _playerExplosion;

public:
	static void initialize();

	static int shoot();
	static int alienExplosion();
	static int playerExplosion();
};

