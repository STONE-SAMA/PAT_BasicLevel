#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//1045 ��������
//����ѭ��-->��ʱ
//Ӧ��ֱ��ʹ��sort��������Ȼ��Ƚ�����ǰ���λ�ñ仯
//���λ�ò��䣬�ҵ�ǰԪ�ش���ǰ�����ֵʱΪ��Ԫ
int pta1045()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	if (n == 1)
	{
		cout << "1" << endl;
		cout << v[0];
		return 0;
	}

	int count = 0;
	vector<int> num;//��ſ�������Ԫ��Ԫ��
	bool flag = true;
	//��һ��Ԫ��
	for (int i = 1; i < n; i++)
	{
		if (v[i] < v[0])
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		count++;
		num.push_back(v[0]);
	}
	//��2��(n-1)��Ԫ��
	for (int i = 1; i < n - 1; i++)
	{
		flag = true;
		for (int j = 0; j < i; j++)
		{
			if (v[i] < v[j])
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			for (int j = i+1; j < n; j++)
			{
				if (v[i] > v[j])
				{
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
		{
			count++;
			num.push_back(v[i]);
		}
	}
	//��n��Ԫ��
	flag = true;
	for (int i = 0; i < n-1; i++)
	{
		if (v[n-1] < v[i])
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		count++;
		num.push_back(v[n-1]);
	}
	sort(num.begin(), num.end());
	if (count == 0)
	{
		cout << "0" << endl;
		cout << endl;
	}
	else
	{
		cout << count << endl;
		for (vector<int>::iterator it = num.begin(); it != num.end(); it++)
		{
			cout << *it;
			if (it != num.end() - 1)
				cout << " ";
		}
	}
	
	return 0;
}
