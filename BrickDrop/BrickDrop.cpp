/**
*
Solution to course project # 3
Introduction to programming course
Faculty of Mathematics and Informatics of Sofia University
Winter semester 2023/2024
*
@author Monika Blazheva
@idnumber 7MI0600350
@compiler VC
*
Main file
*
*/

#include <iostream>
#include <string>
#include "UserLogic.h"
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