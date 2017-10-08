```cpp
//							David McGinn
//						UVA name: SugoiDesuNe
#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	vector<int> lst, testlst;
	int lnSize, n, sum, put, x = 0;
	
	while (cin >> lnSize)
	{
		//clear lists to start a new one
		lst.clear();
		testlst.clear();
		//reset x
		x = 0;
		while (x < lnSize)
		{
			cin >> put;
			lst.push_back(put);
			x++;
		}
		//load all n-1 - 1 into testlist
		n = lst.size() - 1;
		while (n > 0)
		{
			testlst.push_back(n);
			n--;
		}

		for (unsigned int i = 0; i < lst.size() - 1; i++)
		{
			sum = abs(lst[i] - lst[i + 1]);
			for (unsigned int j = 0; j < testlst.size(); j++)
				if (sum == testlst[j])
					testlst.erase(testlst.begin() + j);
		}

		if (testlst.size() == 0)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;


	}
	return 0;
}
```
