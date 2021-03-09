#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

//pta1070  通过排序，使得绳子从小到大排序

void bubleSort(int *p, int total)
{
	int i, j;
	for (i = 0; i < total - 1; i++)
	{
		for (j = 0;j < total - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

//超时！
int pat1070()
{
	int total;
	cin >> total;
	int* p;
	p = new int[total];
	for (int i = 0; i < total; i++)
	{
		cin >> p[i];
	}
	if (total == 2) {
		cout << (p[0] + p[1]) / 2;
	}
	else
	{
		
		while (total > 2)
		{
			bubleSort(p, total);
			int flag = (p[0] + p[1]) / 2;
			p[0] = flag;
			p[1] = p[total - 1];
			total--;
		}
		cout << (p[0] + p[1]) / 2;
		
	}
	delete[]p;
	return 0;
}
