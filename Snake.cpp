#include "Snake.h"

Snake::Snake() {
	Segment head;
	body.push_back(head);
	dx = 0;
	dy = 1;
}

Snake::~Snake() {
	
}

void Snake::addSegment() {
	Segment newSeg;

	if (dx == -2) { newSeg.setX(body[body.size() - 1].getX() + 1); newSeg.setY(body[body.size()-1].getY()); }
	if (dx == 2) { newSeg.setX(body[body.size() - 1].getX() - 1); newSeg.setY(body[body.size() - 1].getY()); }
	if (dy == -1) { newSeg.setX(body[body.size() - 1].getX()); newSeg.setY(body[body.size() - 1].getY() + 1 ); }
	if (dy == 1) { newSeg.setX(body[body.size() - 1].getX()); newSeg.setY(body[body.size() - 1].getY() - 1); }

	body.push_back(newSeg);
}

void Snake::move(int MAXW, int MAXH) {

	if (body[0].getX() + dx > MAXW || body[0].getX() + dx < 0) dx = 0;
	if (body[0].getY() + dy > MAXH || body[0].getY() + dy < 0) dy = 0;

	int pos_startX, saveX = 0;
	int pos_startY, saveY = 0;
	for (size_t i = 0; i < body.size(); ++i) {
		Console::SetCursorPosition(body[i].getX(), body[i].getY()); cout << (char)255;
		if (i == 0) {
			pos_startX = body[i].getX();
			pos_startY = body[i].getY();
			body[i].setX(body[i].getX() + dx);
			body[i].setY(body[i].getY() + dy);
		}
		else {
			if (dx != 0 || dy != 0) {
				saveX = body[i].getX();
				saveY = body[i].getY();
				body[i].setX(pos_startX);
				body[i].setY(pos_startY);

				pos_startX = saveX;
				pos_startY = saveY;

				if (body[0].getX() == body[i].getX() && body[0].getY() == body[i].getY()) {
					dx = dy = 0;
				}
			}
		}
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(body[i].getX(), body[i].getY()); cout << body[i].getForm();
	}
}

void Snake::changeDirection(direction newDir) {
	dir = newDir;
	dx = dy = 0;

	switch (dir) {
	case direction::left:
		dx = -2; break;
	case direction::right:
		dx = 2; break;
	case direction::up:
		dy = -1; break;
	case direction::down:
		dy = 1;
	}
}

int Snake::getHeadX() { return body[0].getX(); }
int Snake::getHeadY() { return body[0].getY(); }

bool Snake::dead() { return dx == 0 && dy == 0 ? true: false; }