```cpp
//*******************************************************************
//		Project #0: Removing Duplicate Elements From Arrays
//		Name: David McGinn						
//		Advanced Structures And Algorithms: CMPS 3013
//		Date: 8/30/17
//*******************************************************************
//		This program will read numbers in from a file and use	
//		them to populate an array.  The program will then remove 
//		all duplicate values from the array and return a new
//		array in the same order.
//*******************************************************************


#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int * RemDups(int A[], int size, int &newsize);

//*******************************************************************
//I have written the entire program as turned in and have not copied
//	this code, or parts of this code from the internet or another
//	student.
//
//					Signature____________________________
//*******************************************************************
int main()
{
	ofstream outfile;
	ifstream infile;
	string filename;
	int max, newsize = 0;
	int * arr;
	int * cleaned;
	
	cout << "Enter Input File Name(include extension)" << endl;
	//accepts a user entered file name
	getline(cin, filename);

	infile.open(filename);
	outfile.open("McGinn_Output.txt");

	//prime infile
	infile >> max;
	
	//while loop iterates until the end is reached
	while (!infile.eof())
	{
		arr = new int[max];
		//for loop adds items to array
		for (int i = 0; i < max; i++)
		{
			
			infile >> arr[i];
		}
		cout << endl;

		//call to RemDups passing in raw array, max, and newsize by reference
		cleaned = RemDups(arr, max, newsize);

		//for loop prints out the clean array
		for (int i = 0; i < newsize; i++)
		{
			cout << cleaned[i] << " ";
		}
		cout << endl;

		delete[] arr;
		arr = nullptr;
		delete[] cleaned;
		cleaned = nullptr;
		infile >> max;
	}
	
	return 0;
}




//*******************************************************************
//		Function :: RemDups()
//		Parameters: 
//			int A[], an array of intergers to be processed
//			int size, the size of the array to be processed
//			int newsize, the size of the processed array
//		Complexity: O((2n^2)+2)
//		The method accepts an array and the size of said array.
//		It then processes the array by removing duplicate intergers.
//		Finally, the function returns the new array and its newsize
//*******************************************************************
int * RemDups(int A[], int size, int &newsize)
{
	newsize = 0;
	int * newArr;
	bool isDup = false;
	newArr = new int[size];
	

	if (size == 0)
		return nullptr;

	cout << endl;

	//assign the first value of newArr
	newArr[0] = A[0];		
	//Increase newsize accordingly
	newsize++;				

	//For loop iterates n-1 times
	for (int i = 1; i < size; i++)				
	{
		//inner for loop can iterate no more than n-1 times
		//as it does not need to check at least the value being analyzed
		for (int j = 0; j < newsize; j++)		
		{
			//checks if two values are equal
			if (A[i] == newArr[j])				
				//sets isDup to true if an equal value is detected
				isDup = true;					
		}//inner for loop terminates
		
		//adds a new value to the newArr if no duplicate is
		//detected
		//increments newsize accordingly
		if (isDup == false)						
		{
			newArr[newsize] = A[i];				
			newsize++;							
		}
		//resets isDup to false
		isDup = false;							
	}//outer for terminates

	
	//returns the new array
	return newArr;

}

```
