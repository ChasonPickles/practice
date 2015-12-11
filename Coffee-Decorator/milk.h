#ifndef MILK_H
#define MILK_H

#include "topping.h"

class Milk : public Topping {
	public:
		Milk (Coffee * cup) : Topping (cup){}
		float getPrice (){
			return 0.15 + next->getPrice (); // this is fancy hipster milk lols
		}
		string desc(){
			return next->desc() +  ", fancy milk";
		}
};

#endif
