/**
*
Solution to course project # 3
Introduction to programming course
Faculty of Mathematics and Informatics of Sofia University
Winter semester 2023/2024
*
@author Monika Blazheva
@idnumber 7MI0600350
@compiler VC
*
Timing helper file
*
*/

#pragma once
#include <iostream>
#include <thread>

using namespace std;

void timing() {
	this_thread::sleep_for(1000ms);
	system("cls");
}

