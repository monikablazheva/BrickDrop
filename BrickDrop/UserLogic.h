#pragma once
#include <iostream>
#include <string>
#include "Timing.h"

using namespace std;

bool loginUser(const string username, const string password) {

	string usernameStream = "monika"; //ToDo ---> stream.get
	string passwordStream = "test123!";

	if (username == usernameStream && password == passwordStream) {

		cout << "Login successful" << endl;

		return true;
	}

	cout << "Incorrect username or password" << endl;
	timing();

	return false;
}

bool registerNewUser(const string username, const string password) {
	//ToDo ---> stream.add

	cout << "Register successful!" << endl;
	cout << "You will be loged int automatically" << endl;
	loginUser(username, password);

	return true;
}

bool userChoice(string& username, string& password) {

	cout << "1) login" << endl;
	cout << "2) register" << endl;

	int userChoice = 0;
	cin >> userChoice;

	if (userChoice < 1 || userChoice > 2) {

		cout << "Invalid input! Enter your choice again: " << endl;
		timing();

		return false;
	}

	if (userChoice == 1) {

		if (!loginUser(username, password)) {
			return false;
		}
	}
	else if (userChoice == 2) {

		if (!registerNewUser(username, password)) {
			return false;
		}
	}

	cout << "Enjoy the game!" << endl;
	return true;
}

