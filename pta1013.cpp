#include<stdio.h>
#include<iostream>
using namespace std;
//1013 ÊıËØÊı
bool isPrime(int n) {
	if (n == 0 || n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int pta1013()
{
	int m, n;
	cin >> m >> n;
	int num = 2;
	int count = 0;
	if (m == n)
	{
		while (count != m)
		{
			if (isPrime(num) == true)
			{
				count++;
			}
			num++;
		}
		cout << num - 1;
		return 0;
	}
	while (count != m)
	{
		if (isPrime(num) == true)
		{
			count++;
		}
		num++;
	}
	int flag = 1;
	cout << num - 1 << " ";
	while (count != n)
	{
		if (isPrime(num) == true)
		{
			count++;
			cout << num;
			flag++;
			if (flag % 10 == 0)
			{
				cout << endl;
			}
			else if (count != n)
			{
				cout << " ";
			}
		}
		num++;
	}


	return 0;
}