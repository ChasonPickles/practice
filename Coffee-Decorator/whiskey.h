#ifndef WHISKEY_H
#define WHISKEY_H

#include "topping.h"

class Whiskey : public Topping {
	public:
		Whiskey (Coffee * cup) : Topping (cup){}
		float getPrice (){
			return 6.49 + next->getPrice (); // whiskey is expensive my friends
		}
		string desc(){
			return  next->desc() + ", whiskey (!)";
		}
};

#endif
