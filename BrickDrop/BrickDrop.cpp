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

void input(int& line, int& index, char& direction, int& length) {
	
	cout << "Enter line (starting from the bottom): ";
	cin >> line;

	cout << "Beginning index of the brick you want to move: ";
	cin >> index;

	cout << "Direction (l for left or r for rigth): ";
	cin >> direction;

	cout << "Length of the move: ";
	cin >> length;

	cout << line << index << direction << length;

	//INPUT VALIDATION TO DO
}

void checkForFullLines(vector<string> field, int& score) {
	if (isFieldEmptyValidation(field)) {
		return;
	}

	for (size_t i = 0; i < FIELD_ROWS; i++)
	{
		if (isFullLine(field[i])) {
			removeAtLine(field, i);
			score += 10;
		}
	}
}

void swap(char& a, char& b) {
	int temp = a;
	a = b;
	b = temp;
}

void moveBrick(string &line, int startIndex, int destination, int brickLen){
	int endOfBrick = startIndex + brickLen - 1;

	if (startIndex < destination)
	{
		int destinationOfEndBrick = destination + brickLen - 1;

		for (int i = endOfBrick; i >= startIndex; i--)
		{
			for (int j = i; j < destinationOfEndBrick; j++)
			{
				swap(line[j], line[j + 1]);
			}
			destinationOfEndBrick--;
		}
	}

	else if (startIndex > destination)
	{
		int destinationOfStartBrick = destination;

		for (int i = startIndex; i <= endOfBrick; i++)
		{
			for (int j = i; j > destinationOfStartBrick; j--)
			{
				swap(line[j], line[j - 1]);
			}
			destinationOfStartBrick++;
		}
	}
}

void update(vector<string> &field, int score) {
	int lineIndex, startIndex, length;
	char direction;
	input(lineIndex, startIndex, direction, length);

	string line = field[FIELD_ROWS-lineIndex];
	int destinationIndex=0;

	if (direction == 'r') {
		destinationIndex = startIndex + length;
	}
	else if (direction == 'l') {
		destinationIndex = startIndex - length;
	}
	int brickLen = lengthBrick(line, startIndex);
	moveBrick(line, startIndex, destinationIndex, brickLen);
	field[FIELD_ROWS - lineIndex] = line;

	checkForFullLines(field, score);
}

void startGame() {
	vector<string> field = generateField();

	int score = 0;

	printField(field);
	addNewLine(field);
	timing();
	checkForFullLines(field, score); //update
	printField(field);

	while (!isGameOver(field)) {
		timing();

		cout << "Score: " << score << endl;
		cout << endl;

		printField(field);
		update(field, score);
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