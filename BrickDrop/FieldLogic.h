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