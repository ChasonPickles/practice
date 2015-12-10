#include <iostream>
using namespace std;

class Book{
	string title;

	// for the purposes of field access I want this to be available	
	protected:
	string get_title(){
		return this->title;
	}

	public:
	Book(string title):title(title){}
	
	virtual ~Book(){}

	// without the virtual keywork every call to info from the subclasses would yield just the title
	virtual void info(){cout << "Title: " << title << ";" << endl;}
};

class CSBook : public Book{
	string topic;

	protected:
	string get_topic(){
		return this->topic;
	}

	public:
	CSBook(string title, string topic):Book(title),topic(topic){}
	void info(){cout << "Title: " << get_title() << ", Topic: " << topic << ";" << endl;}

	// what if I try calling this method with a pointer/reference of type Book? Will it work?
	void intro(){
		cout << "Hi, I am a CSBook" << endl;
	}
};


class Comic : public Book{
	string hero;

	protected:
	string get_hero(){
		return this->hero;
	}

	public:
	Comic(string title, string hero):Book(title),hero(hero){}
	void info(){cout << "Title: " << get_title() << ", Hero: " << hero << ";" <<  endl;}

};
