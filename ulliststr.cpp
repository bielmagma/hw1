#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

/**
	* Adds a new value to the back of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::push_back(const std::string& val){
	
	// If it is an empty list.
	if(head_ == 0 && tail_ == 0){
		size_ = 1;

		Item *temp = new Item();
		// cout << "hey1" << endl;
		temp->first = 0;
		temp->last = 1;
		// cout << temp->first << endl;
		// cout << temp->last << endl;
		// cout << val << endl;
		temp->prev = nullptr;
		temp->next = nullptr;

		temp->val[temp->first] = val;
		// cout << "hey2" << endl;
		
		head_ = temp;
		head_->next = tail_; 
		tail_ = temp;
		tail_->prev = head_;

		return;
	}

	// If the list is not empty.
	if(tail_->last != 10){
		
		tail_->val[tail_->last] = val;
		tail_->last++;

	 } else{
		 	Item *temp = new Item();
			Item *temp2 = tail_;

			temp->first = 0;
			temp->last = 1;
			tail_ = temp;

			tail_->prev = temp2;
			temp2->next = tail_;
			tail_->next = NULL;

			tail_->val[tail_->first] = val;

			// delete temp;
	}

	size_++;
	
}

/**
	* Removes a value from the back of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::pop_back(){
	// If the list is empty.

	if(head_ == 0 && tail_ == 0){

		return;
	}

	
	// If there is only 1 number in the list
	if(head_ == tail_ && size_ == 1){

		delete head_->next;
		delete tail_->prev;

		head_ = 0;
		tail_ = 0;
		size_--;

		
		return;
	}

	// If there is more than 1 space in the list
	if((tail_->last - tail_->first) > 1){

		tail_->last--;

	} else{
		
		Item *temp = tail_;
		tail_ = temp->prev;
		tail_->next = temp->next;	
		delete temp;

	}
	size_--;
}

/**
	* Adds a new value to the front of the list.
	* If there is room before the 'first' value in
	* the head node add it there, otherwise, 
	* allocate a new head node.
	*   - MUST RUN in O(1)
	*/
void ULListStr::push_front(const std::string& val){

	// If it is an empty list.
	if(head_ == 0 && tail_ == 0){

		size_ = 1;

		Item *temp = new Item();
		// cout << "hey1" << endl;
		temp->first = 9;
		temp->last = 10;
		// cout << temp->first << endl;
		// cout << temp->last << endl;
		// cout << val << endl;

		temp->prev = nullptr;
		temp->next = nullptr;

		temp->val[temp->first] = val;
		// cout << "hey2" << endl;
		
		head_ = temp;
		head_->next = tail_;
		tail_ = temp;
		tail_->prev = head_;
		// cout << temp->val[temp->first] << endl;

		return;
	}
	// If the list is not empty.
	if(head_->first != 0){	
		head_->first--;
		head_->val[head_->first] = val;
	 } else{
		 	Item *temp = new Item();
			Item *temp2 = head_;

			temp->first = 9;
			temp->last = 10;

			head_ = temp;

			head_->next = temp2;
			head_->prev = NULL;

			temp2->prev = head_;

			head_->val[head_->first] = val;
	}

	size_++;
}

/**
	* Removes a value from the front of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::pop_front(){
	// Empty list.
	if(head_ == 0 && tail_ == 0){

		return;
	}

	// Only 1 item.
	if(head_ == tail_ && size_ == 1){

		delete head_->next;
		delete tail_->prev;

		head_ = 0;
		tail_ = 0;
		size_--;

		return;
	}

	// If there is more than 1 space in the list.
	if((head_->last - head_->first) > 1){

		head_->first++;

	} else{
		
		Item *temp = head_;
		head_ = temp->next;
		head_->prev = temp->prev;	
		delete temp;

	}
	
	size_--;

}

/**
	* Returns a const reference to the back element
	*   - MUST RUN in O(1)
	*/
std::string const & ULListStr::back() const{

	return tail_->val[tail_->last-1];

}

/**
	* Returns a const reference to the front element
	*   - MUST RUN in O(1)
	*/
std::string const & ULListStr::front() const{

	return head_->val[head_->first];

}

/** 
	* Returns a pointer to the item at index, loc,
	*  if loc is valid and NULL otherwise
	*   - MUST RUN in O(n) 
	*/
std::string* ULListStr::getValAtLoc(size_t loc) const{

	if((head_ == 0 && tail_ == 0) || loc < 0 || loc >= size_){
		// cout << head_ << endl;

		return NULL;
	}

	size_t diff = head_->last - head_->first;
	Item *temp = head_;
	while(true){
		
		diff = temp->last - temp->first;

		if(diff > loc){

			break;
		}

		loc = loc - diff;
		temp = temp->next;
	}

	size_t final = temp->first + loc;
	
	return &(temp->val[final]);
}

