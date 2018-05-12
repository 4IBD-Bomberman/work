/*
 * Case.cpp
 *
 *  Created on: 11 mai 2018
 *      Author: user
 */

#include "Case.h"

Case::Case() {
}

Case::~Case() {
}

bool Case::isDestructible() const{
	return true;
}

bool Case::isCollapsable() const{
	return false;
}

char Case::getCharAffichage() const{
	return '_';
}
