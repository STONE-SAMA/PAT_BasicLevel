#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include <iterator>
using namespace std;

int pta1069()
{
	//得到输入的数字，分别为： 转发的总量 M 、中奖间隔 N 、以及第一位中奖者的序号 S
	string input;
	getline(cin, input);
	istringstream is(input);
	vector<int> nums((istream_iterator<int>(is)), istream_iterator<int>());
	int M = nums[0];
	int N = nums[1];
	int S = nums[2];
	if (M < S)
	{
		cout << "Keep going...";
	}
	else
	{
		string* p;
		p = new string[M];//动态数组
		int count = S - 1;//第一个
		for (int i = 0; i < M; i++)//输入所有参与抽奖的用户名
		{
			getline(cin, p[i]);
		}
		string* q;
		int max = (M - S) / 2 + 1;
		q = new string[max];//存储已中奖用户
		int flag = 0;
		bool temp = false;
		while (count < M)
		{

			temp = false;
			string str = p[count];
			for (int i = 0; i < max; i++)
			{
				if (q[i] == str)//数组中已有该人
				{
					count++;
					temp = true;
					break;
				}
			}
			if (temp == false)
			{
				if (flag != 0) {
					printf("\n");
				}
				q[flag] = str;
				flag++;
				count += N;
				cout << str;
			}
		
		}

		delete []p;//释放动态数组所用空间
		delete []q;
	}
	return 0;
}