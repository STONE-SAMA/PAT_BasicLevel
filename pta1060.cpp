#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//1060 °®¶¡¶ÙÊý
bool cmp(int a, int b)
{
	return a > b;
}
int pta1060()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0, p = 1;
	while (ans <= n && v[p-1] > p) {
		ans++;
		p++;
	}
	cout << ans;

	return 0;
}