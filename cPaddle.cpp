#include "cPaddle.h"
#include <iostream>

	cPaddle::cPaddle() {
		x = y = 0;
	}
	cPaddle::cPaddle(int posX, int posY){ 
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	}
	void cPaddle::Reset() {
		x = originalX;
		y = originalY;
	}
	int cPaddle::getX() {
		return x;
	}
	int cPaddle::getY() {
		return y;
	}
	void cPaddle::moveUp() { y--; }
	void cPaddle::moveDown() { y++; }

	std::ostream & operator<<(std::ostream & o, cPaddle c) {
		o << "Paddle [" << c.getX() << "," << c.getY() << "]";
		return o;
	}


cPaddle::~cPaddle()
{
}
