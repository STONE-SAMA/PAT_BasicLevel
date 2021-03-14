#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1092 最好吃的月饼
struct node
{
	int id;
	int total = 0;
};
bool cmp(node n1, node n2)
{
	if (n1.total != n2.total)
	{
		return n1.total > n2.total;
	}
	else
	{
		return n1.id < n2.id;
	}
	
}
int pta1092()
{
	int n, m;
	cin >> n >> m;
	vector<node> v(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			v[j].id = j + 1;
			v[j].total += temp;
		}
	}
	sort(v.begin(), v.end(), cmp);
	int max = v[0].total;
	cout << max << endl;
	vector<int> num;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (it->total == max)
		{
			num.push_back(it->id);
		}
		else
		{
			break;
		}
	}
	for (auto it = num.begin(); it != num.end(); it++)
	{
		cout << *it;
		if (it != num.end() - 1)
			cout << " ";
	}
	return 0;
}