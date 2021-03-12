#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//1045 快速排序
//暴力循环-->超时
//应该直接使用sort进行排序，然后比较排序前后的位置变化
//相对位置不变，且当前元素大于前面最大值时为主元
int pta1045()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	if (n == 1)
	{
		cout << "1" << endl;
		cout << v[0];
		return 0;
	}

	int count = 0;
	vector<int> num;//存放可能是主元的元素
	bool flag = true;
	//第一个元素
	for (int i = 1; i < n; i++)
	{
		if (v[i] < v[0])
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		count++;
		num.push_back(v[0]);
	}
	//第2至(n-1)个元素
	for (int i = 1; i < n - 1; i++)
	{
		flag = true;
		for (int j = 0; j < i; j++)
		{
			if (v[i] < v[j])
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			for (int j = i+1; j < n; j++)
			{
				if (v[i] > v[j])
				{
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
		{
			count++;
			num.push_back(v[i]);
		}
	}
	//第n个元素
	flag = true;
	for (int i = 0; i < n-1; i++)
	{
		if (v[n-1] < v[i])
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		count++;
		num.push_back(v[n-1]);
	}
	sort(num.begin(), num.end());
	if (count == 0)
	{
		cout << "0" << endl;
		cout << endl;
	}
	else
	{
		cout << count << endl;
		for (vector<int>::iterator it = num.begin(); it != num.end(); it++)
		{
			cout << *it;
			if (it != num.end() - 1)
				cout << " ";
		}
	}
	
	return 0;
}
