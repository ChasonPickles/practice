#ifndef DATABASE_H
#define DATABASE_H

#include "node.h"
#include <assert.h>

class Database{
	static Node * head;
	static int len;
	
	public:
	Database(){}
	
	static void push (const int data);

	static int pop ();

	static void print ();// const;
};

#endif
