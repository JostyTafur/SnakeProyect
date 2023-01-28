#include "Fruit.h"
Fruit::Fruit(int MAXW, int MAXH) {
	x = 2 * (1 + (rand() % MAXW/2));
	y = 1 + (rand() % MAXH - 2);
	form = (char)64;
	Console::SetCursorPosition(x, y); cout << form;
}

void Fruit::change_position(int MAXW, int MAXH) {
	x = 2 * (1 + (rand() % MAXW / 2));
	y = 10 + (rand() % MAXH - 10);
}

void Fruit::Draw() {
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(x, y); cout << form;
}

int Fruit::getX() {
	return x;
}

int Fruit::getY() {
	return y;
}