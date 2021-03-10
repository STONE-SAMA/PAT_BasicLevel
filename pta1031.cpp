#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//1031 查验身份证
int num[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
int m[] = { 1,0,10,9,8,7,6,5,4,3,2 };
bool match(string str)
{
	char x = str[17];//校验码
	int sum = 0;
	for (int i = 0; i < 17; i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
		sum += (str[i] - '0') * num[i];
	}
	int temp;
	if (x == 'X')
		temp = 10;
	else
		temp = x - '0';
	return temp == m[sum % 11];

}

int pta1031()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (match(str) == false)
		{
			count++;
			cout << str << endl;
		}

	}
	if (count == 0)
		cout << "All passed";
	return 0;
}
