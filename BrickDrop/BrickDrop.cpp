#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Timing.h"
#include "UserLogic.h"
#include "BricksLogic.h"
#include "FieldLogic.h"

using namespace std;

bool isGameOver(const vector<string> field) {
	if (!isEmptyLine(field.front())) {
		cout << "GAME OVER" << endl;;
		return true;
	}
	return false;
}

void startGame() {
	vector<string> field = generateField();

	int score = 0;
	
	while (!isGameOver(field)) {
		cout << "Score: " << score << endl;
		cout << endl;

		printField(field);
		timing();
		addNewLine(field);
	}

	cout << "Score: " << score << endl;
	cout << endl;
	printField(field);
}

int main() {

	while (true) {

		string username, password;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;


		if (userChoice(username, password)) {
			timing();
			startGame();
			break;
		}
	}

	return 0;
}