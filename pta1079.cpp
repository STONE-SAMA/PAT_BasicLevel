#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//1079 �ӳٵĻ�����
string add1079(string str)//strΪ��������õ�����
{
	int flag = 0;//���ƽ�λ
	string arr = str;
	string ans;
	reverse(str.begin(), str.end());
	for (int i = 0; i < arr.length(); i++)
	{
		int num = arr[i] - '0' + str[i] - '0' + flag;
		flag = 0;
		if (num >= 10)
		{
			flag = 1;
			num -= 10;
		}
		ans += char(num + '0');
	}
	if (flag == 1)//����λ
	{
		ans += '1';
	}
	reverse(ans.begin(), ans.end());//ת��
	return ans;
}


int pta1079()
{
	string str;
	cin >> str;
	for (int i = 0; i < 10; i++)
	{
		string arr = str;
		reverse(str.begin(), str.end());
		if (str == arr)
		{
			cout << str << " is a palindromic number.";
			return 0;
		}
		else
		{
			string temp = add1079(str);
			cout << arr << " + " << str << " = " << temp << endl;
			str = temp;
		}
	}
	cout << "Not found in 10 iterations.";
	return 0;
}
