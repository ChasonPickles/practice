#include "window.h"
#include "pimpl.h"

Window::Window (){
	fields = new pimpl;

	fields->out = & std::cout;
}

void Window::display (std::string message){
	*(fields->out) << message << std::endl;
}

Window::~Window (){delete fields;}
