#define NOMINMAX // Windows.h contains a definition for min, but I want to use the min from the standard library.

#include "GameEngine.h"
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <algorithm>

using namespace std;

GameEngine::GameEngine(int width, int height)
	: m_windowWidth(width), m_windowHeight(height), ball(width / 2, height / 2)
{
	// Seed the random number generator.
	srand(time(NULL));						
	paddle1.setStartingPosition(1, height / 2 - 3);
	paddle2.setStartingPosition(width - 2, height / 2 - 3);
	paddle1.resetToStartingPosition();
	paddle2.resetToStartingPosition();
	ball.setCurrentDirection(LEFT);
}

void GameEngine::registerPlayerScoring(const Paddle& winningPaddle)
{
	if (&winningPaddle == &paddle1)
		scorePlayer1++;
	if (&winningPaddle == &paddle2)
		scorePlayer2++;
	ball.reset();
	paddle1.resetToStartingPosition();
	paddle2.resetToStartingPosition();
}

void GameEngine::clearScreen() const
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
void GameEngine::draw() const
{
	clearScreen();
	
	for (int i = 0; i < m_windowWidth + 2; i++)
		cout << m_wallCharacter;	
	cout << "\n";

	for (int i = 0; i < m_windowHeight; i++)
	{
		for (int j = 0; j < m_windowWidth; j++)
		{			
			if (j == 0) // This is the position of the left wall.
				cout << m_wallCharacter;

			if (ball.x() == j && ball.y() == i)
				cout << "O";
			else if (paddle1.x() == j && paddle1.y() == i)
				cout << m_paddleCharacter;
			else if (paddle1.x() == j && paddle1.y() + 1 == i)
				cout << m_paddleCharacter;
			else if (paddle1.x() == j && paddle1.y() + 2 == i)
				cout << m_paddleCharacter;
			else if (paddle1.x() == j && paddle1.y() + 3 == i)
				cout << m_paddleCharacter;

			else if (paddle2.x() == j && paddle2.y() == i)
				cout << m_paddleCharacter;
			else if (paddle2.x() == j && paddle2.y() + 1 == i)
				cout << m_paddleCharacter;
			else if (paddle2.x() == j && paddle2.y() + 2 == i)
				cout << m_paddleCharacter;
			else if (paddle2.x() == j && paddle2.y() + 3 == i)
				cout << m_paddleCharacter;
			else
				cout << " ";
			
			if (j == m_windowWidth - 1) // We're on the right wall.
				cout << m_wallCharacter;
		}
		cout << "\n";
	}

	// Draw the bottom wall. 
	for (int i = 0; i < m_windowWidth + 2; i++)
		cout << m_wallCharacter;

	cout << "\n";

	cout << "Score 1: " << scorePlayer1 << "\n" << "Score 2: " << scorePlayer2 << "\n";
	cout << "Paddle 1: " << paddle1.x() << ", " << paddle1.y() << "\n";
	cout << "Ball:" << ball.x() << ", " << ball.y() << "\n";
}

void GameEngine::handleInput()
{	
	if (_kbhit()) // Is key pressed?
	{
		char current = _getch();
		if (current == upKeyPlayer1)
			if (paddle1.y() > 0)
				paddle1.moveUp();
		if (current == upKeyPlayer2)
			if (paddle2.y() > 0)
				paddle2.moveUp();
		if (current == downKeyPlayer1)
			if (paddle1.y() + paddle1.size() < m_windowHeight)
				paddle1.moveDown();
		if (current == down2)
			if (paddle2.y() + paddle2.size() < m_windowHeight)
				paddle2.moveDown();
		if (ball.currentDirection() == STOP)
			ball.setRandomDirection();
		if (current == q)
			m_isGameQuitting = true;
	}
}

void GameEngine::update()
{
	ball.move();
				
	if (ball.x() == paddle1.x() + 1) // Plus 1 because we don't want the ball to go into the paddle.
	{
		auto positionDifference = ball.y() - paddle1.y();
		if (positionDifference < paddle1.size() && positionDifference >= 0)
			ball.setCurrentDirection((Direction)((rand() % 3) + 4));
	}

	if (ball.x() == paddle2.x() - 1) // Minus 1 because we don't want the ball to go into the paddle.
	{
		auto positionDifference = ball.y() - paddle2.y();
		if (positionDifference < paddle2.size() && positionDifference >= 0)
			ball.setCurrentDirection((Direction)((rand() % 3) + 1));
	}
			
	if (ball.y() == m_windowHeight - 1) // hit bottom wall
		ball.setCurrentDirection(ball.currentDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
	if (ball.y() == 0)
		ball.setCurrentDirection(ball.currentDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

	if (ball.x() == 0)
		registerPlayerScoring(paddle2);
	if (ball.x() == m_windowWidth -1)
		registerPlayerScoring(paddle1);
}

void GameEngine::run()
{
	while (!m_isGameQuitting)
	{
		draw();
		handleInput();
		update();
	}
}
