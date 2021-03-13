#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//1087 有多少不同的值
int pta1087()
{
	int n;
	cin >> n;
	int max = n / 2 + n / 3 + n / 5 + 1;
	vector<int> v(max, 0);
	for (int i = 2; i <= n; i++)
	{
		int temp;
		temp = i / 2 + i / 3 + i / 5;
		v[temp] = 1;
	}
	int count = 1;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (*it != 0)
			count++;
	}
	cout << count;

	return 0;
}