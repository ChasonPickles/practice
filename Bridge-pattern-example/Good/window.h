#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

class pimpl; // "look ma! no compilation dependancy!"

class Window {
	
	pimpl * fields; // MMMMMmmmmmMmmmmMM THAT PORTABILITY 
					// once again all the magic is in the window.h file

	public:
	
	// bear with me, but imagine this is our general interface, where our client will interact with our stuff

	Window ();
	void display (std::string);

	~Window ();
};

#endif
