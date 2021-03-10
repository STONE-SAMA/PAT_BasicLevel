#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
//1003 我要通过！
//只能有一个P一个T，中间末尾和开头可以随便插入A。
//但必须满足开头的A的个数 * 中间的A的个数 = 结尾的A的个数
//且P和T中间不能没有A
int pta1003()
{
	int n;
	scanf_s("%d", &n);
	string str;
	int p = 0;//记录p位置
	int t = 0;//记录t位置
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		map<char, int> mymap;
		for (int j = 0; j < str.size(); j++)
		{
			mymap[str[j]]++;
			if (str[j] == 'P')
				p = j;
			if (str[j] == 'T')
				t = j;
		}
		if (mymap.size() == 3 && mymap['P'] == 1 && mymap['T'] == 1 && mymap['A'] != 0 && t-p != 1 && p * (t - p - 1) == str.length() - t - 1)
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}