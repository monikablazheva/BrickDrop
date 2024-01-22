//#pragma once
//#include <iostream>
//#include <string>
//#include <vector>
//#include "Timing.h"
//
//using namespace std;
//
//bool isFieldEmptyValidation(const vector<string> field) {
//
//	if (field.empty()) {
//		cout << "Exception: EMPTY FIELD!";
//		return true;
//	}
//	return false;
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