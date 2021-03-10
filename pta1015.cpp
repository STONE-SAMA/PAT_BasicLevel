#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1015 德才论
struct node
{
	int id;
	int grade;//德育分
	int score;//才育分
};
vector<node> v[4];//4类考生
bool cmp(node n1, node n2)
{
	int total_n1 = n1.grade + n1.score;
	int total_n2 = n2.grade + n2.score;
	if (total_n1 != total_n2)
	{
		return total_n1 > total_n2;
	}
	else if (n1.grade != n2.grade)
	{
		return n1.grade > n2.grade;
	}
	else
	{
		return n1.id < n2.id;
	}

}

int pta1015()
{
	int n, low, high;
	cin >> n >> low >> high;
	node temp;
	int total = n;//达线人数
	for (int i = 0; i < n; i++)
	{
		cin >> temp.id >> temp.grade >> temp.score;
		if (temp.grade < low || temp.score < low)
		{
			total--;
		}
		else if (temp.grade >= high && temp.score >= high)//才德全尽
		{
			v[0].push_back(temp);
		}
		else if (temp.grade >= high && temp.score < high)//德胜才
		{
			v[1].push_back(temp);
		}
		else if (temp.grade < high && temp.score < high && temp.grade >= temp.score)//“才德兼亡”但尚有“德胜才”者
		{
			v[2].push_back(temp);
		}
		else
		{
			v[3].push_back(temp);
		}
	}
	printf("%d\n", total);
	for (int i = 0; i < 4; i++)
	{
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++)
		{
			printf("%d %d %d\n", v[i][j].id, v[i][j].grade, v[i][j].score);
		}
	}

	return 0;
}