#include <cstdlib>
#include "wallet.h"
#include <iostream>
using namespace std;


int main (){
	atexit(Wallet::cleanup);

	Wallet * wallet = Wallet::getInstance();	
	Wallet * same_wallet = Wallet::getInstance();

	wallet->addNet(5000);
	cout << wallet->getMoney() << endl;

	same_wallet->addNet(-200);
	cout << same_wallet->getMoney() << endl;

	wallet->addNet(0);
	cout << wallet->getMoney() << endl;


}
