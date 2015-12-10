
#include <iostream>
using namespace std;
/*
class Car {
	int passengers;
	public:
	explicit Car (int passengers) : passengers (passengers){}
	Car & operator= (const Car & other){
		cout << endl << "Assignment in progress" << endl;
		passengers = other.passengers;
		return *this;
	}
	int getPassengers (){
		return passengers;
	}
};*/

template <typename T> class Node {
	T data;
	Node<T> * next;
	
	public:

	Node (T data, Node * next): data(data), next(next){}
	
	~Node (){
		delete next;
	}

	Node (const Node<T> & other){
		if (other.next == NULL){
			data = other.data;
			next = other.next;
		}else{
			data = other.data;
			next = new Node<T> (*(other.next));
		}
	}

	Node<T> & operator=(const Node<T> & other){
		if (this == &other){ return *this;}
		
		// copy the rest of the list first
		Node<T> * temp;
		if (other.next){
			temp = new Node<T> (*other.next);
		}else{
			temp = NULL;
		}

		data = other.data;
		delete next;
		next = temp; // swap the list over
		
		return * this;
	}

	template <typename U>
	friend ostream & operator<< (ostream & out, const Node<U> & lst);
	
};

/* recursive
ostream & operator<< (ostream & out, const Node & lst){
	if (lst.next == NULL){
		out << lst.data;
	}else{
		out << lst.data << ", ";
		out << *(lst.next);
	}
	return out;
}*/
template <typename T> ostream & operator<< (ostream & out, const Node<T> & lst){
	out << "[ ";
	out << lst.data;	

	Node<T> * cur = lst.next;
	
	while (cur){
		out << ", ";
		out << cur->data;
		cur = cur->next;
	}
	out << " ]";
}

int main (){
	Node<int> * lst = new Node<int> (1, new Node<int> (2, new Node<int> (3, NULL)));

	Node<int> * tmp = new Node<int> (*lst);
	

	Node<int> a(2, NULL);
	//a = *lst;

	cout << *lst << endl;
	cout << *tmp << endl;
	cout << a << endl;

	string w = "hello";
	string v = "world";

	Node<std::string> *  lst2 = new Node<std::string> (w, new Node<std::string> (v, NULL));
	
	cout << *lst2 << endl;
	
	delete tmp;
	delete lst;	
}
