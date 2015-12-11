#include "window.h"

Window::Window () : out (std::cout){}

void Window::display (std::string message){
	out << message << std::endl;
}
