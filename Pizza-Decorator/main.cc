#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#include "pizza.h"
#include "plain.h"
#include "topping.h"
#include "cheese.h"

int main (){
	Pizza * basic = new Plain;
	
	basic = new Cheese (basic);
	

	cout << basic->price() << endl;
	cout << basic->description() << endl;

	delete basic;
}
