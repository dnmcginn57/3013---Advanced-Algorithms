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

#pragma once
#include<vector>
using namespace std;

#define VALUESIZE 32000
#define INSDELPAIRS 100000

class BST
{
	struct treeNode;
	typedef treeNode* pTreeNode;
	vector<int> valueList;// holds the values presently in the tree. Normally not in a tree
	int _size;//number of values in tree and in vector;
	struct treeNode {
		int _key;
		pTreeNode _left;
		pTreeNode _right;
		treeNode(int key) : _key(key), _left(nullptr), _right(nullptr) {}
	};
	pTreeNode _root;
	void insert(pTreeNode &, int);//1
	void inorder(pTreeNode tree);//2
	void SdeleteAux(pTreeNode &, int);//3
	void PdeleteAux(pTreeNode &, int);//5
	int  iplAux(pTreeNode &, int);// 7
	void DestroyTree(pTreeNode);//4
public:
	BST(int);//1, constructs tree with random nodes. It calls insert() multiple times
	~BST();// 4 ,Calls DestroyTree()
	void Insert(int value);//1, Inserts new node,adds it to the vector and increments _size
	void Inorder();//2
	void Sdelete(int);//3, successor delete from tree, does not modify size or vector
	void Pdelete(int); //5, predecessor delete from tree, does not modify size or vector // The following performs an deletion/insertion pair randomly 
					   // Randomly selects value in vector , deletes it from tree and // inserts a new random value into vector and tree. Uses either Sdelete(1) or Pdelete(0)
	void RandDelInsPair(int dType);//6
	int IPL(); //7, Calls iplAux() to return the internal path length. Will discuss in class
};

```
