#pragma once

class Paddle
{
public:		
		
	void setStartingPosition(int xPosition, int yPosition);	

	// Restores the paddle back to its initial position.
	void resetToStartingPosition();
	
	int x() const { return m_x; }
	int y() const { return m_y; }
	int size() const { return m_size; }

	void moveUp() { m_y--; }
	void moveDown() { m_y++; }

private:
	const int m_size = 4;

	int m_x;
	int m_y;
	int m_originalX;
	int m_originalY;
};