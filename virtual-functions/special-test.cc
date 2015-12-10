#include "books.h"

int main (){
	cout << "Size of a regular book: " << sizeof(Book) << endl;	
	cout << "Size of a CS book:      " << sizeof(CSBook) << endl;

	Book * book1 = new CSBook ("AIMA", "artificial intelligence");

	//Book * ptr =  (new CSBook (string("Logic in Computer Science"), string("Prop/Pred Logic, Proof systems")));

	//Book & book2 = *ptr;	
	//book1->info();
	//book2.info();

	delete book1;
	//delete ptr;
}
