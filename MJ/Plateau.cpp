/*
 * Plateau.cpp
 *
 *  Created on: 11 mai 2018
 *      Author: user
 */

#include "Plateau.h"

Plateau::Plateau(const int l,const int h ): X(l), Y(h) {
	tab = new Case*[l*h];
	for(int i=0; i<X*Y; i++){
		tab[i] = new Case();
	}
	initTab();
}

Plateau::~Plateau() {
	delete[] tab;
}

void Plateau::initTab(){
	initTourTab();
	initMillieuTab();
	initMurDestructible();
}

void Plateau::initTourTab(){
	// 1er ligne
	for(int i = 0; i<X; i++){
		tab[i] = new Mur(false);
	}
	// 1er col et derniere col
	for(int i = X; i<X*(Y-1); i+=X){
		tab[i] = new Mur(false);
		tab[i+X-1] = new Mur(false);
	}
	//derniere ligne
	for(int i = X*(Y-1); i< X*Y; i++){
		tab[i] = new Mur(false);
	}
}

void Plateau::initMillieuTab(){
	for(int j= 2; j<Y-2; j+=2){
		for(int i = X*j; i<X*(j+1); i+=2){
			tab[i] = new Mur(false);
		}
	}
}

void Plateau::initMurDestructible(){
	srand(time(NULL));
	int nbMur = (X*Y)*0.2;
	for (int i = 0; i<nbMur; i++) {
		int x=rand()%X;
		int y=rand()%Y;
		if (tab[y*X+x]->getCharAffichage() == '_'){
			tab[y*X+x] = new Mur(true);
		}else {
			i--;
		}
	}
}

std::ostream& operator<<(std::ostream& ostr, const Plateau& p){
	for(int i=0; i<p.Y; i++){
		for (int j=0; j<p.X; j++){
			ostr << p.tab[i*p.X+j]->getCharAffichage() << " ";
		}
		ostr << std::endl;
	}
	return ostr;
}

