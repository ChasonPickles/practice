#include "database.h"

int main(){
	Database d1;
	Database d2;
	Database d3;
	const Database d4;

	d3.push (10);
	d2.push (5);
	d1.pop();
	d1.push(3000);
	d3.push(10);
	d2.push(6);

	d1.print();
	d2.print();
	d3.print();
	d4.push(10);
	d4.print ();
}
