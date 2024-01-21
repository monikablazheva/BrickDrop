#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BricksLogic.h"

bool isFieldEmptyValidation(const vector<string> field) {

	if (field.empty()) {
		cout << "Exception: EMPTY FIELD!";
		return true;
	}
	return false;
}

bool isEmptyLine(string line) { //if each charcter of the line is "_"(empty) return true

	for (size_t i = 0; i < FIELD_COLS; i++)
	{
		if (line[i] != '_') {
			return false;
		}
	}
	return true;
}

bool isFullLine(string line) {
	for (size_t i = 0; i < FIELD_COLS; i++)
	{
		if (line[i] = '_') {
			return false;
		}
	}
	return true;
}

string newLine() {

	string line;

	while (line.size() < FIELD_COLS) {

		if (isBrickEmpty()) {
			line += "_";
		}
		else line += newBrick(FIELD_COLS - line.size());

	}

	if (isEmptyLine(line)) {
		newLine();
	}

	return line;
}

vector<string> generateField() {

	vector<string> field;

	for (size_t i = 0; i < FIELD_ROWS; i++)
	{
		field.push_back("________");
	}
	return field;
}

void printField(const vector<string> field) {

	if (isFieldEmptyValidation(field)) {
		return;
	}

	for (auto str : field) {
		cout << str << endl;
	}
}

void addNewLine(vector<string>& field) {

	if (isFieldEmptyValidation(field)) {
		return;
	}

	field.erase(field.begin()); //removes first line
	field.push_back(newLine()); //adds last line

}

void removeAtLine(vector<string>& field, int index) {
	if (isFieldEmptyValidation(field)) {
		return;
	}

	field.erase(field.begin() + index);
}