#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include "song.h"
#include <iostream>
using namespace std;

class Subject;

class Observer {
	
	public:
	vector<string> favs;
	
	private:
	Subject * radio;
	public:

	Observer(Subject * station);
	
	void notify (Song s){
		// Song is a struct containing inforation about a song playing on the radio	
		cout << "New song from <" << s.stationName << "> called <" << s.songName << '>' << endl;

		for (vector<string>::iterator it = favs.begin(); it != favs.end(); it++){
		if (s.songName == (*it)){
			cout << "This is my favourite!" << endl;
			break;
		}
	} 
	}
};

#endif
