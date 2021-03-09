#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
//1068 万绿丛中一点红
//为满分
int pta1068()
{
	int m, n, tol;//m列  n行
	cin >> m >> n >> tol;
	vector<vector<int>> v(n, vector<int>(m));
	if (m < 3 || n < 3)
	{
		cout << "Not Exist";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int str;
			cin >> str;
			v[i][j] = str;
		}
	}
	int count = 0;
	int x, y;
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < m-1; j++)
		{
			int temp = v[i][j];
			
			//cout << abs(temp - v[i - 1][j - 1]) << "===" << abs(temp - v[i - 1][j]) << "===" << abs(temp - v[i - 1][j + 1]) << endl;
			//cout << abs(temp - v[i][j - 1]) << "===" << "itself" << "===" << abs(temp - v[i][j + 1]) << endl;
			//cout << abs(temp - v[i + 1][j - 1]) << "===" << abs(temp - v[i + 1][j]) << "===" << abs(temp - v[i + 1][j + 1]) << endl;

			//if (abs(temp - v[i - 1][j - 1]) > tol&& abs(temp - v[i - 1][j]) > tol&& abs(temp - v[i - 1][j + 1]) > tol
			//	&& abs(temp - v[i][j - 1]) > tol&& abs(temp - v[i][j + 1]) > tol
			//	&& abs(temp - v[i + 1][j - 1]) > tol&& abs(temp - v[i + 1][j]) > tol&& abs(temp - v[i + 1][j + 1]) > tol)
			if ((temp - v[i - 1][j - 1]) > tol&& (temp - v[i - 1][j]) > tol&& (temp - v[i - 1][j + 1]) > tol
				&& (temp - v[i][j - 1]) > tol&& (temp - v[i][j + 1]) > tol
				&& (temp - v[i + 1][j - 1]) > tol&& (temp - v[i + 1][j]) > tol&& (temp - v[i + 1][j + 1]) > tol)
			{
				if (count == 0)
				{
					x = i;
					y = j;	
					count++;
				}
				else
				{
					cout << "Not Unique";
					return 0;
				}
				
			}
		}
	}
	//边界 行
	/*
	for (int j = 1; j < m - 1; j++)
	{
		int temp = v[0][j];

		if ((temp - v[0][j - 1]) > tol && (temp - v[0][j + 1]) > tol
			&& (temp - v[1][j - 1]) > tol && (temp - v[1][j]) > tol && (temp - v[1][j + 1]) > tol)
		{
			if (count == 0)
			{
				x = 0;
				y = j;
				count++;
			}
			else
			{
				cout << "Not Unique";
				return 0;
			}

		}
	}
	for (int j = 1; j < m - 1; j++)
	{
		int temp = v[n-1][j];

		if ((temp - v[n-1][j - 1]) > tol && (temp - v[n-1][j + 1]) > tol
			&& (temp - v[n-2][j - 1]) > tol && (temp - v[n-2][j]) > tol && (temp - v[n-2][j + 1]) > tol)
		{
			if (count == 0)
			{
				x = n-1;
				y = j;
				count++;
			}
			else
			{
				cout << "Not Unique";
				return 0;
			}

		}
	}
	//边界 列
	for (int i = 1; i < n - 1; i++)
	{
		int temp = v[i][0];
		if ((temp - v[i - 1][0]) > tol && (temp - v[i - 1][1]) > tol
			&& (temp - v[i][1]) > tol
			&& (temp - v[i + 1][0]) > tol && (temp - v[i + 1][1]) > tol )
		{
			if (count == 0)
			{
				x = i;
				y = 0;
				count++;
			}
			else
			{
				cout << "Not Unique";
				return 0;
			}
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		int temp = v[i][m-1];
		if ((temp - v[i - 1][m-2]) > tol && (temp - v[i - 1][m-1]) > tol
			&& (temp - v[i][m-2]) > tol
			&& (temp - v[i + 1][m-2]) > tol && (temp - v[i + 1][m-1]) > tol)
		{
			if (count == 0)
			{
				x = i;
				y = m-1;
				count++;
			}
			else
			{
				cout << "Not Unique";
				return 0;
			}
		}
	}
	*/
	if (count == 0)
	{
		cout << "Not Exist";
	}
	else if(count == 1)
	{
		printf("(%d, %d): %d", y + 1, x + 1, v[x][y]);
	}
	return 0;
}