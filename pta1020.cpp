#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
//1020 月饼
struct node
{
	float total;//月饼的库存量
	float price;//月饼的总售价
	float rate;
};
int cmp(node n1, node n2)
{
	return n1.rate > n2.rate;
}
int pta1020()
{
	int n, d;
	scanf_s("%d %d", &n, &d);
	vector<node> v;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		float num;
		scanf_s("%f", &num);
		v[i].total = num;
	}
	for (int i = 0; i < n; i++)
	{
		float num;
		scanf_s("%f", &num);
		v[i].price = num;
		v[i].rate = v[i].price / v[i].total;
	}
	sort(v.begin(), v.end(), cmp);
	/*for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->total << "====" << it->price << "====" << it->rate << endl;
	}
	cout << "--------------------" <<endl;*/

	float sale = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].total <= d)
		{
			sale += v[i].price;
		}
		else
		{
			sale += d * v[i].rate;
			break;
		}
		d = d - v[i].total;
	}
	printf("%.2f", sale);
	return 0;
}
