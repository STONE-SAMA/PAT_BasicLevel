#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//1065 单身狗 
#define MAX 50000
int pta1065()
{
	int n;
	cin >> n;
	vector<int> v(2 * MAX, -1);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a] = b;
		v[b] = a;
	}
	int m;
	cin >> m;
	int count = 0;
	vector<int> flag(2 * MAX, -1);
	vector<int> temp;
	vector<int> num;
	for (int i = 0; i < m; i++)
	{
		int id;
		cin >> id;
		if (v[id] == -1)//未婚，直接认定为单身狗
		{
			count++;
			num.push_back(id);
		}
		else
		{
			temp.push_back(id);
			flag[id] = 1;
		}
	}
	for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		int id = *it;
		int couple = v[id];//伴侣id
		if (flag[couple] == -1)//伴侣未参加
		{
			count++;
			num.push_back(id);
		}
	}

	cout << count << endl;

	sort(num.begin(), num.end());
	for (vector<int>::iterator it = num.begin(); it != num.end(); it++)
	{
		//cout << *it;
		printf("%05d", *it);//id可能以0开头
		if (it + 1 != num.end())
			cout << " ";
	}

	return 0;
}

