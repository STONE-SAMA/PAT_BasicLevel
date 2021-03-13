#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//1088 ÈýÈËÐÐ
void print(double t);
int m, x, y;
int pta1088()
{
	cin >> m >> x >> y;
	for (int i = 99; i >= 10; i--) {
		int j = i % 10 * 10 + i / 10;
		double k = abs(j - i) * 1.0 / x;
		if (j == k * y) {
			cout << i;
			print(i);
			print(j);
			print(k);
			return 0;
		}
	}
	cout << "No Solution";

	return 0;
}
void print(double t) {
	if (m == t) printf(" Ping");
	else if (m < t) printf(" Cong");
	else printf(" Gai");
}