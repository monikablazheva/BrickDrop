//#pragma once
//#include <iostream>
//#include <string>
//#include <vector>
//#include "BricksLogic.h"
//
//
//bool isEmptyLine(string line) { //if each charcter of the line is "_"(empty) return true
//
//	for (size_t i = 0; i < FIELD_COLS; i++)
//	{
//		if (line[i] != '_') {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool isFullLine(string line) {
//	for (size_t i = 0; i < FIELD_COLS; i++)
//	{
//		if (line[i] == '_') {
//			return false;
//		}
//	}
//	return true;
//}
//
//void clearLine(string& line) {
//	for (size_t i = 0; i < line.size(); i++)
//	{
//		line[i] = '_';
//	}
//}
//
//void checkForFullLines(vector<string>& field, int& score) {
//	if (isFieldEmptyValidation(field)) {
//		return;
//	}
//
//	for (size_t i = 1; i < FIELD_ROWS; i++)
//	{
//		if (isFullLine(field[i])) {
//			clearLine(field[i]);
//			score += 10;
//			checkForFullLines(field, score);
//			printField(field, score);
//			//checkForFullLines(field, score);
//		}
//	}
//}
//
//string newLine() {
//
//	string line;
//
//	while (line.size() < FIELD_COLS) {
//
//		if (isBrickEmpty()) {
//			line += "_";
//		}
//		else line += newBrick(FIELD_COLS - line.size());
//
//	}
//
//	if (isEmptyLine(line)) {
//		newLine();
//	}
//
//	return line;
//}
//
//vector<string> generateField() {
//
//	vector<string> field;
//
//	for (size_t i = 0; i < FIELD_ROWS; i++)
//	{
//		field.push_back("________");
//	}
//	return field;
//}
//
//void printField(const vector<string> field, int score) {
//
//	if (isFieldEmptyValidation(field)) {
//		return;
//	}
//
//	timing();
//
//	cout << "Score: " << score << endl;
//	cout << endl;
//
//	for (auto str : field) {
//		cout << str << endl;
//	}
//}
//
//void addNewLine(vector<string>& field) {
//
//	if (isFieldEmptyValidation(field)) {
//		return;
//	}
//
//	field.erase(field.begin()); //removes first line
//	field.push_back(newLine()); //adds last line
//
//}
//
//void input(int& line, int& index, char& direction, int& length) {
//
//	//LINE INPUT AND VALIDATION
//	cout << "Enter line (starting from the bottom): ";
//	cin >> line;
//	if (line < 1 || line > FIELD_ROWS - 1) {
//		cout << "Exception: INVALID LINE index" << endl;
//		return;
//	}
//
//	//BRICK INPUT AND VALIDATION
//	cout << "Beginning index of the brick you want to move: ";
//	cin >> index;
//	if (index < 0 || index >= FIELD_COLS) {
//		cout << "Exception: INVALID BRICK index" << endl;
//		return;
//	}
//
//	//DIRECTION INPUT AND VALIDATION
//	cout << "Direction (l for left or r for rigth): ";
//	cin >> direction;
//	if (!(direction == 'l' || direction == 'r')) {
//		cout << "Exception: INVALID DIRECTION symbol" << endl;
//		return;
//	}
//
//	//LENGTH INPUT AND VALIDATION
//	cout << "Length of the move: ";
//	cin >> length;
//	if (length <= 0 || length >= FIELD_COLS) {
//		cout << "Exception: INVALID length" << endl;
//		return;
//	}
//}
//
//void updateLine(vector<string>& field) {
//	int row, startIndex, length;
//	char direction;
//	input(row, startIndex, direction, length); //GET DATA FROM USER
//
//	int indexLine = FIELD_ROWS - row;
//	string line = field[indexLine]; //LINE TO UPDATE
//	int destinationIdx = destinationIndex(direction, startIndex, length);
//	int brickLen = lengthBrick(line, startIndex);
//	moveBrickInLine(line, startIndex, destinationIdx, brickLen);
//	field[indexLine] = line;
//}