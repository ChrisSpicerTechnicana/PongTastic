#include "Paddle.h"

void Paddle::setStartingPosition(int xPosition, int yPosition)
{
	m_originalX = xPosition;
	m_originalY = yPosition;
}

void Paddle::resetToStartingPosition()
{
	m_x = m_originalX;
	m_y = m_originalY;
}
