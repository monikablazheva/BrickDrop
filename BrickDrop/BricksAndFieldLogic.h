#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

const int FIELD_ROWS = 10;
const int FIELD_COLS = 8;
const int MAX_BRICK_SIZE = 4;
const int ALPHABET_SIZE = 25;

#pragma region "HELPERS"
void swap(char& a, char& b) {
	int temp = a;
	a = b;
	b = temp;
}

int randomNumber(int start, int end) {

	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(start, end);
	int randomNumber = dis(gen);

	return randomNumber;
}

char randomLetter() {
	char randomLetter = 'a' + randomNumber(0, ALPHABET_SIZE);
	return randomLetter;
}

bool isUpper(const char ch) {
	if (ch >= 'A' && ch <= 'Z') return true;
	return false;
}

void input(int& line, int& index, char& direction, int& length) {

	//LINE INPUT AND VALIDATION
	cout << "Enter line (starting from the bottom): ";
	cin >> line;
	if (line < 1 || line > FIELD_ROWS - 1) {
		cout << "Exception: INVALID LINE index" << endl;
		return;
	}

	//BRICK INPUT AND VALIDATION
	cout << "Beginning index of the brick you want to move: ";
	cin >> index;
	if (index < 0 || index >= FIELD_COLS) {
		cout << "Exception: INVALID BRICK index" << endl;
		return;
	}

	//DIRECTION INPUT AND VALIDATION
	cout << "Direction (l for left or r for rigth): ";
	cin >> direction;
	if (!(direction == 'l' || direction == 'r')) {
		cout << "Exception: INVALID DIRECTION symbol" << endl;
		return;
	}

	//LENGTH INPUT AND VALIDATION
	cout << "Length of the move: ";
	cin >> length;
	if (length <= 0 || length >= FIELD_COLS) {
		cout << "Exception: INVALID length" << endl;
		return;
	}
}

#pragma endregion "HELPERS"

#pragma region "FIELD LOGIC"

vector<string> generateField() {

	vector<string> field;

	for (size_t i = 0; i < FIELD_ROWS; i++)
	{
		field.push_back("________");
	}
	return field;
}

bool isFieldEmptyValidation(const vector<string> field) {

	if (field.empty()) {
		cout << "Exception: EMPTY FIELD!";
		return true;
	}
	return false;
}

void printField(const vector<string> field, int score) {

	if (isFieldEmptyValidation(field)) {
		return;
	}

	timing();

	cout << "Score: " << score << endl;
	cout << endl;

	for (auto str : field) {
		cout << str << endl;
	}
}

#pragma endregion "FIELD LOGIC"

#pragma region "BRICKS LOGIC"

bool isEmptyLine(string line);

string newLine();

