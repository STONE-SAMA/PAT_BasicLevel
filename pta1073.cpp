#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//1073 多选题常见计分法 

//未完成

struct Question
{
	int point;//分值
	int num_op;//选项个数
	int num_cr;//正确选项个数
	string op;//正确选项
};


int pta1073()
{
	int N;//学生人数
	int M;//题目数量
	cin >> N;
	cin >> M;
	Question* p;
	p = new Question[M];
	//将选项信息存入结构体数组
	for (int i = 0; i < M; i++)
	{
		cin >> p[i].point;
		cin >> p[i].num_op;
		cin >> p[i].num_cr;
		getline(cin, p[i].op);
	}
	//开始判卷
	string* q;
	q = new string[N];
	for (int i = 0; i < N; i++)
	{
		string ans;
		getline(cin, ans);
		q[i] = ans;



	}

	delete[]p;
	delete[]q;

	return 0;
}
