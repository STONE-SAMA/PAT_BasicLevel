#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
//1080 MOOC���ճɼ� 
struct StuGrade
{
	string name;
	int gp;//���߱�̳ɼ� 
	int gm;//���п��Գɼ�
	int gf;//��ĩ���Գɼ� 
	int g;//��ĩ���Գɼ� 
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
	int count = 1;//0��ʾ�޸�ѧ��
	for (int i = 0; i < p; i++)//���� ���߱�̳ɼ� gp
	{
		cin >> s >> grade;
		if (grade >= 200)
		{
			v.push_back(StuGrade{ s,grade,-1,-1,0 });
			mymap.insert(pair<string, int>(s, count));
			count++;
		}
	}
	for (int i = 0; i < m; i++)//���� ���п��Գɼ� gm
	{
		cin >> s >> grade;
		if (mymap[s] != 0)
		{
			v[mymap[s] - 1].gm = grade;
		}

	}
	for (int i = 0; i < n; i++)//���� ��ĩ���Գɼ� gf
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
		//c_str()��������һ��ָ������C�ַ�����ָ�볣��, �����뱾string����ͬ. 
	}

	return 0;
}
