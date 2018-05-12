/*
 * Item.cpp
 *
 *  Created on: 11 mai 2018
 *      Author: user
 */

#include "Item.h"

Item::Item(char t): type(t){
}

Item::~Item() {
}

bool Item::isDestructible() const{
	return false;
}
bool Item::isCollapsable() const{
	return true;
}
char Item::getCharAffichage() const{
	return type;
}
char Item::getType() const{
	return type;
}
void Item::setType(char t){
	type = t;
}
