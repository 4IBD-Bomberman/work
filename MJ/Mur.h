/*
 * Mur.h
 *
 *  Created on: 11 mai 2018
 *      Author: user
 */

#ifndef MUR_H_
#define MUR_H_
#include "Case.h"

class Mur: public Case {
private:
	bool destructible;
public:
	Mur(bool destructible);
	virtual ~Mur();
	virtual bool isDestructible() const;
	virtual bool isCollapsable() const;
	virtual char getCharAffichage() const;
};

#endif /* MUR_H_ */
