#pragma once
class JukeBox {
private:
	JukeBox() {}

	static void * _shoot;
	static void * _alienExplosion;
	static void * _playerExplosion;

	static void * _intro;

public:
	static void initialize();

	static int intro();

	static int shoot();
	static int alienExplosion();
	static int playerExplosion();

	static void stop(int handle);
};

