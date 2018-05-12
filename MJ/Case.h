/*
 * Case.h
 *
 *  Created on: 11 mai 2018
 *      Author: user
 */

#ifndef CASE_H_
#define CASE_H_

class Case {
private:

public:
	Case();
	virtual ~Case();
	virtual bool isDestructible() const;
	virtual bool isCollapsable() const;
	virtual char getCharAffichage() const;
};

#endif /* CASE_H_ */
