#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
//1067 ÊÔÃÜÂë 
int pta1067()
{
	string password;
	int n;
	cin >> password >> n;
	getchar();
	while (n > 0)
	{
		string str;
		getline(cin, str);
		if (str == "#")
		{
			return 0;
		}
		if (str == password)
		{
			cout << "Welcome in";
			return 0;
		}
		else
		{
			cout << "Wrong password: " << str << endl;
		}

		n--;
	}
	cout << "Account locked";
	return 0;
}