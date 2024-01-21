#pragma once
#include <iostream>
#include <thread>

using namespace std;

void timing() {
	this_thread::sleep_for(1000ms);
	system("cls");
}

