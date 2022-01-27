#include "Ball.h"
#include <exception>

using namespace std;

Ball::Ball(int x_position, int y_position) : 
	m_originalX(x_position),
	m_originalY(y_position),
	m_x(x_position),
	m_y(y_position),
	m_currentDirection(STOP)
{}

void Ball::reset()
{
	m_x = m_originalX;
	m_y = m_originalY;
	m_currentDirection = STOP;
}

void Ball::setRandomDirection()
{
	m_currentDirection = (Direction)((rand() % 6) + 1);
}

void Ball::move()
{
	switch (m_currentDirection)
	{
	case STOP:
		break;
	case LEFT:
		m_x--;
		break;
	case RIGHT:
		m_x++;
		break;
	case UPLEFT:
		m_x--;
		m_y--;
		break;
	case DOWNLEFT:
		m_x--;
		m_y++;
		break;
	case UPRIGHT:
		m_x++;
		m_y--;
		break;
	case DOWNRIGHT:
		m_x++; m_y++;
		break;
	default:
		throw exception("Unexpected direction");
	}
}