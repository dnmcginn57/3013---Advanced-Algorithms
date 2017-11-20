//*****************************************************************************
//		Project #5a Build a Graph Class
//		Name: David McGinn
//		Advanced Algorithms Date: 11-21-17
//*****************************************************************************
//		This is a construction of a Graph Class to use and add methods to
//		current methods of note include Graph::BFS() and Graph::DFS()
//		this submission contains (3) files:
//											Graph.h
//											Graph.cpp
//											-> Main.cpp
//*****************************************************************************
#include <iostream>

#include "Graph.h"
using namespace std;


//*****************************************************************************
//		I have written the entire program as turned in and have not copied
//		this code, or parts of this code from the internet or another student
//
//
//								Signature: _____________________________
//*****************************************************************************
int main()
{
	int verts, t, f;
	char type;

	cin >> type;
	cin >> verts;




	Graph testGraph(verts, type);

	vector<int> DFStree, BFStree;


	while (cin >> f)
	{
		cin >> t;
		testGraph.AddEdge(f, t, 0);


	}
	BFStree = testGraph.BFS(5);
	DFStree = testGraph.DFS(-1);

	for (auto i : BFStree)
	{
		cout << i << " ";
	}
	
	cout << endl;

	for (auto j : DFStree)
	{
		cout << j << " ";
	}


	return 0;
}
