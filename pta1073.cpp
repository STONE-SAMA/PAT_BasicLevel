#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//1073 ��ѡ�ⳣ���Ʒַ� 

//δ���

struct Question
{
	int point;//��ֵ
	int num_op;//ѡ�����
	int num_cr;//��ȷѡ�����
	string op;//��ȷѡ��
};


int pta1073()
{
	int N;//ѧ������
	int M;//��Ŀ����
	cin >> N;
	cin >> M;
	Question* p;
	p = new Question[M];
	//��ѡ����Ϣ����ṹ������
	for (int i = 0; i < M; i++)
	{
		cin >> p[i].point;
		cin >> p[i].num_op;
		cin >> p[i].num_cr;
		getline(cin, p[i].op);
	}
	//��ʼ�о�
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
