#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Timing.h"
#include "UserLogic.h"
#include "BricksLogic.h"
#include "FieldLogic.h"
#include "GameLoop.h"

using namespace std;

int main() {

	while (true) {

		string username, password;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;


		if (userChoice(username, password)) {
			startGame();
			break;
		}
	}

	return 0;
}