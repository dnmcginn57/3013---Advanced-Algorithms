```cpp
//*****************************************************************************
//		Project #5a Build a Graph Class
//		Name: David McGinn
//		Advanced Algorithms Date: 11-21-17
//*****************************************************************************
//		This is a construction of a Graph Class to use and add methods to
//		current methods of note include Graph::BFS() and Graph::DFS()
//		this submission contains (3) files:
//											Graph.h
//											-> Graph.cpp
//											Main.cpp
//*****************************************************************************

#include "Graph.h"


//*****************************************************************************
//		Graph :: Graph()
//		Parameters: int V - number of vertecies; dtype UoD - directionality
//		Complexity:
//	Recises the graph to int and sets dir type
//*****************************************************************************
Graph::Graph(int V, char UoD)
{
	if (UoD == 'U')
		dir = UNDIRECTED;
	else if (UoD == 'D')
		dir = DIRECTED;

	G.clear();
	Color.resize(V);
	vector<pair<int, int>> empty;

	for (int i = 0; i < V; i++)
	{
		G.push_back(empty);
	}
}

//*****************************************************************************
//		Graph :: AddEdges()
//		Parameters: int from - edge starting point; int to - edge endpoint
//					int wt - edge weight;
//		Complexity: O(1)
//	Creates an edge between two vertecies, loads both edges if dir = UNDIRECTED
//*****************************************************************************
void Graph::AddEdge(int from, int to, int wt)
{
	G[from].push_back(pair<int, int> (to, wt));
	if (dir == UNDIRECTED)
		G[to].push_back(pair<int, int>(from, wt));

}

//*****************************************************************************
//		Graph :: BFS()
//		Parameters: int v - a vertex to do a BFS on
//		Complexity: O(n)
//	generates a BFS tree starting at the given vertex. BFS is O(V+E)
//*****************************************************************************
vector<int> Graph::BFS(int v)
{
	int u;
	queue<int> Q;

	for (int i = 0; i < Color.size(); i++)
	{
		Color[i] = WHITE;
	}
	vector<int> Parent(G.size(), - 1);

	Q.push(v);
	
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();

		for (auto p : G[u])
		{
			if (Color[p.first] == WHITE)
			{
				Color[p.first] = GREY;
				Parent[p.first] = u;
				Q.push(p.first);
			}
		}
		Color[u] = BLACK;
	}
	return Parent;
}

//*****************************************************************************
//		Graph::DFS()
//		Parameters: int v - either a source vertex or -1. the latter generates
//			an entire forrest of trees
//		Complexity: O(n log n)
//	generates either a DFS tree or a forrest of DFS trees depending on user
//	input. calls Graph::DFS_Visit()
//*****************************************************************************
vector<int> Graph::DFS(int v)
{
	//color all vertecies white
	for(int i = 0; i < Color.size(); i++)
	{
		Color[i] = WHITE;
	}
	
	vector<int> Parent(G.size(), - 1);

	if (v == -1)
	{
		for(int u = 0; u < G.size(); u++)
			if (Color[u] == WHITE)
			{
				DFS_Visit(u,Parent);
			}

		return Parent;
	}
	else
	{
		DFS_Visit(v, Parent);
	}

}

//*****************************************************************************
//		Graph::DFS_Visit()
//		Parameters: int u - a source node; vector<int> parent - the parent
//														vector
//		Complexity: O(n log n)
//	recursively visits deeper nodes in the tree, adding nodes to the parent
//	vector if they are found to have children. denoted by connections to white
//	nodes
//*****************************************************************************
void Graph::DFS_Visit(int u, vector<int>& parent)
{

	Color[u] = GREY;
	for (auto p : G[u])
	{
		if (Color[p.first] == WHITE)
		{
			parent[p.first] = u;
			DFS_Visit(p.first, parent);
		}
	}
	Color[u] = BLACK;
}

Graph::~Graph()
{
}

```
