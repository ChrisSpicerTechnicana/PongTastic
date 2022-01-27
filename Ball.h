#pragma once

#include "Direction.h"
#include <stdlib.h>

class Ball
{

public:
	Ball(int x_position, int y_position);

	// Restores the ball back to its initial position and STOP state.
	void reset();

	void move();
	void setRandomDirection();

	int x() const { return m_x; }
	int y() const { return m_y; }
	Direction currentDirection() const { return m_currentDirection; }
	void setCurrentDirection(Direction newDirection) { m_currentDirection = newDirection; }

private:
	int m_x;
	int m_y;
	int m_originalX;
	int m_originalY;
	Direction m_currentDirection;
};