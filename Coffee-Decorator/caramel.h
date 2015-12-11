#ifndef CARAMEL_H
#define CARAMEL_H

#include "topping.h"

class Caramel : public Topping {
	public:
		Caramel (Coffee * cup) : Topping (cup){}
		float getPrice (){
			return 1.15 + next->getPrice ();
		}
		string desc(){
			return next->desc() + ", fair trade caramel";
		}
};

#endif
