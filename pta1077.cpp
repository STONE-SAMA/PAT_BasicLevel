#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
// 1077 互评成绩计算
int pta1077()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int g2;//教师打分
		cin >> g2;
		int count = 0;
		int sum = 0;
		int max = -1;
		int min = 100;
		for (int j = 1; j < n; j++)//获取学生打分
		{
			int temp;
			cin >> temp;
			if (temp >= 0 && temp <= m)
			{
				count++;
				sum += temp;
				if (temp > max)
				{
					max = temp;
				}
				if(temp < min)
				{
					min = temp;
				}
			}		
		}
		double g = g2 * 0.5 + ((sum - max - min) / (count - 2)) * 0.5;
		printf("%d", (int)round(g));
		if (i != n)
			printf("\n");
	}
	


	return 0;
}