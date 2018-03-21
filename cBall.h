#ifndef CBALL_H
#define CBALL_H
#include <iostream>


class cBall
{
private:
	int x, y;
	int originalX, originalY;
	enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
	
public:
eDir direction;
cBall(int posX, int posY);
void Reset();
void changeDirection(int d);
void randomDirection();
int getX();
int getY();
void Move();
friend std::ostream & operator<<(std::ostream & o, cBall c);
eDir getDirection();

};



#endif
