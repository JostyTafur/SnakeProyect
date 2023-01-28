#pragma once
#include <conio.h>
#include "Snake.h"
#include "Fruit.h"

using namespace std;
using namespace System;

class Game
{
private:
	Snake snake;
	Fruit fruit;
	int intervale;
	int MAXW, MAXH;
	int points;
public: 
	Game(int MAXW, int MAXH);
	~Game();
	void IntroGame();
	void PlayGame();
	void Loose(int points);
};

