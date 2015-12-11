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
	
		virtual Book & operator=(const Book & other){
			title = other.title;
		}
};

class CSBook : public Book{
	string topic;

	public:
		CSBook (string title, string topic) : Book (title), topic (topic) {}
		string getTopic (){
			return topic;
		}
	
		CSBook (CSBook & b) : Book (b), topic(b.topic){	cout << "Calling the CSBook cpy ctor" << endl;	}

		// what exactly happens here:
		
		// why doesn't the default/free a-op get called?

		CSBook & operator= (const Book & other){
			const CSBook & cs_other = dynamic_cast<const CSBook &>(other);
			// this will throw an exception if you don't actually have book on the RHS
			
			// DON'T TRY TO BE SO CLEVER!	
			/*Book * me = this;
			*me = other;*/
	
			Book::operator=(other);

			// same as calling the assignment op explicitly
			topic = cs_other.topic;
		}	
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
