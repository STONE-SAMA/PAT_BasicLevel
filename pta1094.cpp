#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
//1094 �ȸ����Ƹ 

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

int pta1094()
{
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	for (int i = 0; i + k <= n; i++)//ע��Ⱥ�
	{
		string temp = str.substr(i, k);
		int num = stoi(temp);
		if (isPrime(num))
		{
			int count = to_string(num).size();
			if (count == k)
			{
				cout << num;
			}
			else
			{
				for (int j = 0; j < k - count; j++)//���λ�������貹0
				{
					cout << "0";
				}
				cout << num;
			}
			
			return 0;
		}
	}
	cout << "404";
	return 0;
}