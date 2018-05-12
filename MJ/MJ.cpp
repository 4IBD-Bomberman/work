//============================================================================
// Name        : Bomberman_Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Plateau.h"

int main() {
	Plateau* p = new Plateau(21,21);
	cout << *p;
	return 0;
}
