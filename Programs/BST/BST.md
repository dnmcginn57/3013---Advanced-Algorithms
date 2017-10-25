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
	_size = n;
	srand(time(nullptr));

	for (int i = 0; i < n; i++)
	{
		x = rand() % VALUESIZE;
		insert(_root, x);
		valueList.push_back(x);
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
//					BST:: SdeleteAux()
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
		treeNode * succ;
		
		//Locate the node
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
				//splice in the right node
				tmp = tree->_right;
				delete tree;
				tree = tmp;
			}
			else if (tree->_right == nullptr)
			{
				//splice in the left node
				tmp = tree->_left;
				delete tree;
				tree = tmp;
			}

			//node has two children
			else
			{
				//Locate a successor
				//right
				tmp = tree->_right;
				//all the way left
				while (tmp->_left != nullptr)
				{
					succ = tmp;
					tmp = tmp->_left;
				}
				//copy value over tree
				tree->_key = tmp->_key;

				if (tree->_right == tmp)
					tree->_right = tmp->_right;
				else
					succ->_left = tmp->_right;
				delete tmp;
			}
		}
	}
}

//*****************************************************************************
//					BST:: PdeleteAux()
//					Parameters: pointer to root of the tree, value to delete
//					Complexity: O(n)
//	Auxilliary function called by Pdelete(). Selects a value to delete,
//	replaces with a predecessor. could be O(n) if a tree is unbalanced
//*****************************************************************************
void BST::PdeleteAux(pTreeNode & tree, int x)
{
	if (tree != nullptr)
	{
		treeNode * tmp;
		treeNode * pred;

		//Locate the node
		if (x < tree->_key)
			PdeleteAux(tree->_left, x);
		else if (x > tree->_key)
			PdeleteAux(tree->_right, x);
		else
		{
			//childless node
			if (tree->_left == nullptr && tree->_right == nullptr)
			{
				delete tree;
				tree = nullptr;
				return;
			}

			//node has one child
			if (tree->_left == nullptr)
			{
				//splice in right
				tmp = tree->_right;
				delete tree;
				tree = tmp;
			}
			else if (tree->_right == nullptr)
			{
				//splice in left
				tmp = tree->_left;
				delete tree;
				tree = tmp;

			}

			//node has two children
			else
			{
				//locate a pred
				//go LEFT
				tmp = tree->_left;
				//go all the way RIGHT
				while (tmp->_right != nullptr)
				{
					pred = tmp;
					tmp = tmp->_right;
				}
				//copy pred to tree
				tree->_key = tmp->_key;
				if (tree->_left == tmp)
					tree->_left = tmp->_left;
				else
					pred->_right = tmp->_left;
				delete tmp;
			}
		}
	}
}
//*****************************************************************************
//					BST::iplAux()
//					Parameters: pTreeNode to the tree, int x which is added to
//															recursively
//					Complexity: O(n)
//	Auxilliary program called by IPL(), calculates the sum total of depths
//	of every node in the tree
//*****************************************************************************
int BST :: iplAux(pTreeNode & tree, int x)
{
	if (tree == nullptr)
		return 0;
	return(x + iplAux(tree->_right, x + 1) + iplAux(tree->_left, x + 1));
}

//*****************************************************************************
//					BST:: DestroyTree()
//					Parameters: pTreeNode to the BST
//					Complexity: O(n)
//	Auxilliary function for deleting every single node in the tree
//	called by the constructor
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
	valueList.clear();
	_size = 0;
}

//*****************************************************************************
//					BST:: Insert()
//					Parameters: x: a single value to be inserted
//					Complexity: O(n)
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
//					Complexity: O(n)
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
//					Complexity: O(n)
//	public function, accepts a value, x, to be deleted, calls SdeleteAux()
//*****************************************************************************
void BST::Sdelete(int x)
{
	SdeleteAux(_root, x);
}

//*****************************************************************************
//					BST:: Pdelete()
//					Parameters: x: a single value to delete from the tree
//					Complexity: O(n)
//	public function, accepts a value, x, to be deleted, calls PdeleteAux()
//*****************************************************************************
void BST::Pdelete(int x)
{
	PdeleteAux(_root, x);
}

//*****************************************************************************
//					BST:: RandDelInsPair
//					Parameters: a 1 or a 0 to indicate delete type
//					Complexity: O(n)
//	Randomly selects value in vector, deletes it from tree and
//  inserts a new random value into vector and tree.
//	Uses either Sdelete(1) or Pdelete(0)
//*****************************************************************************
void BST::RandDelInsPair(int dType)
{
	int x,y;
	x =rand() % _size;
	if (dType == 0)
		Sdelete(valueList[x]);
	else
		Pdelete(valueList[x]);

	y = rand() % VALUESIZE;

	Insert(y);
	valueList[x] = y;

}

//*****************************************************************************
//					BST:: IPL()
//					Parameters: None
//					Complexity: O(n)
//	Calls iplAux and returns the the ipl of the tree
//*****************************************************************************
int BST::IPL()
{
	return iplAux(_root, 0);
}

//*****************************************************************************
//					BST:: ~BST()
//					Parameters: none
//					Complexity: O(n)
//	destructor, calls the DestroyTree() auxilliary function
//*****************************************************************************
BST::~BST()
{
	DestroyTree(_root);
}

```
