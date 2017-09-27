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
#include"SLList.h"
#include<iostream>
using namespace std;


// Modified 9/22/2017 @ 10:37
int main()
{
	SLList Alst;
	Alst.pop_front();// Should print an error and return
	cout << "Alst="; Alst.print(0);
	for (int i = 0; i < 5; i++) {
		Alst.push_back(i);
	}
	for (int i = 0; i < 5; i++) {
		cout << Alst.front() << endl;
		Alst.pop_front();
	}
	for (int i = 10; i < 15; i++) {
		Alst.push_back(i);
	}
	Alst.print(0);
	SLList Blst(Alst);//calls the copy constructor
	cout << "Alst="; Alst.print(0);
	cout << "Blst(3)=";
	Blst.print(3);
	int sum = 0;
	int size = Blst.size();
	cout << "Size of Blst is " << size << endl;
	while (!Blst.empty()) {
		sum += Blst.front();
		Blst.pop_front();
	}
	cout << "Emptied Blst to obtain sum=" << sum << endl;
	SLList Clst(Alst), Dlst;// checks copy constructor and default constructor.
	Dlst.print(0);
	for (int i = 1; i < 20; i++) {
		Dlst.push_back(i * 2);
	}
	cout << Dlst << endl;
	Dlst.push_front(100);
	cout << Clst << endl;
	Alst = Dlst;// Assign D to A
	cout << Alst << endl;
	cout << "Done" << endl;
}
