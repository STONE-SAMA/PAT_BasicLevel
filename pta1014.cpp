#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//1014 福尔摩斯的约会
int pta1014()
{
	string s1, s2, s3, s4;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	getline(cin, s4);
	int size = min(s1.size(), s2.size());
	string week[] = { "MON","TUE", "WED","THU","FRI","SAT" ,"SUN"};
	char c1, c2;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (count == 0) {
			if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
			{
				c1 = s1[i];
				count++;
			}
		}
		else if (s1[i] == s2[i])
		{
			c2 = s1[i];
			break;
		}
		
	}
	cout << week[c1 - 'A'] << " ";
	int hour;
	if (c2 >= '0' && c2 <= '9')
	{
		hour = c2 - '0';
	}
	else
	{
		c2 = tolower(c2);
		hour = c2 - 'a' + 10;
	}
	printf("%02d", hour);
	size = min(s3.size(), s4.size());
	int min = 0;
	for (int i = 0; i < size; i++)
	{
		if (s3[i] == s4[i] && isalpha(s3[i]))
		{
			min = i;
			break;
		}
	}
	printf(":%02d", min);

	return 0;
}

