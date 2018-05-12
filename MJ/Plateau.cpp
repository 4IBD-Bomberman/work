/*
 * Plateau.cpp
 *
 *  Created on: 11 mai 2018
 *      Author: user
 */

#include "Plateau.h"

Plateau::Plateau(const int l, const int h) : X(l), Y(h) {
    tab = new Case *[l * h];
    for (int i = 0; i < X * Y; i++) {
        tab[i] = new Case();
    }
    initTab();
}

Plateau::~Plateau() {
    delete[] tab;
}

void Plateau::initTab() {
    initTourTab();
    initMillieuTab();
    initMurDestructible();
}

void Plateau::initTourTab() {
    // 1er ligne
    for (int i = 0; i < X; i++) {
        tab[i] = new Mur(false);
    }
    // 1er col et derniere col
    for (int i = X; i < X * (Y - 1); i += X) {
        tab[i] = new Mur(false);
        tab[i + X - 1] = new Mur(false);
    }
    //derniere ligne
    for (int i = X * (Y - 1); i < X * Y; i++) {
        tab[i] = new Mur(false);
    }
}

void Plateau::initMillieuTab() {
    for (int j = 2; j < Y - 2; j += 2) {
        for (int i = X * j; i < X * (j + 1); i += 2) {
            tab[i] = new Mur(false);
        }
    }
}

void Plateau::initMurDestructible() {
    srand(time(NULL));
    int nbMur = (X * Y) * 0.2;
    for (int i = 0; i < nbMur; i++) {
        int x = rand() % X;
        int y = rand() % Y;
        if (tab[y * X + x]->getCharAffichage() == '_') {
            tab[y * X + x] = new Mur(true);
        } else {
            i--;
        }
    }
}

std::ostream &operator<<(std::ostream &ostr, const Plateau &p) {
    for (int i = 0; i < p.Y; i++) {
        for (int j = 0; j < p.X; j++) {
            ostr << p.tab[i * p.X + j]->getCharAffichage() << " ";
        }
        ostr << std::endl;
    }
    return ostr;
}

bool Plateau::isOKToPutJoeurICI(int x, int y, char *tabC) {
    /*On regarde les case H, B, G, D
    Si rien n'est accessible -> return false;
    Si on peut avancer dans une autre direction qu'avant -> return true;
    Si on peut avancer que dans la même direction qu'avant -> return sur le meme algo mais sur la prochaine case*/
    // -x = G  ; +x = D  ; -y = B ; ; +y = H
    if (tabC[(y * X + x) - 1] != '_' && tabC[(y * X + x) + 1] != '_' && tabC[(y * X + x) + y] != '_' &&
        tabC[(y * X + x) - y] != '_') {
        return false;
    }
    if (tabC[y * X + x] != 'G' && tabC[y * X + x] != 'D' && tabC[y * X + x] != 'H' && tabC[y * X + x] != 'B') {
        //SI  JOUEUR -> regarder HGBD
        if (tabC[(y * X + x) - 1] == '_') {
            tabC[(y * X + x) - 1] = 'G';
            return isOKToPutJoeurICI(x - 1, y, tabC);
        }
        if (tabC[(y * X + x) + 1] == '_') {
            tabC[(y * X + x) + 1] = 'D';
            return isOKToPutJoeurICI(x + 1, y, tabC);
        }
        if (tabC[(y * X + x) - y] == '_') {
            tabC[(y * X + x) - y] = 'B';
            return isOKToPutJoeurICI(x, y - 1, tabC);
        }
        if (tabC[(y * X + x) + y] == '_') {
            tabC[(y * X + x) + y] = 'H';
            return isOKToPutJoeurICI(x, y + 1, tabC);
        }
        if (tabC[y * X + x] == 'G' && tabC[y * X + x] == 'D') {
            return isOKToPutJoeurICI(x, y + 1, tabC);//doute ici
        } else if (tabC[y * X + x] == 'H' && tabC[y * X + x] == 'B') {
            return isOKToPutJoeurICI(x + 1, y, tabC);//doute ici
        } else {
            return true;
        }
    }
    //SI JOUEUR -> peut aller gauche et droite return isOKtoPUT
    //				peut aller bas et haut return isOKtoput
    // else return true
}



