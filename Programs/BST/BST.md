```cpp
//*****************************************************************************
//					Project #3 Binary Search Tree
//					Name: David McGinn
//					Advanced Algorithms Date: 10/11/17
//*****************************************************************************
//	I'll actually write this later
//*****************************************************************************
#include "BST.h"
#include <vector>
#include<iostream>
#include<ctime>
using namespace std;


//*****************************************************************************
//					BST::BST()
//					Parameters: an int to represent the number of random
//								numbers to put into the BST
//					Complexity: O(n)
//	Constructor will insert n random intergers into the BST
//*****************************************************************************
BST::BST(int n)
{
	int x;
	_root = nullptr;
	_size = 0;
	srand(time(nullptr));

	for (int i = 0; i < n; i++)
	{
		x = rand() % 256 + 1;
		insert(_root, x);
		cout << x << endl;
	}
}

//*****************************************************************************
//					BST:: insert()
//					Parameters: pointer to a tree node, and an int to insert
//					Complexity: O(n)
//	Takes a single value to insert into the BST, Complextiy is O(n) in the
//	case because the tree could be entirely unbalanced
//*****************************************************************************
void BST::insert(pTreeNode & tree, int x)
{
	//checks to see if the tree is empty
	if (tree == nullptr)
		tree = new treeNode(x);
	else
		if (x < tree->_key)
			insert(tree->_left, x);
		else
			insert(tree->_right, x);
	//once a value has been inserted
	//increase _size
	_size++;
	//add x to the vector
	valueList.push_back(x);

}
//*****************************************************************************
//					BST:: inorder()
//					Parameters: pTreeNode for the BST
//					Complexity O(n)
//	Auxilliary function for printing the contents of the BST recursively
//*****************************************************************************
void BST::inorder(pTreeNode tree)
{
	if (tree->_left != nullptr)
		inorder(tree->_left);

	cout << tree->_key << " ";
	
	if (tree->_right != nullptr)
		inorder(tree->_right);
}

//*****************************************************************************
//					BST:: sdeleteAux()
//					Parameters: pTreeNode to the tree and an int to delete
//					Complexity: O(n)
//	Auxilliary function called by pDelete
//	Deletes a single int, x from the tree
//	May run n times if the tree is entirely unbalanced and the last node needs
//	to be deleted
//*****************************************************************************
void BST::SdeleteAux(pTreeNode & tree, int x)
{
	if (tree != nullptr)
	{
		treeNode * tmp;
		treeNode * pred;
		
		if (x < tree->_key)
			SdeleteAux(tree->_left, x);
		else if (x > tree->_key)
			SdeleteAux(tree->_right, x);
		else
		{
			//node has no children
			if (tree->_left == nullptr && tree->_right == nullptr)
			{
				delete tree;
				tree = nullptr;
				return;
			}
			//node has one child
			if (tree->_left == nullptr)
			{
				tmp = tree->_right;
				delete tree;
				tree = tmp;
			}
			else if (tree->_right == nullptr)
			{
				tmp = tree->_left;
				delete tree;
				tree = tmp;
			}
			//node has two children
			else
			{
				//right
				tmp = tree->_right;
				//all the way left
				while (tmp->_left != nullptr)
				{
					pred = tmp;
					tmp = tmp->_left;
				}
				//copy value over tree
				tree->_key = tmp->_key;

				if (tree->_right == tmp)
					tree->_right = tmp->_right;
				else
					pred->_left = tmp->_right;
				delete tmp;
			}
		}
		_size--;
	}
}

//*****************************************************************************
//					BST:: DestroyTree()
//					Paprameters: pTreeNode to the BST
//					Complexity: O(n)
//	Auxilliary function for deleting every single node in the tree
//called by the constructor
//*****************************************************************************
void BST::DestroyTree(pTreeNode tree)
{
	if (tree != nullptr)
	{
		DestroyTree(tree->_left);
		DestroyTree(tree->_right);
		delete tree;
		tree = nullptr;
	}
}

//*****************************************************************************
//					BST:: Insert()
//					Parameters: x: a single value to be inserted
//					Complexity: O(1)
//	The first of the public functions, accepts a single value to insert
//	calls the insert() auxilliary function
//*****************************************************************************
void BST::Insert(int x)
{
	insert(_root, x);
}

//*****************************************************************************
//					BST:: Inorder()
//					Parameters: none
//					Complexity: O(1)
//	public function to print out the contents of the BST in order.
//	Calls the private inorder() function
//*****************************************************************************
void BST::Inorder()
{
	inorder(_root);
}

//*****************************************************************************
//					BST:: Sdelete()
//					Parameters: x: a single value to delete from the tree
//					Complexity: O(1)
//	public function, accepts a value, x, to be deleted, calls SdeleteAux()
//*****************************************************************************
void BST::Sdelete(int x)
{
	SdeleteAux(_root, x);
}

//*****************************************************************************
//					BST:: ~BST()
//					Parameters: none
//					Complexity: O(1)
//	destructor, calls the DestroyTree() auxilliary function
//*****************************************************************************
BST::~BST()
{
	DestroyTree(_root);
}

```
