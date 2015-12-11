#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class timelog {

	// this is really a hack to manage the case that we don't have an object :(
	static timelog * instance; // the one instance of the timelog that we will acually always share

	vector<string> logbook;
	
	// 0-parameter ctor, actually does nothing
	timelog(){
		
	}

	public:

	void printall(){
		for (vector<string>::iterator it = logbook.begin(); it != logbook.end(); it++){
			cerr << *it << endl;
		}
		cerr << "end of current log" << endl;
	}
		
	void cleanup (){
		logbook.clear();
		cerr << "The logbook has now been reset" << endl;
	}

	void add (string s){
		logbook.push_back(s);
	}

	// all the object wants is an instance of the log that it can use to interact with
	static timelog * getInstance (){
		if (instance) return instance;
		instance = new timelog;
		return instance;
	}

	static void endfile (){
		delete instance;
	}
};

timelog * timelog::instance = NULL;


void f(){
	ostringstream oss;
	oss << "The function f was executed at " << time(NULL) << endl;

	timelog * logger = timelog::getInstance();
	logger->add(oss.str());
}

void g(){
	ostringstream oss;
	oss << "The function g was executed at " << time(NULL) << endl;

	timelog * logger = timelog::getInstance();
	logger->add(oss.str());
}
void h(){
	ostringstream oss;
	oss << "The function h was executed at " << time(NULL) << endl;

	timelog * logger = timelog::getInstance();
	logger->add(oss.str());
}

int main (){
	atexit(timelog::endfile);// make sure the dynamic memory associated with any instances is managed

	f();

	g();
	
	h();

	f();

	timelog::getInstance()->printall();
}
