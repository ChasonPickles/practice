#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

#include "bookvisitor.h"

class Book{
	protected:
		string title;
		string author;
	public:
		Book (string title, string author);
		
		string getTitle();
		string getAuthor();
		
		virtual void accept (BookVisitor &) = 0;	

		virtual ~Book () = 0;
};

Book::Book(string title, string author): title(title), author (author){}

Book::~Book(){}

string Book::getTitle(){
	return title;
}

string Book::getAuthor(){
	return author;
}


class Comic : public Book {
	string hero;
	public:
		Comic (string title, string author, string hero) : Book (title, author), hero (hero) {}
		string getHero () {return hero;}
		
		void accept (BookVisitor & v){
			v.visit (*this);
		}

		~Comic (){}
};


class CSBook : public Book {
	string topic;
	public:
		CSBook (string title, string author, string topic) : Book (title, author), topic(topic) {}
		string getTopic () {return topic;}

		void accept (BookVisitor &  v){
			v.visit (*this);
		}

		~CSBook(){}
};

#endif
