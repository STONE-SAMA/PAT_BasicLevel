#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//1081 �������
int pta1081()
{
	int n;
	cin >> n;
	//string* p = new string[n];
	getchar();
	for (int i = 0; i < n; i++)
	{
		//getline(cin, p[i]);
		string str;
		getline(cin, str);
		if (str.length() < 6)
		{
			cout << "Your password is tai duan le.";
			if (i != n)
				cout << endl;
		}
		else
		{
			int invalid = 0;//�Ƿ��ַ�
			int zimu = 0;//��ĸ
			int num = 0;//����
			for (int j = 0; j < str.length(); j++)
			{
				if (str[j] != '.' && !isalnum(str[j]))//isalnum() �����������һ���ַ��Ƿ�����ĸ����ʮ��������
					invalid = 1;//���зǷ��ַ�
				else if (isalpha(str[j]))//isalpha() �����������һ���ַ��Ƿ�����ĸ
					zimu = 1;
				else if(isdigit(str[j]))//isdigit() �������һ���ַ��Ƿ���ʮ��������
					num = 1;				
			}
			if (invalid == 1)
			{
				cout << "Your password is tai luan le.";
				if (i != n)
					cout << endl;
			}
			else if (num == 0)
			{
				cout << "Your password needs shu zi.";
				if (i != n)
					cout << endl;
			}
			else if (zimu == 0)
			{
				cout << "Your password needs zi mu.";
				if (i != n)
					cout << endl;
			}
			else
			{
				cout << "Your password is wan mei.";
				if (i != n)
					cout << endl;
			}

		}

	}


	//delete[]p;
	return 0;
}