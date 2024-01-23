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
User login and registration helper file
*
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Timing.h"

using namespace std;

fstream db;
ofstream dbInput;
bool userExists = false;

bool loginUser(string username, string password) {

	db.open("Database.txt");
	dbInput.open("Database.txt", ios::app);

	if (db.is_open()) {
		string line;
		while (getline(db, line)) {	//check if there is an existing user with entered name and password
			if (line == (username + ";" + password)) {
				userExists = true;
				break;
			}
		}
		if (userExists) { //if there is an existing user break the loop and output success
			cout << "Login successful" << endl;
			return true;
		}

		cout << "Incorrect username or password" << endl;
		timing();
	}

	dbInput.close();
	db.close(); //close connections
	return false;
}

bool registerNewUser(const string username, const string password) {

	db.open("Database.txt"); //opening a read-only connection to file
	dbInput.open("Database.txt", ios::app);	//opening a write connection to file
	if (db.is_open()) {
		string line;
		while (getline(db, line)) {	//check every line for the registered user
			string usernameInFile;
			for (int i = 0; i < line.length(); i++)	//get the username
			{
				if (line[i] == ' ') break;
				usernameInFile += line[i];
			}
			if (username == usernameInFile) { //check if a username in in the file is equal to entered username. This way a username cannot be used more than once					userExists = true;
				userExists = true;
				cout << "User with that name already exists! Try to log in!" << endl;
				return false;
			}
		}
	
		if (!userExists) {	// if the user doesn't exist create new one
			string newUser = username + ";" + password;
			dbInput << newUser << endl;
			cout << "Register successful!" << endl;
			dbInput.close();
			db.close(); //close connections

			cout << "You will be loged int automatically" << endl;
			loginUser(username, password);
			return true;
		}
	}
	return false;
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