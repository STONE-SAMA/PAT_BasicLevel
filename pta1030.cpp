#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//1030 完美数列
int pta1030()
{
	long n,p;
	cin >> n >> p;
	vector<long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	//for (vector<long>::iterator it = v.begin(); it != v.end(); it++)
	//	cout << *it;
	int count = 0, temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + count; j < n; j++)
		{
			if (v[j] <= v[i] * p)
			{
				count = j - i + 1;
				if (count > temp)
					temp = count;
			}
			else
			{
				break;
			}
		}
	}
	cout << count;

	return 0;
}
