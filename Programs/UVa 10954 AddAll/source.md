```CPP
//*******************************************************************
//		Project #4 A simple priority queue
//		Name: David McGinn
//		UVa Name: SugoiDesuNe
//		Advanced Algorithms Date: 11/10/2017
//*******************************************************************
//	This program impliments a minHeap to solve UVa problem 10954
//*******************************************************************

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Heap
{
private:
	vector<int> _heap;

public:

//*******************************************************************
//		Heap :: Heap()
//		Parameters: None
//		Complexity: O(1)
//	Default constructor just pushes a dummy value into the heap
//*******************************************************************
	Heap()
	{
		_heap.push_back(-999);
	}

//*******************************************************************
//		Heap :: Heap()
//		Parameters: vector to initialize the heap with
//		Complexity: O(n log n)
//	Parameterize constructor just pushes a dummy value into the heap
//	and then uses a Build Heap algorithm on an intake vector
// this calls Heap :: Heapify() [O(log n)]
//*******************************************************************
	Heap(vector<int> intake)
	{
		_heap.push_back(-999);
		for (auto x : intake)
			_heap.push_back(x);

		for (int i = Size() / 2; i >= 1; i--)
		{
			Heapify(_heap, i);
		}

	}

//*******************************************************************
//		Heap :: Size()
//		Parameters: None
//		Complexity: O(1)
//	Returns the number of elements on the heap(not including dummy)
//*******************************************************************
	int Size()
	{
		return _heap.size()-1;
	}

//*******************************************************************
//		Heap :: Insert()
//		Parameters: int val, a value to insert
//		Complexity: O(log n)
//	pushes a value onto the end of the heap, swaps until it is
//	larger than its parent
//*******************************************************************
	void Insert(int val)
	{
		int tmp;
		int i;

		_heap.push_back(val);
		i = Size();
		//while heap[i] is less than its parent
		while (_heap[i] < _heap[i >> 1])
		{
			//swap with parent
			tmp = _heap[i];
			_heap[i] = _heap[i >> 1];
			_heap[i >> 1] = tmp;
			//move i
			i = i >> 1;
		}

	}

	//*******************************************************************
	//		Heap :: Extract()
	//		Parameters: None
	//		Complexity: O(log n)
	//	extracts the smallest(top) value. calls Heapify[O(log N)]
	//*******************************************************************
	int Extract()
	{
		if (Size() == 0)
			return 0;
		int min = _heap[1];

		swap(_heap[1], _heap[Size()]);

		_heap.pop_back();

		Heapify(_heap, 1);

		return min;
	}

	//*******************************************************************
	//		Heap :: Heapify()
	//		Parameters :: vector A, vector to heapify; int e, element to
	//						swap to the correct place
	//		Complexity: O(log n)
	//	Recursive function swaps elements in a given sub tree until it is
	//	compliant with the heap property
	//*******************************************************************
	void Heapify(vector<int>& A, int e)
	{
		int left = e << 1;
		int right = 1 + (e << 1);
		int small = e;
		int tmp;
		//select the smallest of the (potentially) 3 values
		if (left <= Size())
		{
			if (A[left] < A[small])
				small = left;
		}
		if (right <= Size())
			if (A[right] < A[small])
				small = right;
		//make the swap if a smaller child was found

		if (small != e)
		{
			//swap
			tmp = A[e];
			A[e] = A[small];
			A[small] = tmp;
			//now heapify again
			Heapify(A, small);

		}
	}
};

//*******************************************************************
//	I have written the entire program as turned in and have not
//	copied this code, or parts of this code from the internet or
//	another student
//
//						Signature:__________________________________
//
//*******************************************************************
int main()
{
	vector<int> nums;
	int testCase, num;
	int sumCost = 0;
	int cost = 0;

	cin >> testCase;
	while (testCase != 0)
	{
		while (testCase > 0)
		{
			cin >> num;

			nums.push_back(num);

			testCase--;
		}

		Heap minHeap(nums);

		//the heap will only ever reach 1
		while(minHeap.Size() > 1)
		{
			//add two smallest values
			cost = minHeap.Extract();
			cost += minHeap.Extract();
			sumCost += cost;

			//it may sometimes be best to add a previous sum
			//so they shouldn't just be discarded
			//this is important
			minHeap.Insert(cost);
		}

		cout << sumCost << endl;

		cin >> testCase;
		nums.clear();
		sumCost = 0;
		cost = 0;
	}

	return 0;
}
```
