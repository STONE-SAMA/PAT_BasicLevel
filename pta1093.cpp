#include<iostream>
#include<string>
#include<vector>
using namespace std;
//1093 字符串A+B 
int pta1093()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	vector<int> v(95);//记录已有字符
	for (int i = 0; i < str1.size(); i++)
	{
		char temp = str1[i];
		if (v[temp - ' '] == 0)//当前字符未出现过
		{
			cout << temp;
			v[temp - ' ']++;
		}
	}
	for (int i = 0; i < str2.size(); i++)
	{
		char temp = str2[i];
		if (v[temp - ' '] == 0)
		{
			cout << temp;
			v[temp - ' ']++;
		}
	}

	return 0;
}