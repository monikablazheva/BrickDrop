#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Timing.h"
#include "UserLogic.h"

using namespace std;

const int FIELD_ROWS = 10;
const int FIELD_COLS = 8;
const int MAX_BRICK_SIZE = 4;
const int ALPHABET_SIZE = 25;

int randomNumber(int start, int end) {

	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(start, end);
	int randomNumber = dis(gen);

	return randomNumber;
}

bool isBrickEmpty() {
	int chance = randomNumber(0,1);
	if (chance == 0) {
		return true;
	}
	return false;
}

char randomLetter() {
	char randomLetter = 'a' + randomNumber(0,ALPHABET_SIZE);
	return randomLetter;
}

int randomBrickSize(int maxSize) {

	if (maxSize < 1) {
		cout << "Exception: INVALID random number range";
		return -1;
	}
	if (maxSize > MAX_BRICK_SIZE) maxSize = MAX_BRICK_SIZE;

	int randomNum = randomNumber(1, maxSize);
	return randomNum;
}

bool isEmpty(string line) { //if each charcter of the line is " "(empty) return true

	for (size_t i = 0; i < FIELD_COLS; i++)
	{
		if (line[i] != ' ') {
			return false;
		}
	}
	return true;
}

string newBrick(int maxSize) {

	//a brick is either " "(empty) or a string.
	//If it's a string it has one beginning upper letter, the rest are lower, max size = 4
	
	string newBrick = "";
	char randLetterLower = randomLetter();
	char randLetterUpper = toupper(randLetterLower);

	if (maxSize == 1) {
		return newBrick + randLetterUpper;
	}

	int size = randomBrickSize(maxSize);
	newBrick += randLetterUpper;

	int lowerStringCount = size - 1;
	for (size_t i = 0; i < lowerStringCount; i++)
	{
		newBrick += randLetterLower;
	}

	return newBrick;
}

string newLine() {

	string newLine;

	while (newLine.size() < FIELD_COLS) {

		if (isBrickEmpty()) {
			newLine += "_";
		}
		else newLine += newBrick(FIELD_COLS - newLine.size());
		
	}

	return newLine;
}

int main() {

	while (true) {

		string username, password;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;


		if (!userChoice(username, password)) {
			continue;
		}

		timing();

		//startGame() ToDo

		cout << "startGame" << endl;;
		break;

	}

	//vector<string> field;

	string line = newLine(); //test
	cout << line;

	return 0;
}