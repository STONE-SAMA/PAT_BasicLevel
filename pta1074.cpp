#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//1074 ÓîÖæÎÞµÐ¼Ó·¨Æ÷
int pta1074()
{
	string str, str1, str2;
	cin >> str >> str1 >> str2;
	string ans = str;
	int carry = 0;
	int flag = 0;
	string ss1(str.length() - str1.length(), '0');
	str1 = ss1 + str1;
	string ss2(str.length() - str2.length(), '0');
	str2 = ss2 + str2;
	for (int i = str.length() - 1; i >= 0; i--) {
		int mod = str[i] == '0' ? 10 : (str[i] - '0');
		ans[i] = (str1[i] - '0' + str2[i] - '0' + carry) % mod + '0';
		carry = (str1[i] - '0' + str2[i] - '0' + carry) / mod;
	}
	if (carry != 0) ans = '1' + ans;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != '0' || flag == 1) {
			flag = 1;
			cout << ans[i];
		}
	}
	if (flag == 0) cout << 0;
	return 0;
}