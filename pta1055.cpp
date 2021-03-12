#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1055 集体照
struct node
{
	string name;
	int height;

};
bool cmp(node n1, node n2)
{
	if (n1.height != n2.height)
	{
		return n1.height > n2.height;
	}
	else
	{
		return n1.name < n2.name;
	}
}

int pta1055()
{
	int n, k;
	cin >> n >> k;
	int row = n / k;
	int last_row = row + n % k;
	vector<node> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].name >> v[i].height;
	}
	sort(v.begin(), v.end(), cmp);
	
	//for (int i = 0; i < n; i++)
	//{
	//	cout << v[i].name << "===" << v[i].height << endl;
	//}
	//cout << "-----------" << endl;

	int count = 0;
	vector<int> temp(last_row);
	int mid = last_row / 2 ;
	//vector<int> temp(last_row);
	temp[mid] = count;
	int flag = last_row-1;
	//最后一排单独排列
	for (int j = 1; j < mid+1; j++)
	{
		if (last_row%2==0)//人数为偶数
		{
			if (flag > 1)
			{
				count++;
				temp[mid - j] = count;
				count++;
				temp[mid + j] = count;
				flag -= 2;
			}
			else
			{
				count++;
				temp[mid - j] = count;
				
			}
		}
		else//人数为奇数
		{
			if (flag > 0)
			{
				count++;
				temp[mid - j] = count;
				count++;
				temp[mid + j] = count;
				flag -= 2;
			}
		}	
	}
	for (int i = 0;i < last_row;i++)
	{
		cout << v[temp[i]].name;
		if (i != last_row - 1)
			cout << " ";
	}	
	cout << endl;
	//其余各排
	mid = row / 2;
	for (int m = 1; m < k; m++)
	{
		flag = row - 1;
		vector<int> list(row);
		count++;
		list[mid] = count;
		for (int j = 1; j < mid + 1; j++)
		{
			if (row % 2 == 0)//人数为偶数
			{
				if (flag > 1)
				{
					count++;
					list[mid - j] = count;
					count++;
					list[mid + j] = count;
					flag -= 2;
				}
				else
				{
					count++;
					list[mid - j] = count;
				}
			}
			else//人数为奇数
			{
				if (flag > 0)
				{
					count++;
					list[mid - j] = count;
					count++;
					list[mid + j] = count;
					flag -= 2;
				}
			}
		}
		for (int i = 0;i < row;i++)
		{
			cout << v[list[i]].name;
			if (i != row - 1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}