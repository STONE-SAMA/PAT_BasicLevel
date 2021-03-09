#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
//1078 字符串压缩与解压
int pta1078()
{
	char in;
	cin >> in;
	getchar();//吸收换行
	string str;
	string num;
	getline(cin, str);
	int count = 1;
	if (in == 'C' && str.length() != 0)//压缩
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
	else if (in == 'D')//解压
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
					count = stoi(num);//将字符串转为十进制
				for (int j = 0; j < count; j++)
				{
					cout << str[i];
				}
			}
		}

	}

	return 0;
}