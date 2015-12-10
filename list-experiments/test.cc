#include "node.h"

int main (){
	//Node mylist (10);		

	Node myList (10, new Node (9, new Node (11)));
	Node newList (10);
	newList.print();
	newList = myList;
	myList.print();
	newList.print();

}
