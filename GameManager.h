#pragma once

#include "Ball.h"
#include "Paddle.h"

class GameEngine
{
private:
	int m_windowWidth;
	int m_windowHeight;
	int scorePlayer1 = 0;
	int scorePlayer2 = 0;
	bool m_isGameQuitting = false;
	const char up1 ='w';
	const char up2 = 'i';
	const char down1 = 's';
	const char down2 = 'k';
	const char q = 'q';
	Ball* ball;
	Paddle* p1;
	Paddle* p2;
	Paddle p3;

public:
	GameEngine(int width, int height);
	
	~GameEngine()
	{
		delete ball;
		delete p1, p2;
	}

	void registerPlayerScoring(Paddle* player);

	void clearScreen() const;

	void draw()	const;

	void handleInput();

	void update();

	void run()
	{
		while (!m_isGameQuitting)
		{
			draw();
			handleInput();
			update();
		}
	}
};