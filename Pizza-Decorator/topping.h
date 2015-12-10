#ifndef TOPPING_H
#define TOPPING_H

#include "pizza.h"

class Topping : public Pizza {
	protected:
	Pizza * next;
	
	public:	

	Topping (Pizza * p) : next (p){}

	~Topping (){
		delete next;
	}
};

#endif
