#include "split.h"
#include "iostream"
#include <cstddef>

using namespace std;


int main(){

	Node* five = new Node(5, nullptr);
	Node* four = new Node(4, five);
	Node* three = new Node(3, four);
	Node* two = new Node(2, three);
	Node* one = new Node(1, two);

	Node* odds = nullptr;
	Node* evens = nullptr;

	cout << "First Try:" << endl;
	split(one, odds, evens);

	cout << "Evens is: " << endl;
	while(evens != nullptr){
		cout << evens->value << endl;
		evens = evens->next; 
	}

	cout << endl << "Odds is: " << endl;
	while(odds != nullptr){
		cout << odds->value << endl;
		odds = odds->next; 
	}

	delete five;
	delete four;
	delete three;
	delete two;
	delete one;

	return 0;
}



