#pragma once

#include "Ball.h"
#include "Paddle.h"

class GameEngine
{
public:
	GameEngine(int width, int height);

	void registerPlayerScoring(const Paddle& winningPaddle);

	void clearScreen() const;

	void draw()	const;

	void handleInput();

	void update();

	void run();

private:
	int m_windowWidth;
	int m_windowHeight;
	int scorePlayer1 = 0;
	int scorePlayer2 = 0;
	bool m_isGameQuitting = false;
	const char upKeyPlayer1 = 'w';
	const char upKeyPlayer2 = 'i';
	const char downKeyPlayer1 = 's';
	const char down2 = 'k';
	const char q = 'q';

	const char m_wallCharacter = '\xB2';
	const char m_paddleCharacter = '\xDB';

	Ball ball;
	Paddle paddle1;
	Paddle paddle2;
};