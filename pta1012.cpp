#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
//1012 Êý×Ö·ÖÀà
int pta1012()
{
	int n;
	cin >> n;
	vector<int> v(5);
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag4 = false;
	bool flag5 = false;
	int count = 0;
	int flag = 1;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp % 5 == 0 && temp % 2 == 0)//A1
		{
			flag1 = true;
			v[0] += temp;
		}
		else if (temp % 5 == 1)//A2
		{
			flag2 = true;
			if (flag % 2 == 1)
			{
				v[1] += temp;
			}
			else
			{
				v[1] -= temp;
			}
			flag++;
		}
		else if(temp % 5 == 2)//A3
		{
			flag3 = true;
			v[2]++;
		}
		else if (temp % 5 == 3)//A4
		{
			flag4 = true;
			v[3] += temp;
			count++;
		}
		else if(temp % 5 == 4)//A5
		{
			flag5 = true;
			if (temp > v[4])
			{
				v[4] = temp;
			}
		}
	}
	if (flag1 == true)
	{
		cout << v[0] << " ";
	}
	else
	{
		cout << "N ";
	}
	if (flag2 == true)
	{
		cout << v[1] << " ";
	}
	else
	{
		cout << "N ";
	}
	if (flag3 == true)
	{
		cout << v[2] << " ";
	}
	else
	{
		cout << "N ";
	}
	if (flag4 == true)
	{
		double ans = (double)v[3] / count;
		printf("%.1f ", ans);
	}
	else
	{
		cout << "N ";
	}
	if (flag5 == true)
	{
		cout << v[4];
	}
	else
	{
		cout << "N";
	}
	return 0;
}