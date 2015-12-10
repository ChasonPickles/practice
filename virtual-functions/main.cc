#include <iostream>
#include "books.h"

int main (){
	cout << "Lets keep track of some books here: <add, type->fields> <printall>" << endl;

	const int MAXBOOKS = 1000;

	Book * library[MAXBOOKS];
	
	for (int i = 0; i < MAXBOOKS; i++){
		library[i] = NULL;
	} 

	string s;
	while (cin >> s){
		if (s == "add"){
			cin >> s;
			int i = 0;
			while (library[i]){i++;if (i==MAXBOOKS){cerr << "MAXBOOKS=" << MAXBOOKS << endl; return 1;}}
			
			if (s == "regular"){
				cout << "Please enter a title:" << endl;
				cin >> s;
				library[i] = new Book (s);
				cout << "<Book created successfully>"<< endl;
			}else if (s == "cs"){
				cout << "Please enter a title and a topic:" << endl;
				cin >> s;
				string topic;
				cin >> topic;
				library[i] = new CSBook (s, topic);
				cout << "<Book created successfully>"<< endl;
			}else if (s == "comic"){
				cout << "Please enter a title and a hero:" << endl;
				cin >> s;
				string hero;
				cin >> hero;
				library[i] = new Comic (s, hero);
				cout << "<Book created successfully>"<< endl;
			}else{
				cout << "Invalid behaviour :(" << endl;
			}	 
		}else if (s == "printall"){
			for (int i = 0; library[i]; i++){
				library[i]->info();
			}
		}else{
			cerr << "Undefined behaviour" << endl;
		}
	}

	for (int i = 0; i < MAXBOOKS; i++){
		delete library[i];
	}
}
