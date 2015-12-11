#include <iostream>
using namespace std;
#include "book.h"
#include "catalog.h"

int main (){
	Comic c ("civil war", "stan lee", "iron man");

	Catalog library;

	library.addBook (new Comic ("civil war", "stan lee", "avengers"));
	library.addBook (new CSBook ("art of prog." , "donal knuth", "general"));	
	library.addBook (new Comic ("dawn", "stan lee", "avengers"));
	library.addBook (new CSBook ("AIMA", "a group of authors", "AI"));
	library.addBook (new Comic ("THE END", "stan lee", "avengers"));
	library.addBook (new CSBook ("Algorithms", "a group of authors", "Algos"));

	library.dumpCatalog();
}
