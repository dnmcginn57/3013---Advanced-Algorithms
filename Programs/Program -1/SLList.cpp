//*****************************************************************************
//			Project #1 SLList
//			Name: David McGinn
//			Advanced Algorithms Date: 09/27/2017
//*****************************************************************************
//	This program creates a linked list class that would not be
//	out of place in the standard template library.
//	this program consists of 2 files
//		1.) SLList.h
//		2.) SLList.cpp
//	for class this project was run using a specific main function
//*****************************************************************************

#include "SLList.h"
#include <iostream>
#include<algorithm>

using namespace std;



//*****************************************************************************
//			SLList :: SLList()
//			Parameters: None
//			Complexity: O(1)
//	Creates an instance of SLList
//*****************************************************************************
SLList::SLList()
{
	_HeaderPtr = new Node(-999);
	_LastNodePtr = _HeaderPtr;
	_HeaderPtr->_next = new Node(-999);
	_size = 0;
}

//*****************************************************************************
//			SLList :: SLList()
//			Parameters: source, An SLList to copy
//			Complexity: O(n)
//	Creates a new instance of SLList that is a deep copy of another SLList
//*****************************************************************************
SLList::SLList(const SLList& source)
{
	_HeaderPtr = new Node(-999);
	_LastNodePtr = _HeaderPtr;
	_HeaderPtr->_next = new Node(-999);
	_size = 0;

	Node* tmp = source._HeaderPtr->_next;
	while (tmp->_data != -999)
	{
		push_back(tmp->_data);
		tmp = tmp->_next;
	}
}

//*****************************************************************************
//			SLList :: push_back(int i)
//			Parameters: i, a single intake interger
//			Complexity: O(1)
//	Accepts a single interger value and adds it to the end of the SLList
//	Incriments Size
//*****************************************************************************
void SLList::push_back(int i)
{
	_LastNodePtr = _LastNodePtr->_next;
	_LastNodePtr->_data = i;
	_LastNodePtr->_next = new Node(-999);
	_size++;
}

//*****************************************************************************
//			SLList :: print(int i)
//			Parameters: i, an interger representing the number of items to
//						print
//			Complexity: O(n)
//	prints out i intergers, if I is zero the entire list is printed
//	handles values that are out of bounds by printing the entire SLList
//*****************************************************************************
void SLList::print(int i)
{
	if (!empty())
	{
		Node* tmp = _HeaderPtr->_next;
		if (i == 0 || i >= _size)
		{
			while (tmp->_data != -999)
			{
				cout << tmp->_data << " ";
				tmp = tmp->_next;

			}
			cout << endl;
		}
		else
		{
			int j = 0;
			while (j < i)
			{
				cout << tmp->_data << " ";
				tmp = tmp->_next;
				j++;
			}
			cout << endl;
		}
	}
	else
		cout << "empty" << endl;;
}

//*****************************************************************************
//			SLList :: push_front(int i)
//			Parameters: i, a single intake interger
//			Complexity: O(1)
//	Adds a single interger, i, to the front of the list
//*****************************************************************************
void SLList:: push_front(int i)
{
	if (empty())
	{
		_HeaderPtr->_next = new Node(i, _LastNodePtr ->_next);
		_LastNodePtr = _HeaderPtr->_next;
	}
	else
	{
		Node* t = _HeaderPtr;
		_HeaderPtr->_data = i;
		_HeaderPtr = new Node(-999, t);

	}
	_size++;
}

//*****************************************************************************
//			SLList :: pop_front()
//			Parameters: None
//			Complexity: O(1)
//	removes the value at the front of the list
//*****************************************************************************
void SLList::pop_front()
{
	if (empty())
	{
		cout << "Error: empty list" << endl;
	}
	else
	{
		_HeaderPtr = _HeaderPtr->_next;
		_HeaderPtr->_data = -999;
		_size--;
	}
}

//*****************************************************************************
//			SLList :: front()
//			Parameters: None
//			Complexity: O(1)
//	Return the value at the front of the list. print an error and return a -1 
//	if list is empty
//*****************************************************************************
int SLList::front()
{
	if (empty()) {
		cout << "Error: Empty List";
		return -1;
	}
	else
		return _HeaderPtr->_next->_data;
}

//*****************************************************************************
//			SLList :: empty()
//			Parameters: None
//			Complexity: O(1)
//	returns true if the list is empty
//*****************************************************************************
bool SLList::empty()
{
	if (_size == 0)
		return true;
	return false;
}

//*****************************************************************************
//			SLList :: size()
//			Parameters: None
//			Complexity: O(1)
//	returns the size of the list
//*****************************************************************************
int SLList::size()
{
	return _size;
}


//*****************************************************************************
//			SLList :: operator=()
//			Parameters: SLList
//			Complexity: O(1)
// This implements the assignment copy operator
// Allows us to do A=B in main where A and B are SLList's
// Also allows the swap(A,B);	
//*****************************************************************************
SLList & SLList::operator=(const SLList & rhs) {
	if (&rhs != this) {// if not A=A then do a copy
		SLList N = rhs;// create a copy of rhs. Uses copy constructor
		swap(*this, N);
		//Note that this new N gets destroyed on exit of this method
	}
	return *this;
}


//*****************************************************************************
//			SLList::~SLList()
//			Parameters: None
//			Complexity: O(n)
//	deletes all values in the list and causes all pointers to point to null
//*****************************************************************************
SLList::~SLList()
{
	Node*tmp = _HeaderPtr;
	while (tmp != nullptr)
	{
		_HeaderPtr = _HeaderPtr->_next;
		delete tmp;
		tmp = _HeaderPtr;
	}

	_HeaderPtr = _LastNodePtr = tmp = nullptr;
}
