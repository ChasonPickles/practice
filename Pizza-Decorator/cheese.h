#ifndef CHEESE_H
#define CHEESE_H

class Cheese : public Topping {
	public:

	Cheese (Pizza * p) : Topping (p) {}

	float price () {
		return 3 + next->price();
	}

	string description (){
		return next->description() + "With cheese. ";
	}

};

#endif
