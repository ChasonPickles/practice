#include <iostream>
#include "database.h"
#include "node.h"

int Database::len = 0;
Node * Database::head = NULL;

void Database::push (const int data){
	Node * temp = new Node (data, head);
	head = temp;
	len += 1;		
}


int Database::pop (){
	assert(len != 0);
	int tmp = head->data;
	
	Node * tmpnext = head->next;
	head->next = NULL;
	delete head;
	
	head = tmpnext;
}

void Database::print (){// const{
	(*head).print();
}
