#include <memory>
#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
using namespace std;

struct A {
	string message;
	~A(){
		//cout << "I am being destructed" << endl;
	}
};

void h (){
	if (rand() % 2){
		throw 1;
	}
}

// f is factory function that makes and retuns me an A
auto_ptr<A > f (){
	auto_ptr<A > ptr (new A);
	ptr->message = "hello";

	h();

	return ptr;
}

// notice that no matter what, we will never leak memory :)

int main (){
	srand(time(NULL));
	
	auto_ptr<A> ptr(NULL);
	try {
		auto_ptr<A> ptr = f();
		cout << ptr->message << endl;
	}catch (...){
		cout << "Something went wrong when trying to make and instance of A" << endl;
	}
}
