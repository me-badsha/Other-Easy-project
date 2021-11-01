// Bismillahir Rahmanir Rahim 
// Author: Badsha Faysal ;
#include<bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

bool gameover;
bool shutDown;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[400], tailY[400], nTail;
enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void StartScreen()
{
	system("cls");
	cout << "\nWELCOME TO SNAKE CONSOLE!"
	     << "\n\nIf you want to Play this Game Press 'S' to Start!"
	     << "\n\nIf you want to Exit!! this game Perss 'E' to Quit"
	     << "\n\nIf you want to Know How to Play in this Game Press 'I' for Instructions."
	     << "\n\nYour Previous Score: " << score << endl;
}
void Instructions()
{
	system("cls");
	cout << "\nUse the 'w' key to go UP."
	     << "\n\nUse the 'a' key to turn LEFT."
	     << "\n\nUse the 's' key to go DOWN."
	     << "\n\nUse the 'd' key to turn RIGHT."
	     << "\n\nPress the 'x' key any time during the game to EXIT."
	     << "\n\nDO NOT touch the borders or you will LOSE."
	     << "\nDO NOT reverse movement or you will LOSE."
	     << "\nDO NOT eat your own tail or you will obviously also LOSE!"
		 << "\n\n\nNow press the 'm' key to go MENU.\n";
	string input;
	cin >> input;
	if(input=="m")
		StartScreen();
}
void FruitSpawn()
{
	fruitX = rand() % width;
	fruitY = rand() % height;
}
void Setup()
{
	gameover = false;
	shutDown = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	FruitSpawn();
	score = 0;
	nTail = 0;
}
void Draw()
{
	system("cls"); //clear screen
	for (int i = 0; i < width + 2; i++) {
		cout << "#";}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";

			if (i == y && j == x)
				cout << "0";

			else if (i == fruitY && j == fruitX)
				cout << "F";

			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "0";
						print = true;
					}
				}
				if(!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
}
void Input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x > width || x < 0 || y > height || y < 0) {
		gameover = true;
		StartScreen();
	}

	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			gameover = true;
	}

	if (x == fruitX && y == fruitY) {
		score++;
		nTail++;
		FruitSpawn();
	}
}
int main()
{
	do {
		StartScreen();
		string input;
		cin >> input;
		if (input == "S")
		{
			Setup();
			while (!gameover)
			{
				Draw();
				Input();
				Logic();
				Sleep(100);
			}
		}
		else if (input == "I")
			Instructions();
		else if (input == "E")
			shutDown = true;
	} while (shutDown == false);

    return 0;
}
