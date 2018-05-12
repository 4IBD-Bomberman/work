/*
 * Bombe.cpp
 *
 *  Created on: 11 mai 2018
 *      Author: user
 */

#include "Bombe.h"

Bombe::Bombe(int r, int o, int t): rayon(r), owner(o), tours(t) {
}
Bombe::~Bombe() {
}

bool Bombe::isDestructible() const{
	return true;
}
bool Bombe::isCollapsable() const{
	return true;
}
char Bombe::getCharAffichage() const{
	return 'o';
}
int Bombe::getRayon() const{
	return rayon;
}
void Bombe::setRayon(int r){
	rayon = r;
}
int Bombe::getOwner() const{
	return owner;
}
void Bombe::setOwner(int o){
	owner = o;
}
int Bombe::getTours() const{
	return tours;
}
void Bombe::setTours(int t){
	tours = t;
}
bool Bombe::diminuerTours(){
	tours--;
	return tours == 0;
}
