```cpp
//*****************************************************************************
//					Project #3 Binary Search Tree
//					Name: David McGinn
//					Advanced Algorithms Date: 10/11/17
//*****************************************************************************
//	This program implements a BST with a vector containing the values of all
//	nodes in the tree to allow for random deletion. The effects of deletion
//	on the IPL of the BST are analyzed by main()
//*****************************************************************************

#include<iostream>
#include "BST.h"


using namespace std;


void asymetrical(int tsize);
void alternating(int tsize);

//*****************************************************************************
//	I have written the entire program as turned in and have not copied this code,
//		or parts of this code from the internet or another student.
//
//
//								Signature:_______________________________
//*****************************************************************************
int main() 
{		
	int treesize = 256;
	asymetrical(treesize);
	alternating(treesize);

	treesize = 128;
	cout << "\nBEGIN 128" << endl;
	asymetrical(treesize);
	alternating(treesize);

	return 0;
}


//*****************************************************************************
//					asymetrical()
//					Parameters: none
//					Complexity: O(n^2)
//	Method cals BST::RandDelInsPair() INSDELPAIRS times.
//	Uses Pdelete every time
//*****************************************************************************
void asymetrical(int tsize)
{
	//Predecessor Delete only
	BST t(tsize);//create an empty tree with _size=0
	int iterations = 100;
	cout << "Data for predecessor delete only " << endl;
	vector<long long>iplData(40, 0);// 40 sample ipl values
	cout << "--------------------------------------------------" << endl;
	for (int ct = 0; ct < iterations; ct++) {//collect data 100 times to average
		if (ct % 2 == 0)cout << ".";// A nice trick to see your program running
		BST t(tsize);//create an random tree with tsize nodes
		for (int i = 0; i < INSDELPAIRS; i++) {// INSDELPAIRS is 100,000
			if (i % 2500 == 0)iplData[i / 2500] += t.IPL();
			t.RandDelInsPair(1);//Im doing a Pdelete every time here
		}
		// t gets destroyed here when it goes out of scope
	}
	cout << endl;
	for (int i = 0; i < 40; i++)// print out the averaged values
		cout << iplData[i] / iterations << endl;
}


//*****************************************************************************
//					alternating()
//					Parameters: none
//					Complexity: O(n^2)
//	Method cals BST::RandDelInsPair() INSDELPAIRS times.
//	alternates between Pdelete and Sdelete each time BST::RandDelInsPair()
//	is called
//*****************************************************************************
void alternating(int tsize)
{
	//Predecessor Delete
	BST t(tsize);//create an empty tree with _size=0
	int iterations = 100;
	cout << "Data for alternating delete only " << endl;
	vector<long long>iplData(40, 0);// 40 sample ipl values
	cout << "--------------------------------------------------" << endl;
	for (int ct = 0; ct < iterations; ct++) {//collect data 100 times to average
		if (ct % 2 == 0)cout << ".";// A nice trick to see your program running
		BST t(tsize);//create an random tree with tsize nodes
		for (int i = 0; i < INSDELPAIRS; i++) {// INSDELPAIRS is 100,000
			if (i % 2500 == 0)iplData[i / 2500] += t.IPL();
			t.RandDelInsPair(i%2);
		}
		// t gets destroyed here when it goes out of scope
	}
	cout << endl;
	for (int i = 0; i < 40; i++)// print out the averaged values
		cout << iplData[i] / iterations << endl;
}
```
