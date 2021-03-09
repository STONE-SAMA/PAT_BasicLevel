#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//1075 链表元素分类 (25 分)
struct node
{
	int data, next;
}list[100000];

vector<int> v[3];//二维数组

int pta1075()
{
	int start, n, k, a;//a为地址
	cin >> start >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cin >> list[a].data >> list[a].next;
	}
	int p = start;
	while (p != -1)
	{
		int data = list[p].data;
		if (data < 0)//值比0小
		{
			v[0].push_back(p);
		}
		else if(data >= 0 && data <= k)//值比0大，但小于k
		{
			v[1].push_back(p);
		}
		else//值比k大
		{
			v[2].push_back(p);
		}
		p = list[p].next;
	}
	int flag = 0;
	for (int i = 0; i < 3; i++) {
		for (vector<int>::size_type j = 0; j < v[i].size(); j++) {
			if (flag == 0) {
				printf("%05d %d ", v[i][j], list[v[i][j]].data);
				flag = 1;
			}
			else {
				printf("%05d\n%05d %d ", v[i][j], v[i][j], list[v[i][j]].data);
			}
		}
	}

	printf("-1");
	return 0;
}