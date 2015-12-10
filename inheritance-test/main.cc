#include <iostream>
using namespace std;

class person{
	public:
	virtual ~person() = 0;
};


class student : public person{
	public:
	void intro(){
		cout << "I am a student" << endl;
	}
};

int main (){
	person p; student s;

	p.intro();
	s.intro();


	cout << "A reference of the class type is now referring to the derived classs obj. Te behaviour when we call the intro() function " << endl;
	person & pr = s;

	pr.intro();
	
	cout << "Does any shaving occur because of the refernece? if yes, the next line should say person" << endl;
	s.intro();
}
