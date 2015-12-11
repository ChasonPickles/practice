#include <iostream>
using namespace std;

class Book {
	string title;
	
	public:
		Book (string title) : title(title) {}
		string getTitle (){
			return title;
		}
		
		Book (Book & b) : title (b.title){ cout << "Book cpy ctor being called" << endl;}

};

class CSBook : public Book{
	string topic;

	public:
		CSBook (string title, string topic) : Book (title), topic (topic) {}
		string getTopic (){
			return topic;
		}
	
		CSBook (CSBook & b) : Book (b), topic(b.topic){	cout << "Calling the CSBook cpy ctor" << endl;	}
};

int main(){
	CSBook a ("AIMA", "AI");
	CSBook b ("art of prog" , "all");

	cout << "Book 1) is called " << a.getTitle() << " and is written on " << a.getTopic() << endl;
	cout << "Book 2) is called " << b.getTitle() << " and is written on " << b.getTopic() << endl;

	cout << endl;
	Book * base_a = &a;
	Book * base_b = &b;
	
	// the book assignment operator gets called and both objects are treated like books,
	// and by default behaviour this blindly copies over the fields associated only with the 
	// Book class.
	*base_b = *base_a;
	cout << endl;

	cout << "Book 1) is called " << a.getTitle() << " and is written on " << a.getTopic() << endl;
	cout << "Book 2) is called " << b.getTitle() << " and is written on " << b.getTopic() << endl;
}
