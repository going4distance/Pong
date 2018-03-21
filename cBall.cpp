#include <iostream>
#include "cBall.h"



cBall::cBall(int posX, int posY) { //constructor
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
		direction = STOP;
	}

	void cBall::Reset() {
		x = originalX;
		y = originalY;
		direction = STOP;
	}

	void cBall::changeDirection(int d) {
		switch (d) {
		case 0:
			direction = STOP;
			break;
		case 1:
			direction = LEFT;
			break;
		case 2:
			direction = UPLEFT;
			break;
		case 3:
			direction = DOWNLEFT;
			break;
		case 4:
			direction = RIGHT;
			break;
		case 5:
			direction = UPRIGHT;
			break;
		case 6:
			direction = DOWNRIGHT;
			break;
		default:
			break;
		}
	}

	void cBall::randomDirection() {
		direction = (eDir)((rand() % 6) + 1);
	}

	int cBall::getX() { return x; }

	int cBall::getY() { return y; }

	void cBall::Move() {
		switch (direction) {
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case RIGHT:
			x++;
			break;
		case UPRIGHT:
			x++; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case DOWNRIGHT:
			x++; y++;
			break;
		default:
			break;
		}
	}
	
	std::ostream & operator<<(std::ostream & o, cBall c) {
		o << "Ball [" << c.getX() << "," << c.getY() << "][" << c.direction << "]";
		return o;
	}	 

	cBall::eDir cBall::getDirection() { return direction; }
