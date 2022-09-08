/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include "iostream"

using namespace std;

/* Add a prototype for a helper function here if you need */

Node* evenOdd(Node*& in, Node*& odds, Node*& evens);
// void odd(Node*& in, Node*& odds);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  Node* temp = in;

  evenOdd(temp, odds, evens);

  in = temp;
}

/* If you needed a helper function, write it here */

Node* evenOdd(Node*& temp, Node*& odds, Node*& evens){

  if(temp == nullptr){
    
    odds = nullptr;
    evens = nullptr;
    return nullptr;

  } else if(temp->value % 2 == 0){

    evens = temp;
    return evenOdd(temp->next, odds, temp->next);

  } else{

    odds = temp;
    return evenOdd(temp->next, temp->next, evens);

  }
}

// WRITE YOUR CODE HERE