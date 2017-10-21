//--------------------------------------------------------------------
//
//  Laboratory 4                                         ordlist.cpp
//
//  Array implementation of the Ordered List ADT
//
//--------------------------------------------------------------------

#ifndef ORDEREDLIST_CPP
#define ORDEREDLIST_CPP

using namespace std;

#include "OrderedList.h"

//--------------------------------------------------------------------
template < typename DataType, typename KeyType >
OrderedList<DataType,KeyType>:: OrderedList ( int maxNumber )

// Creates an empty list by calling the List ADT constructor.
{

}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void OrderedList<DataType,KeyType>:: insert ( const DataType &newDataItem ) throw ( logic_error )

// Inserts newDataItem in its appropriate location within an ordered
// list. If a data item with the same key as newData already
// exists in the list, then updates that data item's data with
// newData's data. Moves the cursor to newData.

{
    
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
bool OrderedList<DataType,KeyType>:: retrieve ( const KeyType& searchKey, DataType &searchDataItem )

// Searches a list for the data item with key searchKey. If the
// data item is found, then moves the cursor to the data item,
// copies the data item to searchDataItem, and returns true.
// Otherwise, returns false without moving the cursor and with
// searchDataItems undefined.

{
    return false;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void OrderedList<DataType,KeyType>:: replace ( const DataType &newDataItem )
    throw ( logic_error )

// Replaces the data item marked by the cursor with newData and
// moves the cursor to newData.

{
   
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void OrderedList<DataType,KeyType>:: showStructure () const

// Outputs the keys of the data items in a list. If the list is
// empty, outputs "Empty list". This operation is intended for
// testing and debugging purposes only.

{
    
}

//--------------------------------------------------------------------
//
//  Facilitator function
//

template < typename DataType, typename KeyType >
bool OrderedList<DataType,KeyType>:: binarySearch ( KeyType searchKey, int &index )

// Binary search routine. Searches a list for the data item with
// key searchKey. If the data item is found, then returns true with
// index returning the array index of the entry containing searchKey.
// Otherwise, returns false with index returning the array index of the
// entry containing the largest key that is smaller than searchKey
// (or -1 if there is no such key).

{
    return false;
}


template < typename DataType, typename KeyType >
void OrderedList<DataType,KeyType>:: merge ( const OrderedList<DataType,KeyType>& fromL ) throw ( logic_error )

// Merges the data items in list fromL into a list. Assumes that
// none of the data items in fromL occur in L already. The merge
// is done in a single pass through both lists.

{
   
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
bool OrderedList<DataType,KeyType>:: isSubset ( const OrderedList<DataType,KeyType> &subList )

// Returns true if every key in list subList also occurs in a list --
// that is, if the keys in subList are a subset of the keys in the list.
// Otherwise, returns false.

{
   return false;
}

#endif // #IFNDEF ORDEREDLIST_CPP
