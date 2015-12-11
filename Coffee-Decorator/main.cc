#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "coffee.h"
#include "homebrew.h"
#include "topping.h"
#include "whiskey.h"
#include "milk.h"
#include "caramel.h"
using namespace std;

int main (){

	string cmd;

	while (true){
		system("clear");
		cout << "We have a coffee coming right up, would you like, it with some toppings <yes> - continue <no> - end <other> - invalid" << endl;
		cin >> cmd;
	
		if (cmd == "no"){
			cout << "See ya!" << endl;
			break;
		}
	
		// if you can't type the right command, you deserve to buy a coffee anyway!
	
		cout << "The toppings are: <1> Milk <2> Caramel <3> Whiskey <4> end"  << endl;	

		Coffee * order = new Homebrew;

		int choice;
		while (true){
			cin >> choice;

			if (cin.fail()){
				exit(1);
			}

			if (choice == 1){
				order = new Milk (order);
			
			}else if (choice == 2){
				order = new Caramel (order);

			}else if (choice == 3){
				order = new Whiskey (order);

			}else { // if you can't type the right command, you don't derserve a second choice!
				break;
			}
		}

		system ("clear");		

		cout << endl <<  "Your coffee has all this stuff:" << endl << order->desc() << endl;
		cout << "Your total comes out to $"<< std::setprecision (2) << order->getPrice()*1.13 << ", type anything to continue" << endl << endl;
		cin >> cmd;
		delete order;
	}
}
