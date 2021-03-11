#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//1035 插入与归并 
int pta1035()
{
	int n;
	cin >> n;
	int a[100], b[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	int flag = 0;//0为归并，1为插入
	for (int i = 0; i < n - 1; i += 2)
	{
		if (b[i] > b[i + 1])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		cout << "Insertion Sort" << endl;
		int temp = 0;
		for (temp = 0; temp < n-1; temp++)
		{
			if (b[temp] > b[temp + 1])
				break;
		}
		sort(b, b + temp + 2);
		for (int i = 0; i < n; i++)
		{
			cout << b[i];
			if (i != n - 1)
				cout << " ";
		}
	}
	else
	{
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while (flag) {
			flag = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] != b[i])
					flag = 1;
			}
			k = k * 2;
			for (int i = 0; i < n / k; i++)
				sort(a + i * k, a + (i + 1) * k);
			sort(a + n / k * k, a + n);
		}
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
			if (i != n - 1)
				cout << " ";
		}

	}

	return 0;
}
