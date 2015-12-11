#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
using namespace std;

class Coffee{
	public:
		virtual float getPrice () = 0;
		virtual string desc () = 0;
		virtual ~Coffee(){}
};

#endif
