/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"

using namespace std;


int main(int argc, char* argv[])
{

// push_back Test Cases:

	// Test Case 1: push_back empty list.
	ULListStr case1;
	case1.push_back("1");

	cout << endl;
	cout << "push_back Test Case 1:" << endl;
	cout << case1.get(0) << endl;

	// Test Case 2: push_back non-empty list, but with space to add.
	ULListStr case2;

	case2.push_back("1");
	case2.push_back("2");

	cout << endl;
	cout << "push_back Test Case 2:" << endl;
	cout << case2.get(0) << " " << case2.get(1) << endl;

	// Test Case 3: push_back non-empty list, while creating a new Item.

	ULListStr case3;
	case3.push_back("1");
	case3.push_back("2");
	case3.push_back("3");
	case3.push_back("4");
	case3.push_back("5");
	case3.push_back("6");
	case3.push_back("7");
	case3.push_back("8");
	case3.push_back("9");
	case3.push_back("10");
	case3.push_back("11");

	cout << endl;
	cout << "push_back Test Case 3:" << endl;
	for(size_t i = 0; i < case3.size(); i++){
		cout << case3.get(i) << " ";
	}
	cout << endl;

	cout << "Size should be 11, size is " << case3.size() << endl;

// push_front Test Cases:

	// Test Case 1: push_front empty list.
	ULListStr case4;
	case4.push_front("2");

	cout << endl;
	cout << "push_front Test Case 1:" << endl;
	cout << case4.get(0) << endl;

	// Test Case 2: push_front, but there is still space to add items.

	ULListStr case5;
	case5.push_front("1");
	case5.push_front("2");
	case5.push_front("3");
	case5.push_front("4");

	cout << endl;
	cout << "push_front Test Case 2:" << endl;
	for(size_t i = 0; i < case5.size(); i++){
		cout << case5.get(i) << " ";
	}
	cout << endl;

	// Test Case 3: push_front, while adding a new item because we have already have 10 items in the array.

	ULListStr case6;
	case6.push_front("1");
	case6.push_front("2");
	case6.push_front("3");
	case6.push_front("4");
	case6.push_front("5");
	case6.push_front("6");
	case6.push_front("7");
	case6.push_front("8");
	case6.push_front("9");
	case6.push_front("10");
	case6.push_front("11");

	cout << endl;
	cout << "push_front Test Case 3:" << endl;
	for(size_t i = 0; i < case6.size(); i++){
		cout << case6.get(i) << " ";
	}
	cout << endl;
	cout << "Size should be 11, size is " << case6.size() << endl;

// push_front and push_back at the same time Test Case:

	// Test Case 1: push_back and push_front more than 10 items each to create two new nodes.

	ULListStr case7;

	case7.push_back("1");
	case7.push_front("1");
	case7.push_back("2");
	case7.push_front("2");
	case7.push_back("3");
	case7.push_front("3");
	case7.push_back("4");
	case7.push_front("4");
	case7.push_back("5");
	case7.push_front("5");
	case7.push_back("6");
	case7.push_front("6");
	case7.push_back("7");
	case7.push_front("7");
	case7.push_back("8");
	case7.push_front("8");
	case7.push_back("9");
	case7.push_front("9");
	case7.push_back("10");
	case7.push_front("10");
	case7.push_front("11");
	case7.push_back("11");
	
	cout << endl;
	cout << "push_front and push_back Test Case 1:" << endl;
	for(size_t i = 0; i < case7.size(); i++){
		cout << case7.get(i) << " ";
	}
	cout << endl;
	cout << "Size should be 22, size is " << case7.size() << endl;
	
// pop_back Test Cases:

	// Test Case 1: pop_back an empty list. (Nothing should happen)
	
	ULListStr case8;

	cout << endl;
	cout << "pop_back Test Case 1:" << endl;
	case8.pop_back();
	cout << "Size should be 0, size is " << case8.size() << endl;

	// Test Case 2: pop_back a list with only 1 value, should give you the empty list.

	ULListStr case9;

	cout << endl;
	cout << "pop_back Test Case 2:" << endl;
	case9.push_front("1");

	cout << case9.get(0) << endl;

	case9.pop_back();

	cout << "After pop_back, size should be 0, size is " << case9.size() << endl;

	// Test Case 3: pop_back a list with multiple values and multiple nodes.

	ULListStr case10;

	cout << endl;
	cout << "pop_back Test Case 3:" << endl;

	case10.push_back("12");
	case10.push_front("11");
	case10.push_back("13");
	case10.push_front("10");
	case10.push_back("14");
	case10.push_front("9");
	case10.push_back("15");
	case10.push_front("8");
	case10.push_back("16");
	case10.push_front("7");
	case10.push_back("17");
	case10.push_front("6");
	case10.push_back("18");
	case10.push_front("5");
	case10.push_back("19");
	case10.push_front("4");
	case10.push_back("20");
	case10.push_front("3");
	case10.push_back("21");
	case10.push_front("2");
	case10.push_front("1");
	case10.push_back("22");

	size_t x = case10.size();

	for(size_t i = 0; i < case10.size(); i++){
		cout << case10.get(i) << " ";
	}
	cout << endl << "popping:" << endl;

	for(size_t i = 0; i < x-1; i++){
		cout << case10.get(case10.size()-1) << endl;
		case10.pop_back();
	}

	cout << "After pop_back, size should be 1, size is " << case10.size() << endl;
	cout << "The value that remains is " << case10.get(0) << endl; 

// pop_front Test Cases:

		// Test Case 1: pop_front an empty list. (Nothing should happen)
	
	ULListStr case11;

	cout << endl;
	cout << "pop_front Test Case 1:" << endl;
	case11.pop_back();
	cout << "Size should be 0, size is " << case11.size() << endl;

	// Test Case 2: pop_front a list with only 1 value, should give you the empty list.

	ULListStr case12;

	cout << endl;
	cout << "pop_front Test Case 2:" << endl;
	case12.push_front("1");

	cout << case12.get(0) << endl;

	case12.pop_back();

	cout << "After pop_front, size should be 0, size is " << case12.size() << endl;

	// Test Case 3: pop_front a list with multiple values and multiple nodes.

	ULListStr case13;

	cout << endl;
	cout << "pop_front Test Case 3:" << endl;

	case13.push_back("12");
	case13.push_front("11");
	case13.push_back("13");
	case13.push_front("10");
	case13.push_back("14");
	case13.push_front("9");
	case13.push_back("15");
	case13.push_front("8");
	case13.push_back("16");
	case13.push_front("7");
	case13.push_back("17");
	case13.push_front("6");
	case13.push_back("18");
	case13.push_front("5");
	case13.push_back("19");
	case13.push_front("4");
	case13.push_back("20");
	case13.push_front("3");
	case13.push_back("21");
	case13.push_front("2");
	case13.push_back("22");
	case13.push_front("1");

	size_t x2 = case13.size();

	for(size_t i = 0; i < case13.size(); i++){
		cout << case13.get(i) << " ";
	}
	cout << endl << "popping:" << endl;

	for(size_t i = 0; i < x2-1; i++){
		cout << case13.get(0) << endl;
		case13.pop_front();
	}

	cout << "After pop_front, size should be 1, size is " << case13.size() << endl;
	cout << "The value that remains is " << case13.get(0) << endl;

// pop_back and pop_front Test Cases:

	// Test Case 1: using both pop_front and pop_back to get another list.

	ULListStr case14;

	case14.push_front("1");
	case14.push_front("2");
	case14.push_front("3");
	case14.push_front("4");
	case14.push_front("5");
	case14.push_front("6");
	case14.push_front("7");
	case14.push_front("8");
	case14.push_front("9");
	case14.push_front("10");
	case14.push_front("11");

	cout << endl;
	cout << "pop_front and pop_back Test Case 1:" << endl;

	cout << "Old list is : ";

	for(size_t i = 0; i < case14.size(); i++){
		cout << case14.get(i) << " ";
	}
	cout << endl;

	case14.pop_back();
	case14.pop_back();
	case14.pop_front();
	case14.pop_front();

	cout << "New list is : ";

	for(size_t i = 0; i < case14.size(); i++){
		cout << case14.get(i) << " ";
	}
	cout << endl;

// back and front Test Cases:

	// Test Case 1 and 2: get front and back values. 

	ULListStr case15;
	case15.push_front("1");
	case15.push_front("2");
	case15.push_front("3");
	case15.push_front("4");
	case15.push_back("0");

	cout << endl;
	cout << "front and back Test Case 1 and 2:" << endl << "list is: ";

	for(size_t i = 0; i < case15.size(); i++){
		cout << case15.get(i) << " ";
	}

	cout << endl << "front is " << case15.front() << endl;
	cout << "back is " << case15.back() << endl;

// getValAtLoc Test Cases:

	// Test Case 1: getting the value at that loc in a given list.

	ULListStr case16;

	case16.push_front("1");
	case16.push_front("2");
	case16.push_front("3");
	case16.push_front("4");
	case16.push_front("5");
	case16.push_front("6");
	case16.push_front("7");
	case16.push_front("8");
	case16.push_front("9");
	case16.push_front("10");
	case16.push_front("11");
	case16.push_front("12");

	cout << endl;
	cout << "getValAtLoc Test Case 1:" << endl;

	cout << "List is : ";

	for(size_t i = 0; i < case16.size(); i++){
		cout << case16.get(i) << " ";
	}
	cout << endl;

	cout << "Value at location 12 is: " << case16.get(11) << endl;

	// Test Case 2: handling invalid locations (works the same for negative values, empty lists, and out-of-bounds indexes. In this case, the indexes goes from 0-11 [12 items], but the user tries to get the 12th index, which does not exist).

// NOTE: I do not know if it necessary to consider .get() at an invalid location as a test case. In my .cpp file, I am accounting for all invalid locations, but as testing this would cause the program to throw invalid_argument("bad location") from the get(size_t loc) function, I wrote one appropriate test case for each scenario, but left it as a comment below.

	ULListStr case17;

	case17.push_front("1");
	case17.push_front("2");
	case17.push_front("3");
	case17.push_front("4");
	case17.push_front("5");
	case17.push_front("6");
	case17.push_front("7");
	case17.push_front("8");
	case17.push_front("9");
	case17.push_front("10");
	case17.push_front("11");
	case17.push_front("12");

	cout << endl;
	cout << "getValAtLoc Test Case 2:" << endl;

	cout << "List is : ";

	for(size_t i = 0; i < case17.size(); i++){
		cout << case17.get(i) << " ";
	}
	cout << endl;

	// cout << "Value at location 12 is: " << case17.get(12) << endl;
	// Correct would be case17.get(11)

	// cout << case17.get(-1) << endl;
	
	// ULListStr case18;
	// cout << case18.get(0);

	
  return 0;
}
