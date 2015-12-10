#ifndef WALLET_H
#define WALLET_H

#include <iostream>
using namespace std;

class Wallet{

	static Wallet * instance; // instantianitated to null in wallet.cc
	int money;	

	Wallet (){
		money = 0;
	}
	
	public:

	static Wallet * getInstance (){
		if (instance){ return instance;}
		instance = new Wallet;
		return instance;
	}

	void addNet (int delta){
		money += delta;
	}
	
	int getMoney (){
		return money;
	}

	void static cleanup (){
		cout << "cleaning up" << endl;
		delete instance;
	} 
};

#endif
