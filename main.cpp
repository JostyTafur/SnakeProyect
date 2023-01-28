#include <iostream>
#include "Game.h"
#include<time.h>

using namespace std;

int main() {
	srand(time(NULL));
	const int MAXW = 80;
	const int MAXH = 30;

	Console::CursorVisible = false;
	Console::SetWindowSize(MAXW, MAXH);
	Game game = Game(MAXW, MAXH);

	char key = ' ';
	do {
		game.IntroGame();
		
		key = ' ';
		key = _getch();
		if (toupper(key) == (char)32) { 
			system("cls");
			game.PlayGame();
		}
	} while (key != (char)27);
	
	Console::SetCursorPosition(MAXW / 2 - 20, MAXH / 2 + 5);
	system("pause");
	return 0;
}