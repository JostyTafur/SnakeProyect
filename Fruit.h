#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace System;

class Fruit
{
private:
	int x;
	int y;
	char form;
public:
	Fruit(){}
	Fruit(int MAXW, int MAXH);
	void change_position(int MAXW, int MAXH);
	void Draw();
	int getX();
	int getY();
};

