#include <iostream>
#include "cBall.h"
#include "cPaddle.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

class cGameManger {
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall * ball;
	cPaddle *player1;
	cPaddle *player2;
public:
	cGameManger(int w, int h) {
		srand(time(NULL));
		quit = false;
		up1 = 'w'; up2 = 'i';
		down1 = 's'; down2 = 'k';
		score1 = score2 = 0;
		width = w;
		height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w-2, h / 2 - 3);
	}
	~cGameManger() {
		delete ball, player1, player2;
	}
	void ScoreUp(cPaddle * player) {
		if (player == player1)
			score1++;
		else if (player == player2)
			score2++;

		ball->Reset();
		player1->Reset();
		player2->Reset();
	}

	void Draw() {
		system("cls");
		// Run->Charmap.  Advanced View, char set: Dos: Western Europe --> get the hex value.
		cout << "\xC9";  // omit the 0 from charmap.
		for (int i = 1; i < width + 1; i++) {
			cout << "\xCD";		}
		cout << "\xBB" << endl;
		// end of top row draw
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (x == 0) {
					cout << "\xBA";		}
				if (ballx == x && bally == y) {
					cout << "O";		} //ball
				else if (player1x == x && player1y == y) {
					cout << "\xDB";		} //player 1
				else if (player1x == x && player1y +1 == y) {
					cout << "\xDB";		} //player 1
				else if (player1x == x && player1y +2 == y) {
					cout << "\xDB";		} //player 1
				
				else if (player2x == x && player2y == y) {
					cout << "\xDB";		} //player 2
				else if (player2x == x && player2y +1 == y) {
					cout << "\xDB";		} //player 2
				else if (player2x == x && player2y +2 == y) {
					cout << "\xDB";		} //player 2
				else {
					cout << " ";		}
				if (x == width - 1) {
					cout << "\xBA";		}
			}
			cout << endl;
		}
		// begin - draw bottom row
		cout << "\xC8";
		for (int i = 1; i < width + 1; i++) {
			cout << "\xCD";		}
		cout << "\xBC" << endl;

		cout << "Score 1: " << score1 << endl<< "Score 2: " << score2 << endl;
	}

	void Input() {
		ball->Move();
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		if (_kbhit()) {
			char current = _getch();
			if (current == up1) 
				if (player1y > 0) {
					player1->moveUp();	} 
			if (current == up2)
				if (player2y > 0) {
					player2->moveUp();	}
			if (current == down1)
				if (player1y + 3 < height) {
					player1->moveDown();	}
			if (current == down2)
				if (player2y + 3 < height) {
					player2->moveDown();	}
			if (ball->getDirection() == 0) // triggers if ball direction is "STOP".  (see eDir in cBall.h)
				ball->randomDirection();
			if (current == 'q') {
				quit = true;		}
		}
	}//end Input function

	void Logic() {
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		// Left Paddle
		for (int i = 0; i < 3; i++) {
			if (ballx == player1x + 1)
				if (bally == player1y + i)
					ball->changeDirection((rand() % 3) + 4);
		}
		// Right Paddle
		for (int i = 0; i < 3; i++) {
			if (ballx == player2x -1)
				if (bally == player2y + i)
					ball->changeDirection((rand() % 3) + 1);
		}
		//bottom wall
		if (bally == height - 1) {
			if (ball->getDirection() == 6){
				ball->changeDirection(5);				
			}
			else{
				ball->changeDirection(2);
			}
		}
			//ball->changeDirection(ball->getDirection() == 6 ? 5 : 2);
			// syntax means if <before ?> then make <after?> else make it <after :>
		
		//top wall
		if (bally == 0) {
			if (ball->getDirection() == 5)
				ball->changeDirection(6);
			else
				ball->changeDirection(3);
		}
		//ball->changeDirection(ball->getDirection() == 5 ? 6 : 3);

		//right wall
		if (ballx == width - 1)
			ScoreUp(player1);
		//left wall
		if (ballx == 0)
			ScoreUp(player2);
	} //end Logic function

	void Run() {
		while (!quit) {
			Draw();
			Input();
			Logic();
			//Sleep(20);
		}
	}
};



int main() {
	cGameManger game1(40, 20);
	game1.Run();




	return 0;
}


