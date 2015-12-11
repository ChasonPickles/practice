#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "bookvisitor.h"
#include "book.h"

using namespace std;

class Catalog : public BookVisitor{
	
	// see numType function
	//int numComics;
	//int numCSBooks;

	vector <Book *> books; // the garbage will be cleaned by the visitor himself
	
	public:
		void visit (Comic & c){
			//numComics += 1;
			
			cout << "A comic about titled \"" << c.getTitle() << "\" by " << c.getAuthor() << " with " << c.getHero() << " as the protagonist(s)" << endl;
		}
		void visit (CSBook & c){
			//numCSBooks += 1;
			
			cout << "A CSBook titled \"" << c.getTitle() << "\" by "<< c.getAuthor() << ", with the topic being " << c.getTopic() << endl;
		}

		void addBook (Book * b){
			books.push_back(b);
		}	
		
		// prints the number of each type of book you have in your library
		/*void numType(){
			numComics = numCSBooks = 0;
			for (vector<Book *>::iterator it = books.begin(); it != books.end(); it++){
				(*it)->accept(*this);
			}	
			cout << "We have " << numComics << " comics and " << numCSBooks << " books about CS " <<endl;
		}*/

		void dumpCatalog (){
			int i = 0;
			for (vector<Book *>::iterator it = books.begin(); it != books.end(); it++){
				cout << i << " - "; i++;
				(*it)->accept(*this);
			}
		}

		~Catalog (){
			for (vector<Book*>::iterator it = books.begin(); it != books.end(); it++){
				delete *it;
			}
		}
};

#endif
