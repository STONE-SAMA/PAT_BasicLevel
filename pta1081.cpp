#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//1081 检查密码
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
			int invalid = 0;//非法字符
			int zimu = 0;//字母
			int num = 0;//数字
			for (int j = 0; j < str.length(); j++)
			{
				if (str[j] != '.' && !isalnum(str[j]))//isalnum() 函数用来检测一个字符是否是字母或者十进制数字
					invalid = 1;//含有非法字符
				else if (isalpha(str[j]))//isalpha() 函数用来检测一个字符是否是字母
					zimu = 1;
				else if(isdigit(str[j]))//isdigit() 用来检测一个字符是否是十进制数字
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