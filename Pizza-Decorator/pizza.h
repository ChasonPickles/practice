#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
using namespace std;

class Pizza {

	public:
	virtual float price () = 0;
	virtual string description () = 0;
	
	virtual ~Pizza(){}
};

#endif
