#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

class Window {

	// IRL this is an implementation detail, the client does not need to know that we will somehow use a 
	// standard output stream

	// if we decide to move over to ncurses, and remove this part, the client will need to recompile
	// needlessly

	// seriously! Imagine there are like a 100 params and like 1000s of lines of code using this header
	std::ostream & out;

	public:
	
	// bear with me, but imagine this is our general interface, where our client will interact with our stuff

	Window ();
	void display (std::string);
};

#endif
