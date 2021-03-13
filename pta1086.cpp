#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
//1086 ¾Í²»¸æËßÄã 
int pta1086()
{
	int a, b;
	cin >> a >> b;
	int sum = a * b;
	string str = to_string(sum);
	reverse(str.begin(), str.end());
	sum = stoi(str);
	cout << sum;
	return 0;
}