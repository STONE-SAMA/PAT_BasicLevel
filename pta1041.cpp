#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//1041 ¿¼ÊÔ×ùÎ»ºÅ
struct node
{
	string num;//¿¼ÊÔÖ¤ºÅ
	int a;//ÊÔ»ú×ùÎ»ºÅ 
	int b;//¿¼ÊÔ×ùÎ»ºÅ

};

int pta1041()
{
	int n;
	cin >> n;
	vector<node> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].num >> v[i].a >> v[i].b;
	}
	//for (vector<node>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << it->num << "==" << it->a << "==" << it->b << endl;
	//}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			if (v[j].a == temp)
			{
				cout << v[j].num << " " << v[j].b;
				break;
			}
		}

		if (i != m - 1)
			cout << endl;
	}



	return 0;
}
