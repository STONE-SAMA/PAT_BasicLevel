#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//1084 ������� 
int pta1084()
{
	string d;
	int  n;
	unsigned int k;
	cin >> d >> n;
	for (int i = 1; i < n; i++)
	{
		string ans;
		for (unsigned int j = 0; j < d.length(); j = k)
		{
			for (k = j; k < d.length() && d[k] == d[j]; k++);//ÿһ����������ͬ��ĸ�ĸ���
			ans += d[j] + to_string(k - j);
		}
		d = ans;
	}
	cout << d;
	return 0;
}
