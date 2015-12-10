#include "subject.h"
#include "observer.h"

void Subject::update_listener (){
	if (playlist.size() == 0){
		cout << "We're all out of songs!! " << endl;
		return;
	}
	Song s = {name, playlist.at(0)};
	
	cout << "You want me to update all my dudes" << endl;

	playlist.erase(playlist.begin());

	for (vector<Observer *>::iterator it = listeners.begin(); it != listeners.end(); it++){
		(*it)->notify(s);
	}			
}
