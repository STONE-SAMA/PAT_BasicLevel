#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
//1003 ��Ҫͨ����
//ֻ����һ��Pһ��T���м�ĩβ�Ϳ�ͷ����������A��
//���������㿪ͷ��A�ĸ��� * �м��A�ĸ��� = ��β��A�ĸ���
//��P��T�м䲻��û��A
int pta1003()
{
	int n;
	scanf_s("%d", &n);
	string str;
	int p = 0;//��¼pλ��
	int t = 0;//��¼tλ��
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		map<char, int> mymap;
		for (int j = 0; j < str.size(); j++)
		{
			mymap[str[j]]++;
			if (str[j] == 'P')
				p = j;
			if (str[j] == 'T')
				t = j;
		}
		if (mymap.size() == 3 && mymap['P'] == 1 && mymap['T'] == 1 && mymap['A'] != 0 && t-p != 1 && p * (t - p - 1) == str.length() - t - 1)
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}