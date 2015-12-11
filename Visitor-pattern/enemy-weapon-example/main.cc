#include <iostream>
using namespace std;

// this is the turtle/bullet example from the notes

class Weapon;
class Turtle;
class Bullet;
class Stick;
class Rock;

class Enemy{
	public:
		virtual void strike (Weapon & w) = 0;
};

class Weapon {
	public:
		// these are the two enemy type I may need to hit with my weaponz
		virtual void strike (Turtle &) = 0;
		virtual void strike (Bullet &) = 0;
};

class Turtle : public Enemy{
	public:
		void strike (Weapon & w){
			w.strike (*this); // the type is unambigous now!
		}
};

class Bullet : public Enemy{
	public:
		void strike (Weapon & w){
			w.strike (*this); // the type is unambigous now!
		}
};

class Stick : public Weapon{
	public:
		void strike (Turtle & t){
			cout << "I am a stick and I know that I am dealing damage to some turtle" << endl;
		}
		void strike (Bullet & b){	
			cout << "I am a stick and I know that I am dealing damage to some bullet" << endl;
		}
};

class Rock : public Weapon{
	public:
		void strike (Turtle & t){
			cout << "I am a rock and I know that I am dealing damage to some turtle" << endl;
		}
		void strike (Bullet & b){	
			cout << "I am a rock and I know that I am dealing damage to some bullet" << endl;
		}
};

int main(){
	Enemy * e = new Turtle;
	Weapon * w = new Stick; // notice, none of my virtuals actually know the tue type of the underlying obj is!

	e->strike(*w);
	// tell enenemy that he is being struck by some weapon. 
	// strike will go all the way down to the concrete type, so we know what type of enemy is
	// the enemy will return a disambiguated ptr to itself to a function of the Weapon that will also drive
	//	all the way down to the base type, thus guaranteeng that even though we make our calls through 
	//	base class (ambiguous) ptrs, we still figure out the true type of our underlying obj.

	// notice that strike for example on the enemy side is EXACTLY the same as dealAttack that we implemented 
	// in our project. Just imagine that the e->strike(*w) was REALLY this->dealAttack(*p) where dealAttack would
	// go all the way down to the concrete class and call the takeAttack() ~ {the complement of strike in the player class}
	// and make sure we deal damage only when we know the types of both parties involved!
}
