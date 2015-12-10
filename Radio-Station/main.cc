#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

#include "observer.h"
#include "subject.h"

int main (){
	
	cout << "welcome to virgin radio! Type in the songs you want out listners to hear" << endl; 

	Subject virginRadio("Virgin Radio");

	Observer uday(&virginRadio);
	Observer yash(&virginRadio);
	Observer jahan(&virginRadio);

	vector<string> playlist;
	playlist.push_back("wildest-dreams");
	playlist.push_back("started-from-the-bottom");
	playlist.push_back("versace");

	
	(uday.favs).push_back("started-from-the-bottom");

	virginRadio.addSongs(playlist);

	virginRadio.update_listener();
	cout << "--------------------------------------------------------" << endl;

	virginRadio.update_listener();
	cout << "--------------------------------------------------------" << endl;

	virginRadio.update_listener();
	cout << "--------------------------------------------------------" << endl;

	virginRadio.update_listener();
	cout << "--------------------------------------------------------" << endl;

}
