#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//1053 住房空置率
int pta1053()
{
	int n, d;
	double e;
	cin >> n >> e >> d;
	int flag = 0;//可能空置
	int temp = 0;//空置
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		int count = 0;
		for (int j = 0; j < k; j++)
		{
			double a;
			cin >> a;
			if (a < e)
				count++;
		}
		if (count > k / 2)
		{
			if (k > d)//若观察期超过某给定阈值 D 天，且满足上一个条件，则该住房为“空置”
				temp++;
			else
				flag++;
		}

	}
	double r1, r2;
	r1 = (double)flag / n * 100;
	r2 = (double)temp / n * 100;
	printf("%.1f%% %.1f%%", r1,r2);
	return 0;
}
