#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//1052 Âô¸öÃÈ 
int pta1052()
{
	vector<vector<string>> v;
	for (int i = 0; i < 3; i++)
	{
		vector<string> row;
		string str;
		getline(cin, str);
		int j = 0, k = 0;
		while (j < str.size())
		{
			if (str[j] == '[')
			{
				while (k < str.size())
				{
					k++;
					if (str[k] == ']')
					{
						row.push_back(str.substr(j + 1, k - j - 1));
						break;
					}
					
				}
			}
			j++;
		}
		v.push_back(row);
		//for (vector<string>::iterator it = row.begin(); it != row.end();it++)
		//	cout << *it;
		//cout << endl;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d, e;//×óÊÖ¡¢×óÑÛ¡¢¿Ú¡¢ÓÒÑÛ¡¢ÓÒÊÖ
		cin >> a >> b >> c >> d >> e;

		if (a > v[0].size() || b > v[1].size() || c > v[2].size() || d > v[1].size() || e > v[0].size()
			|| a < 1 || b < 1 || c < 1 || d < 1 || e < 1)
		{
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		cout << v[0][a - 1] << "(" << v[1][b - 1] << v[2][c - 1] << v[1][d - 1] << ")" << v[0][e - 1] << endl;

	}

	return 0;
}
