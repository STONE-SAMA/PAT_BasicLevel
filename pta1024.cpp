#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
//1024 ��ѧ������
int pta1024()
{
	string str;
	cin >> str;
	int flag;// Eλ��
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'E')
		{
			flag = i;
			break;
		}
	}
	string first;//Eǰ���ַ���
	first = str.substr(1, flag-1);
	int n = stoi(str.substr(flag + 1));//E���ַ���ת��������
	if (str[0] == '-')
		cout << "-";
	if (n < 0)//ǰ��
	{
		cout << "0.";
		for (int j = 0; j < abs(n) - 1; j++)
		{
			cout << "0";
		}
		cout << str[1];
		for (int j = 3; j < flag; j++)
		{
			cout << str[j];
		}
	}
	else
	{
		cout << first[0];
		unsigned int j, count;
		for (j = 2, count = 0; j < first.size() && count < n; j++, count++)
		{
			cout << first[j];
		}
		if (j == first.length())
		{
			for (int k = 0; k < n - count; k++) 
				cout << '0';
		}
		else
		{
			cout << '.';
			for (int k = j; k < first.length(); k++) 
				cout << first[k];
		}

	}


	return 0;
}