#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include <iterator>
using namespace std;

int pta1069()
{
	//�õ���������֣��ֱ�Ϊ�� ת�������� M ���н���� N ���Լ���һλ�н��ߵ���� S
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
		p = new string[M];//��̬����
		int count = S - 1;//��һ��
		for (int i = 0; i < M; i++)//�������в���齱���û���
		{
			getline(cin, p[i]);
		}
		string* q;
		int max = (M - S) / 2 + 1;
		q = new string[max];//�洢���н��û�
		int flag = 0;
		bool temp = false;
		while (count < M)
		{

			temp = false;
			string str = p[count];
			for (int i = 0; i < max; i++)
			{
				if (q[i] == str)//���������и���
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

		delete []p;//�ͷŶ�̬�������ÿռ�
		delete []q;
	}
	return 0;
}