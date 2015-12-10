#include <iostream>
using namespace std;

struct base{
	virtual void info (){cout << "I am base" << endl;}
};

struct derived : public base{
	void info (){cout << "I am derived" << endl;}

	void secondary(){cout << "Fuck bichis get moneh" << endl;}
};

int main (){
	base * ptr = new derived;

	ptr->info();

	//ptr->secondary();

	derived & b1 = *((derived*)ptr);

	b1.secondary();

	delete ptr;
}
