#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BricksLogic.h"
#include "FieldLogic.h"
#include "Print.h"

bool isGameOver(const vector<string> field) {
	if (!isEmptyLine(field.front())) {
		cout << "GAME OVER" << endl;;
		return true;
	}
	return false;
}

void startGame() {
	vector<string> field = generateField();

	int score = 0;

	printField(field, score);

	while (!isGameOver(field)) {
		addNewLine(field);
		printField(field, score);
		//timingAdditional();
		checkForFullLines(field, score);

		dropBrick(field, score);
		printField(field, score);
		checkForFullLines(field, score);

		updateLine(field);
		printField(field, score);
		//timingAdditional();
		checkForFullLines(field, score);

		dropBrick(field, score);
		printField(field, score);
		checkForFullLines(field, score);

	}

	cout << "Score: " << score << endl;
	cout << endl;
	printField(field, score);
}