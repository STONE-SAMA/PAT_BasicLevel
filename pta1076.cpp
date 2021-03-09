#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
// 1076 WifiÃÜÂë
int pta1076()
{
	int n;
	cin >> n;
	string str;
	while (cin >> str)
	{
		if (str[2] == 'T')
		{
			if (str[0] == 'A')
			{
				cout << 1;
			}
			else if (str[0] == 'B')
			{
				cout << 2;
			}
			else if (str[0] == 'C')
			{
				cout << 3;
			}
			else
			{
				cout << 4;
			}
		}
	}

	return 0;
}
