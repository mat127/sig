#pragma once
class JukeBox {
private:
	JukeBox() {}

	static void * _highlyLoaded;
	static void * _shoot;
	static void * _alienExplosion;
	static void * _playerExplosion;

	static void * _intro;
	static void * _gameOver;
	static void * _newHighScore;

public:
	static void initialize();

	static int intro();
	static int gameOver();
	static int newHighScore();

	static int highlyLoaded();
	static int shoot();
	static int alienExplosion();
	static int playerExplosion();

	static void stop(int handle);
};

