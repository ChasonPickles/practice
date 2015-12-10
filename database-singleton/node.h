#ifndef LIST_H
#define LIST_H

// called a list but will have stack like behaviour
#include <iostream>

struct Node {
	int data;
	Node * next;
	
	// initializes the new node to have the 
	// given value as the information, and the 
	// the rest of the list to be NULL
	Node (int data):data(data),next(NULL){}
	Node (int data, Node * next):data(data),next(next){}// the CLASS WILL NOW HANDLE THE MEMORY, VERY DANGEROUS
	Node (const Node & other){
		this->data = other.data;
		this->next = NULL;
		if (other.next != NULL){
			this->next = new Node (*other.next);
		}
	}
	~Node(){delete next;}
	
	/* 
	// A generic implementation of the asssignment operator:
	Node & operator= (const Node & other){
		if (this == other){
			return *this;
		}else{
			delete this->next; // I just got rid of all my dynamic memory
			this->data = other.data;
			this->next = new Node(*other.next); // pointer to a new copy
		}
	}*/

	
	// what do we need to implement the assignment operator in this style?
	// A working copy constructor
	// A working destructor
	// A working swap function (this can be quick)!!
	
	Node & operator= (const Node & other){
		Node temp (other);	// temp is a copy of other
		this->swap (temp); // temp now carries all of the values of temp, and temp vice versa
		return *this;
		// this is where your properly implemented ctor works	
	}
	
	// gets called on an object, swap your fields with another guy:
	void swap (Node & other){
		int tmpdata    = this->data;
		Node * tmpnext = this->next;

		this->data = other.data;
		this->next = other.next;

		other.data = tmpdata;
		other.next = tmpnext;
	}

	void print (std::ostream & out = std::cout){
		if (this->next == NULL){
			out << this->data << std::endl;
		}else{
			out << this->data << ", ";
			(*(this->next)).print(out);
		}		
	}
};

#endif
