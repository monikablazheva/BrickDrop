#pragma once
#include <iostream>
#include <string>
#include <random>

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
	int chance = randomNumber(0, 1);
	if (chance == 0) {
		return true;
	}
	return false;
}

char randomLetter() {
	char randomLetter = 'a' + randomNumber(0, ALPHABET_SIZE);
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

bool isUpper(const char ch) {
	if (ch >= 'A' && ch <= 'Z') return true;
	return false;
}

int lengthBrick(string line, int index) {
	if (!isUpper(line[index])) {
		cout << "Exception: invalid brick start index";
		return -1;
	}
	
	index++;
	int count = 1;
	for (size_t i = index; !isUpper(line[i]) && line[i]!='_'; i++)
	{
		count++;
	}

	return count;
}