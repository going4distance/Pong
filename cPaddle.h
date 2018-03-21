#ifndef CPADDLE_H
#define CPADDLE_H
#include <iostream>

class cPaddle
{
private:
	int x, y;
	int originalX, originalY;

public:
	cPaddle();
	cPaddle(int posX, int posY);
	void Reset();
	int getX();
	int getY();
	void moveUp();
	void moveDown();
	friend std::ostream & operator<<(std::ostream & o, cPaddle c);
	~cPaddle();
};
#endif

