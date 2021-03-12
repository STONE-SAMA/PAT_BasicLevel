#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1058 选择题 
struct node
{
	int mark;
	string choose;//选项,如:2 a c
};
struct problem
{
	int id;
	int num = 0;
};
bool cmp(problem p1, problem p2)
{
	if (p1.num != p2.num)
		return p1.num > p2.num;
	else
		return p1.id < p2.id;
}
int pta1058()
{
	int n, m;
	cin >> n >> m;
	vector<node> v(m);
	for (int i = 0; i < m; i++)
	{
		int score;
		cin >> v[i].mark;
		cin >> score;
		getchar();
		getline(cin, v[i].choose);
		//cout << v[i].choose << endl;
	}
	vector<problem> wrong(m);
	for (int i = 0; i < n; i++)
	{
		int total = 0;
		string str;
		getline(cin, str);
		//cout << "str  = " << str << endl;
		int j = 0;
		int count = 0;
		for (j = 0; j < str.size(); j++)
		{
			if (count > m)
			{
				break;
			}
			else
			{
				if (str[j] == '(')
				{
					string ans;
					int t;
					for (t = j + 1; t < 1000; t++)
					{
						if (str[t] == ')') {
							break;
						}
						else
						{
							ans += str[t];
						}
					}
					//cout << "ans = " << ans << endl; 
					if (v[count].choose == ans)
					{
						total += v[count].mark;
					}
					else
					{
						wrong[count].id = count;
						wrong[count].num++;
					}
					count++;
				}
			}

		}
		cout << total << endl;
	}
	sort(wrong.begin(), wrong.end(), cmp);
	int max = wrong[0].num;
	if (max == 0)
	{
		cout << "Too simple";
	}
	else
	{
		cout << max;
		for (int i = 0; i < m; i++)
		{
			if (wrong[i].num == max)
			{
				cout << " " << wrong[i].id + 1;
			}
			else
			{
				break;
			}

		}
	}
	return 0;
}
