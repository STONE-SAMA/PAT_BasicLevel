#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
//1095 解码PAT准考证 
//超时！
struct node
{
	string pta;//准考证
	char level;
	int place;//考场编号
	string date;//考试日期
	int mark;
};
bool cmp(node n1, node n2)
{
	if (n1.mark != n2.mark)
		return n1.mark > n2.mark;
	else
		return n1.pta < n2.pta;
}
struct exam
{
	int place;
	int num;
};
bool compare(exam e1, exam e2)
{
	if (e1.num != e2.num)
		return e1.num > e2.num;
	else
		return e1.place < e2.place;
}
int pta1095()
{
	int n, m;
	cin >> n >> m;
	vector<node> v(n);
	for (int i = 0; i < n; i++)
	{
		string str;
		int temp;
		cin >> str >> temp;
		v[i].pta = str;
		v[i].level = str[0];
		v[i].place = stoi(str.substr(1, 3));
		v[i].date = str.substr(4,6);
		v[i].mark = temp;
	}

	//for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
	//	cout << it->pta << "===" << it->level << "===" << it->place << "===" << it->date << "===" << it->mark << endl;
	int count = 1;
	for(int i = 0; i < m; i++)
	{
		int choose;
		string str;
		cin >> choose >> str;
		cout << "Case " << count << ": " << choose << " " << str << endl;
		count++;
		switch (choose)
		{
		case 1: 
		{
			//cout << "Case 1: " << choose << " " << str << endl;
			sort(v.begin(), v.end(), cmp);
			bool flag = false;
			for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
			{
				char c = str[0];
				if (it->level == c)
				{
					flag = true;
					cout << it->pta << " " << it->mark << endl;
				}
			}
			if (flag == false)
				cout << "NA" << endl;
			break;
		}		
		case 2:
		{
			int id = stoi(str);//考场号
			bool flag = false;
			int total = 0;//总分
			int num = 0;//考场人数
			for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
			{
				if (it->place == id)
				{
					flag = true;
					num++;
					total += it->mark;
				}
			}
			if (flag == false)
				cout << "NA" << endl;
			else
				cout << num << " " << total << endl;
			break;
		}		
		case 3:
		{
			bool flag = false;
			unordered_map<int, int> umap;
			for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
			{
				if (it->date == str)
				{
					flag = true;
					umap[it->place]++;
				}
			}
			
			if (flag == false)
				cout << "NA" << endl;
			else
			{
				vector<exam> vec;
				for (auto it = umap.begin(); it != umap.end(); it++)
				{
					vec.push_back({ it->first, it->second });
				}
				sort(vec.begin(), vec.end(), compare);
				for (auto it = vec.begin(); it != vec.end(); it++)
				{
					cout << it->place << " " << it->num << endl;
				}
			}
			break;
		}	
		default:
			cout << "NA" << endl;
			break;
		}
	}

	return 0;
}