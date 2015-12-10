#ifndef SUBJECT_H
#define SUBJECT_H

#include "song.h"

#include <vector>
#include <iostream>
using namespace std;

class Observer;

class Subject {

	vector <string> playlist;	
	vector<Observer *> listeners;	
	string name;

	public:
	void register_listener (Observer * o){
		listeners.push_back(o);
	}


	Subject (string stationName) : name(stationName){}

	void addSongs(vector<string> & newPlaylist){
		playlist = newPlaylist;
	}

	void update_listener ();

	
};

#endif

