#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "ListD.h"

using namespace System;
using namespace std;
public enum direction { left, right, up, down };

struct Segment {
	int x;
	int y;
	char form;

	Segment(int x = 0, int y = 0, char form = (char)254) : x(x), y(y), form(form) {}

	int getX() { return x; }
	int getY() { return y; }
	char getForm() { return form; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};

class Snake
{
private:
	vector<Segment> body;
	int dx, dy;
	direction dir;

public:
	Snake();
	~Snake();
	void addSegment();
	void move(int MAXW, int MAXH);
	void changeDirection(direction newDir);
	int getHeadX();
	int getHeadY();
	bool dead();
};
