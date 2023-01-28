#include "Game.h"
Game::Game(int MAXW, int MAXH) {
	fruit = Fruit(MAXW, MAXH);
	snake = Snake();
	this->intervale = 250;
	this->MAXW = MAXW;
	this->MAXH = MAXH;
	this->points = 0;
}

Game::~Game() {

}

void Game::IntroGame() {

	system("cls");
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(MAXW / 2 - 17, MAXH / 2 - 7);
	cout << "  _____ ____    ____  __  _    ___ "<<endl;
	Console::SetCursorPosition(MAXW / 2 - 17, MAXH / 2 - 6);
	cout << " / ___/|    \\  /    ||  |/ ] /   _]"<<endl;
	Console::SetCursorPosition(MAXW / 2 - 17, MAXH / 2 - 5);
	cout << "(   \\_ |  _  ||  o  ||  ' / /   [_ "<<endl;
	Console::SetCursorPosition(MAXW / 2 - 17, MAXH / 2 - 4);
	cout << " \\__  ||  |  ||     ||    \\ |    _]"<<endl;
	Console::SetCursorPosition(MAXW / 2 - 17, MAXH / 2 - 3);
	cout << " /  \\ ||  |  ||  _  ||     ||   [_ " << endl;
	Console::SetCursorPosition(MAXW / 2 - 17, MAXH / 2 - 2);
	cout << " \\    ||  |  ||  |  ||  .  ||     |"<<endl;
	Console::SetCursorPosition(MAXW / 2 - 17, MAXH / 2 - 1);
	cout << "  \\___||__|__||__|__||__|\\_||_____|"<<endl;
	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::SetCursorPosition(MAXW / 2 - 20, MAXH / 2 + 1 );
	cout << "          Press SPACE to start game"<< endl;
	Console::SetCursorPosition(MAXW / 2 - 20, MAXH / 2 + 3);
	cout << "          Press ESC to close game" << endl;
}

void Game::PlayGame() {
	bool life = true;
	while (life) {
		snake.move(MAXW, MAXH);
		if (_kbhit()) {
			char key = _getch();
			switch (toupper(key)) {
			case 'W': snake.changeDirection(direction::up); break;
			case 'A': snake.changeDirection(direction::left); break;
			case 'S': snake.changeDirection(direction::down); break;
			case 'D': snake.changeDirection(direction::right);
			}
		}
		System::Threading::Thread::Sleep(intervale);
		if (fruit.getX() == snake.getHeadX() && fruit.getY() == snake.getHeadY()) {
			snake.addSegment();
			fruit.change_position(MAXW, MAXH);
			if (intervale != 30) {
				intervale -= 10;
			}
			++points;
		}
		fruit.Draw();
		if (snake.dead()) { life = false; }
		
	}

	Loose(points);
	
	_getch();
	snake = Snake();
}

void Game::Loose(int points) {
	system("cls");
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(MAXW / 2 - 31, MAXH / 2 - 6);
	cout << "  ____   ____  ___ ___    ___       ___   __ __    ___  ____  ";
	Console::SetCursorPosition(MAXW / 2 - 31, MAXH / 2 - 5);
	cout << " /    | /    ||   |   |  /  _]     /   \\ |  |  |  /  _]|    \\ ";
	Console::SetCursorPosition(MAXW / 2 - 31, MAXH / 2 - 4);
	cout << "|   __||  o  || _   _ | /  [_     |     ||  |  | /  [_ |  D  )";
	Console::SetCursorPosition(MAXW / 2 - 31, MAXH / 2 - 3);
	cout << "|  |  ||     ||  \\_/  ||    _]    |  O  ||  |  ||    _]|    / ";
	Console::SetCursorPosition(MAXW / 2 - 31, MAXH / 2 - 2);
	cout << "|  |_ ||  _  ||   |   ||   [_     |     ||  :  ||   [_ |    \\ ";
	Console::SetCursorPosition(MAXW / 2 - 31, MAXH / 2 - 1);
	cout << "|     ||  |  ||   |   ||     |    |     | \\   / |     ||  .  \\";
	Console::SetCursorPosition(MAXW / 2 - 31, MAXH / 2);
	cout << "|___,_||__|__||___|___||_____|     \\___/   \\_/  |_____||__|\\_|";
	Console::SetCursorPosition(MAXW / 2 - 10, MAXH / 2 + 2);
	cout << "PUNTOS : " << points << endl;
}