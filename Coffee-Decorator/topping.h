#ifndef TOPPING_H
#define TOPPING_H

#include "coffee.h"

class Topping : public Coffee {
	protected:
	Coffee * next;
	
	public:
	Topping(Coffee * cup) : next(cup){}

	virtual ~Topping(){
		delete next;
	}
};

#endif
