#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
//1078 �ַ���ѹ�����ѹ
int pta1078()
{
	char in;
	cin >> in;
	getchar();//���ջ���
	string str;
	string num;
	getline(cin, str);
	int count = 1;
	if (in == 'C' && str.length() != 0)//ѹ��
	{
		char pre = str[0];
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == pre)
			{
				count++;
			}
			else
			{
				if (count >= 2)
				{
					cout << count;
				}
				cout << pre;
				pre = str[i];
				count = 1;
			}
		}
		if (count >= 2)
		{
			cout << count;
		}
		cout << pre;

	}
	else if (in == 'D')//��ѹ
	{
		for (unsigned int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				num += str[i];
			}
			else
			{
				if (num.length() > 0)
					count = stoi(num);//���ַ���תΪʮ����
				for (int j = 0; j < count; j++)
				{
					cout << str[i];
				}
			}
		}

	}

	return 0;
}