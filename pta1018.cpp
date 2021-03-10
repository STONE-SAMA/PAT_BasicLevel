#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//1018 锤子剪刀布
int match(char a, char b)//1为甲胜,0为平，-1为甲负
{
	if (a =='C' && b=='J')
	{
		return 1;
	}
	else if (a == 'C' && b == 'B')
	{
		return -1;
	}
	else if (a == 'C' && b == 'C')
	{
		return 0;
	}
	else if (a == 'J' && b == 'C')
	{
		return -1;
	}
	else if (a == 'J' && b == 'J')
	{
		return 0;
	}
	else if (a == 'J' && b == 'B')
	{
		return 1;
	}
	else if (a == 'B' && b == 'C')
	{
		return 1;
	}
	else if (a == 'B' && b == 'J')
	{
		return -1;
	}
	else if (a == 'B' && b == 'B')
	{
		return 0;
	}
}
int findMax(int num[3])//0:B  1:C  2:J
{
	int temp = 0;
	if (num[1] > num[temp])
	{
		temp = 1;
	}
	else if(num[2] > num[temp])
	{
		temp = 2;
	}
	return temp;
}

int pta1018()
{
	int n;
	scanf_s("%d", &n);
	int a[3] = { 0,0,0 };//记录甲的胜、平、负，乙只需逆序输出
	int b[3] = { 0,0,0 };//甲出B、C、J的胜率
	int c[3] = { 0,0,0 };//乙出B、C、J的胜率
	for (int i = 0; i < n; i++)
	{
		char m, n;
		cin >> m >> n;//甲、乙手势
		int result = match(m, n);
		if (result == 1)//甲胜
		{
			a[0]++;
			if (m == 'B')
				b[0]++;
			else if (m == 'C')
				b[1]++;
			else
				b[2]++;
		}
		else if(result == 0)//平
		{
			a[1]++;
		}
		else//甲负
		{
			a[2]++;
			if (n == 'B')
				c[0]++;
			else if (n == 'C')
				c[1]++;
			else
				c[2]++;
		}

	}
	printf_s("%d %d %d\n", a[0], a[1], a[2]);
	printf_s("%d %d %d\n", a[2], a[1], a[0]);
	char k[3] = { 'B','C','J' };
	int r1,r2;
	r1 = findMax(b);
	r2 = findMax(c);
	printf("%c %c", k[r1], k[r2]);

	return 0;
}
