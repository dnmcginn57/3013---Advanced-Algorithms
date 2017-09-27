```CPP
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
#pragma once
#include "SLList.h"
#include <iostream>
#include<algorithm>
using namespace std;
class SLList
{
protected:
	struct Node {
		int _data;
		Node* _next;

		Node(int num, Node* n = nullptr)
		{
			_data = num;
			_next = n;
		}
	};
private:
	Node* _HeaderPtr;
	Node* _LastNodePtr;
	int _size;
	
public:
	SLList();
	SLList(const SLList& source);
	void push_back(int);
	void print(int);
	void push_front(int);
	void pop_front();
	int front();
	bool empty();
	int size();
	SLList &operator=(const SLList & rhs);
	
	//This is the overloaded output >> operater  allow   cout<< list <<endl;
	 //Place this in your .h file for SLList  only 
	friend ostream &operator<<(ostream &output, const SLList &L) {
		Node * t = L._HeaderPtr->_next;
		int ct = min(L._size, 10);
		//List size = 21 : 2, 5, 4, 76, 1, 9, 7, 12, 54, 88, ... 23
		output << "List size = " << L._size << " : ";
		if (L._size > 10) {
			for (size_t i = 0; i < 10; i++)
			{
				output << t->_data << ", ";// leaves a space at end.
				t = t->_next;//go to next node
			}
			cout << "... " << L._LastNodePtr->_data;
		}
		else {
			for (int i = 0; i < ct; i++)
			{
				output << t->_data << ", ";
				t = t->_next;
			}
		}
		return output;
	}

	//*****************************************************************************
	//			SLList :: swap()
	//			Parameters: 2 lists to swap
	//			Complexity: O(n)
	//	swap method provided so the overridden assignment operater doesn't
	//	infinitely recurse on itsself
	//*****************************************************************************
	friend void swap(SLList& LHS, SLList& RHS)
	{
		swap(LHS._HeaderPtr, RHS._HeaderPtr);
		swap(LHS._LastNodePtr, RHS._LastNodePtr);
		swap(LHS._size, RHS._size);
	}
	~SLList();
};
```
