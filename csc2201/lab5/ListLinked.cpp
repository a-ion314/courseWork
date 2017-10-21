//--------------------------------------------------------------------
//  Laboratory 5                                        ListLinked.cpp
//
//  
//--------------------------------------------------------------------

#ifndef LISTLINKED_CPP
#define LISTLINKED_CPP

using namespace std;

#include <iostream>			// For showStructure

#include "ListLinked.h"

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData,
				   ListNode* nextPtr)
// Creates a list node containing item elem and next pointer
// nextPtr.
    
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::List(int ignored)

// Creates an empty list. The argument is included for compatibility
// with the array implementation (maxSize specifier) and is ignored.
    
{
	ListNode(ignored, NULL);
	cursor = NULL;
	head = NULL;
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::List(const List& other)
    
// Copy constructor. Creates a list which is equivalent in content
// to the "other" list.

{
    
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)

// Overloaded assignment operator. Reinitializes the list to be 
// equivalent in content to the "other" list.

{
	ListNode temp = other->head;
	this->head = other->head;
	while (temp->next != NULL){
		this->insert(temp->dataItem);
		temp = temp->next;
	}
	this->cursor = this->head;
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::~List() 

// Destructor. Frees the memory used by a list.

{
	delete head;
	delete cursor;
	gotoBeginning();

	while (cursor != NULL){
		delete (cursor->next);
		gotoNext();
	}
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.

{
	if (isEmpty()){
		head = new ListNode(newDataItem, NULL);
	}
	else{
		
	}
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::remove() throw (logic_error) 

// Removes the item marked by the cursor from a list. Moves the
// cursor to the next item in the list. Assumes that the first list
// item "follows" the last list item.

{
	ListNode* temp;
	temp = cursor->next;

	cursor->next = NULL;
	gotoPrior();
	cursor->next = temp;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
    
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::clear() 

// Removes all the items from a list. Sets head and cursor to 0.

{
    
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::isEmpty() const 

// Returns true if a list is empty. Otherwise, returns false.

{
	if (head == NULL)
		return true;
	else return false;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::isFull() const 

// Returns true if a list is full. Otherwise, returns false.

{
	return false;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)

// If a list is not empty, then moves the cursor to the beginning of
// the list. If list is empty, throws logic error.

{
	if (!(isEmpty())){
		cursor = head;
	}
	else
		throw logic_error("List is empty");
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)

// If a list is not empty, then moves the cursor to the end of the
// list. Otherwise, throws logic_error.

{
	if (!(isEmpty())){
		while ((cursor->next) != NULL){
			cursor = cursor->next;
		}
	}
	else throw logic_error("List is empty");
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise, 
// leaves cursor unmoved and returns false.

{
	if (cursor != NULL){
		cursor = cursor->next;
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	if (cursor == head){
		return false;
	}
	else{
		ListNode* temp;
		temp = head;
		while (temp->next != cursor){
			temp = temp->next;
		}
		cursor = temp;
		return true;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)

// Returns the item marked by the cursor. Requires that list is not empty.

{
	if (!(isEmpty())){
		return cursor;
	}
	else
		throw logic_error("List is empty");
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::showStructure() const

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
    if ( isEmpty() )
    {
       cout << "Empty list" << endl;
    } 
    else
    {
	for (ListNode* temp = head; temp != 0; temp = temp->next) {
	    if (temp == cursor) {
		cout << "[";
	    }

	    // Assumes that dataItem can be printed via << because
	    // is is either primitive or operator<< is overloaded.
	    cout << temp->dataItem;	

	    if (temp == cursor) {
		cout << "]";
	    }
	    cout << " ";
	}
	cout << endl;
    }
}

//--------------------------------------------------------------------
//
//                        Programming Exercises 2 and 3
//
//--------------------------------------------------------------------

// Programming exercise 2

template < typename DataType >
void List<DataType>:: moveToBeginning() throw ( logic_error )

// Removes the item marked by the cursor from a list and
// reinserts it at the beginning of the list. Moves the cursor to the
// beginning of the list.

{
   
}

//--------------------------------------------------------------------
// Programming exercise 3

template < typename DataType >
void List<DataType>:: insertBefore ( const DataType &newDataItem )
    throw ( logic_error )

// Inserts newDataItem before the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.

{
   
}

#endif		// #ifndef LISTLINKED_CPP
