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
#include <utility>

class Plateau {
private:
	Case*** tab;
	int X;
	int Y;

	void initTab();
	void initTourTab();
	void initMillieuTab();
	void initMurDestructible();
	std::pair<int,int> getDirPosition(int x, int y, char dir);
	bool isOKToPutJoeurICI(int x, int y, char * tabC); //c'est Charlotte qui a mis ce nom de merde
public:
	Plateau(const int l, const int h);
	virtual ~Plateau();
	friend std::ostream& operator<<(std::ostream& ostr, const Plateau& p);


};

#endif /* PLATEAU_H_ */
