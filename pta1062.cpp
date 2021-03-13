#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
//1062 最简分数

//辗转相除法gcd计算a和b的最大公约数
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int pta1062()
{
	string str1, str2;
	int k;
	cin >> str1 >> str2 >> k;
	int flag = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] == '/')
		{
			flag = i;
			break;
		}
			
	}
	int a = stoi(str1.substr(0, flag));
	int b = stoi(str1.substr(flag + 1));
	for (int i = 0; i < str2.size(); i++)
	{
		if (str2[i] == '/')
		{
			flag = i;
			break;
		}

	}
	int c = stoi(str2.substr(0, flag));
	int d = stoi(str2.substr(flag + 1));
	//double min = (double)a / b;
	//double max = (double)c / d;
	if (a * d > b* c)
	{
		swap(a, c);
		swap(b, d);
	}
	int num = 1;
	bool temp = false;
	while (a * k >= b * num) 
		num++;
	while (a * k < b * num && d * num < c * k) {
		if (gcd(num, k) == 1) {
			printf("%s%d/%d", temp == true ? " " : "", num, k);
			temp = true;
		}
		num++;
	}

	return 0;
}