#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
//1085 PAT单位排行
struct node
{
	string name;
	int score;//加权分
	int num;//学校参赛人数
};
map<string, int> total;//参赛人数
map<string, double> sum;//总分
bool cmp(node n1, node n2)
{
	if (n1.score != n2.score)
	{
		return n1.score > n2.score;
	}
	else if (n1.num != n2.num)
	{
		return n1.num < n2.num;
	}
	else
	{
		return n1.name < n2.name;
	}
};
int pta1085()
{
	int n;
	cin >> n;
	string id, school;
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		double score;
		scanf("%lf", &score);
		cin >> school;
		for (int j = 0; j < school.length(); j++)
		{
			school[j] = tolower(school[j]);
		}
		if (id[0] == 'B')
			score = score / 1.5;
		else if (id[0] == 'T')
			score = score * 1.5;
		total[school]++;
		sum[school] += score;
	}
	vector<node> v;
	for (map<string, int>::iterator it = total.begin(); it != total.end(); it++)
	{
		v.push_back(node{ it->first,(int)sum[it->first], it->second });
	}
	sort(v.begin(), v.end(), cmp);
	int rank = 0, pre = -1;
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (pre != v[i].score)
			rank = i + 1;//排名
		pre = v[i].score;
		printf("%d ", rank);
		cout << v[i].name;
		printf(" %d %d\n", v[i].score, v[i].num);
	}
	return 0;
}
