#ifndef HOMEBREW_H
#define HOMEBRE_H

#include "coffee.h"

class Homebrew : public Coffee {

	float getPrice(){
		return 2.00;
	}

	string desc(){
		return "Regular Homebrew";
	}
	~Homebrew(){}

};

#endif
