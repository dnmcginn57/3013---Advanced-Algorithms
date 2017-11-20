```cpp
//*****************************************************************************
//		Project #5a Build a Graph Class
//		Name: David McGinn
//		Advanced Algorithms Date: 11-21-17
//*****************************************************************************
//		This is a construction of a Graph Class to use and add methods to
//		current methods of note include Graph::BFS() and Graph::DFS()
//		this submission contains (3) files:
//											-> Graph.h
//											Graph.cpp
//											Main.cpp
//*****************************************************************************

#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include<queue>
#include <iostream>

using namespace std;

enum dtype { DIRECTED, UNDIRECTED };
enum color { WHITE, BLACK, GREY };

class Graph
{
	// The wt value will be used in a later algorithm.
	vector<vector<pair<int, int>>> G; //Pair < node#, wt >
	vector<color> Color;// Not really required but will reduce parameter passing.
	dtype dir;
	void DFS_Visit(int, vector<int>&);
public:
	Graph(int, char); // resizes G to int and sets dir to type.
	~Graph();
	// NOTE: AddEdge loads both edges if dir = UNDIRECTED
	void AddEdge(int from, int to, int wt);
	vector<int> BFS(int);// return the parent vector
						 // (ie the BFS tree for this vertex)

	vector<int> DFS(int);// Note: if the parameter is a vertex do a single DFS 
						 // on this vertex. If the parameter is -1 do the complete
						 // DFS returning a forest of trees.
};


```
