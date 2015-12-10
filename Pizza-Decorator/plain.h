#ifndef PLAIN_H
#define PLAIN_H

#include "pizza.h"

class Plain : public Pizza {
	public:
	float price (){
		return 5.99;
	}
	string description (){
		return "Crust & Sauce. ";
	}
};

#endif