bool isBrickEmpty() {
	int chance = randomNumber(0, 1);
	if (chance == 0) {
		return true;
	}
	return false;
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

	//a brick is either "_"(empty) or a string.
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

int lengthBrick(string line, int index) {
	if (!isUpper(line[index])) {
		cout << "Exception: invalid BRICK BEGINNING index";
		return -1;
	}
	
	index++;
	int count = 1;
	for (size_t i = index; (i < FIELD_COLS) && (!isUpper(line[i])) && (line[i]!='_'); i++)
	{
		count++;
	}

	return count;
}

int destinationIndex(char direction, int startIndex, int brickLen) {
	int destinationIndex = 0;

	if (direction == 'r') {
		destinationIndex = startIndex + brickLen;
	}
	else if (direction == 'l') {
		destinationIndex = startIndex - brickLen;
	}

	return destinationIndex;
}

bool isValidBrickMove(string line, int destinationIdx) {

	if (destinationIdx < 0 || destinationIdx >= FIELD_COLS || line[destinationIdx] != '_') {
		cout << "Invalid brick move";
		return false;
	}
	return true;
}

#pragma endregion "BRICKS LOGIC"

#pragma region "DROP BRICKS"

bool canDrop(const vector<string> field, int i, int j, int brickLen) {

	bool canDrop = true;
	for (int k = 0; k < brickLen; k++)
	{
		if (field[i + 1][j + k] != '_')
		{
			canDrop = false;
			break;
		}
	}

	return canDrop;
}

void swapCurrentBrick(vector<string>& field, int i, int j, int brickLen) {
	for (int k = 0; k < brickLen; k++)
	{
		swap(field[i + 1][j + k], field[i][(j + k)]);
	}
}

void searchForBricksLine(vector<string>& field, int i, bool& hasDropped) {
	for (int j = 0; j < FIELD_COLS; j++)
	{
		if (isUpper(field[i][j]))
		{
			int brickLen = lengthBrick(field[i], j);
			bool canDropCurrentBrick = canDrop(field, i, j, brickLen);

			if (canDropCurrentBrick)
			{
				swapCurrentBrick(field, i, j, brickLen);
				j += brickLen - 1;
				hasDropped = true;

			}
		}
	}
}

void dropBricksAllField(vector<string>& field, bool& hasDropped) {
	int bottom = FIELD_ROWS - 1;

	for (int i = 1; i < bottom; i++) {

		if (!isEmptyLine(field[i])) {
			searchForBricksLine(field, i, hasDropped);
		}
	}
}

void dropBricksAllFieldRecursive(vector<string>& field, int score) {

	bool hasDropped = false;
	dropBricksAllField(field, hasDropped);

	if (hasDropped) {
		printField(field, score);
		dropBricksAllFieldRecursive(field, score);
	}
}

#pragma endregion "DROP BRICKS"

#pragma region "LINES LOGIC"

bool isEmptyLine(string line) { //if each charcter of the line is "_"(empty) return true

	for (size_t i = 0; i < FIELD_COLS; i++)
	{
		if (line[i] != '_') {
			return false;
		}
	}
	return true;
}

void moveBrickInLine(string& line, int startIndex, int destination, int brickLen) {

	int endOfBrick = startIndex + brickLen - 1;

	if (startIndex < destination) //RIGTH
	{
		int destinationOfBrickEnd = destination + brickLen - 1;
		if (!isValidBrickMove(line, destinationOfBrickEnd)) {
			return;
		}

		for (int i = endOfBrick; i >= startIndex; i--)
		{
			for (int j = i; j < destinationOfBrickEnd; j++)
			{
				swap(line[j], line[j + 1]);
			}
			destinationOfBrickEnd--;
		}
	}

	else if (startIndex > destination) //LEFT
	{
		int destinationOfBrickStart = destination;
		if (!isValidBrickMove(line, destinationOfBrickStart)) {
			return;
		}

		for (int i = startIndex; i <= endOfBrick; i++)
		{
			for (int j = i; j > destinationOfBrickStart; j--)
			{
				swap(line[j], line[j - 1]);
			}
			destinationOfBrickStart++;
		}
	}
}

bool isFullLine(string line) {
	for (size_t i = 0; i < FIELD_COLS; i++)
	{
		if (line[i] == '_') {
			return false;
		}
	}
	return true;
}

void clearLine(string& line) {
	for (size_t i = 0; i < line.size(); i++)
	{
		line[i] = '_';
	}
}

void checkForFullLines(vector<string>& field, int& score) {
	if (isFieldEmptyValidation(field)) {
		return;
	}

	for (size_t i = 1; i < FIELD_ROWS; i++)
	{
		if (isFullLine(field[i])) {
			clearLine(field[i]);
			score += 10;
			checkForFullLines(field, score);
			printField(field, score);
		}
	}
}

void addNewLine(vector<string>& field) {

	if (isFieldEmptyValidation(field)) {
		return;
	}

	field.erase(field.begin()); //removes first line
	field.push_back(newLine()); //adds last line

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

void updateLine(vector<string>& field) {
	int row, startIndex, length;
	char direction;
	input(row, startIndex, direction, length); //GET DATA FROM USER

	int indexLine = FIELD_ROWS - row;
	string line = field[indexLine]; //LINE TO UPDATE
	int destinationIdx = destinationIndex(direction, startIndex, length);
	int brickLen = lengthBrick(line, startIndex);
	moveBrickInLine(line, startIndex, destinationIdx, brickLen);
	field[indexLine] = line;
}

#pragma endregion "LINES LOGIC"
