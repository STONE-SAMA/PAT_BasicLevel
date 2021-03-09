#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
//1080 MOOC期终成绩 
struct StuGrade
{
	string name;
	int gp;//在线编程成绩 
	int gm;//期中考试成绩
	int gf;//期末考试成绩 
	int g;//期末考试成绩 
};
map<string, int> mymap;
bool cmp1080(const StuGrade& s1, const StuGrade& s2)
{
	if (s1.g == s2.g)
		return s1.name < s2.name;
	else
		return s1.g > s2.g;
}
int pta1080()
{
	int p, m, n;
	cin >> p >> m >> n;
	//StuGrade* sp = new StuGrade[p];
	vector<StuGrade> v, ans;
	string s;
	int grade;
	int count = 1;//0表示无该学生
	for (int i = 0; i < p; i++)//输入 在线编程成绩 gp
	{
		cin >> s >> grade;
		if (grade >= 200)
		{
			v.push_back(StuGrade{ s,grade,-1,-1,0 });
			mymap.insert(pair<string, int>(s, count));
			count++;
		}
	}
	for (int i = 0; i < m; i++)//输入 期中考试成绩 gm
	{
		cin >> s >> grade;
		if (mymap[s] != 0)
		{
			v[mymap[s] - 1].gm = grade;
		}

	}
	for (int i = 0; i < n; i++)//输入 期末考试成绩 gf
	{
		cin >> s >> grade;
		if (mymap[s] != 0)
		{
			int temp = mymap[s] - 1;
			v[temp].gf = grade;
			if (v[temp].gm > v[temp].gf)
			{
				v[temp].g = int(v[temp].gm * 0.4 + v[temp].gf * 0.6 + 0.5);
			}
			else
			{
				v[temp].g = grade;
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].g >= 60)
		{
			ans.push_back(v[i]);
		}
	}
	sort(ans.begin(), ans.end(), cmp1080);
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
		//c_str()函数返回一个指向正规C字符串的指针常量, 内容与本string串相同. 
	}

	return 0;
}
