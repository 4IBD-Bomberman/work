/*
 * Plateau.h
 *
 *  Created on: 11 mai 2018
 *      Author: user
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_
#include "Case.h"
#include "Bombe.h"
#include "Mur.h"
#include "Item.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <map>

class Plateau {
private:
	Case** tab;
	int X;
	int Y;

	void initTab();
	void initTourTab();
	void initMillieuTab();
	void initMurDestructible();
public:
	Plateau(const int l, const int h);
	virtual ~Plateau();
	friend std::ostream& operator<<(std::ostream& ostr, const Plateau& p);

};

#endif /* PLATEAU_H_ */
