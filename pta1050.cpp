#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//1050 ÂÝÐý¾ØÕó
//https://www.liuchuo.net/archives/2070
bool cmp(int a, int b)
{
	return a > b;
}
int pta1050()
{
	int n,m,N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	for (n = sqrt((double)N); n >= 1; n--) {
		if (N % n == 0) {
			m = N / n;
			break;
		}
	}
	sort(v.begin(), v.end(), cmp);
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//	cout << *it  << endl;
	int level = m / 2 + m % 2;
	vector<vector<int> > b(m, vector<int>(n));
	int t = 0;
	for (int i = 0; i < level; i++) {
		for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
			b[i][j] = v[t++];
		for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
			b[j][n - 1 - i] = v[t++];
		for (int j = n - i - 1; j >= i && t <= N - 1; j--)
			b[m - 1 - i][j] = v[t++];
		for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
			b[j][i] = v[t++];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", b[i][j]);
			if (j != n - 1) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
