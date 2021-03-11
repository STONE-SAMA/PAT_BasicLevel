#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//1034 有理数四则运算
string myNumber(long long num1, long long num2);
//最大公约数
long long measure(long long x, long long y)
{
	long long z = y;
	while (x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}
int pta1034 ()
{
	string str;
	getline(cin, str);
	long long flag = 0;//空格位置
	for (flag = 0; flag < str.size(); flag++)
	{
		if (str[flag] == ' ')
			break;
	}
	long long a, b, c, d;//四个数
	string str1 = str.substr(0, flag);
	string str2 = str.substr(flag + 1);
	flag = 0;//标记"/"位置
	for (long long i = 0; i < str1.size(); i++)
	{
		if (str1[i] == '/')
		{
			flag = i;
			break;
		}
	}
	a = stoi(str1.substr(0, flag));
	b = stoi(str1.substr(flag + 1));
	for (long long i = 0; i < str2.size(); i++)
	{
		if (str2[i] == '/')
		{
			flag = i;
			break;
		}
	}
	c = stoi(str2.substr(0, flag));
	d = stoi(str2.substr(flag + 1));
	//cout << a << "===" << b << "===" << c << "===" << d << endl;

	long long s1, s2, s3;
	string r1, r2;
	r1 = myNumber(a, b);
	r2 = myNumber(c, d);
	//加法
	s1 = a * d + b * c;//分子
	s2 = b * d;//分母
	s3 = measure(s1, s2);
	cout << r1 << " + " << r2 << " = "<< myNumber(s1 / s3, s2 / s3) << endl;
	//减法
	s1 = a * d - b * c;
	//s2 = b * d;
	s3 = measure(s1, s2);
	cout << r1 << " - " << r2 << " = " << myNumber(s1 / s3, s2 / s3) << endl;
	//乘法
	s1 = a * c;
	s2 = b * d;
	s3 = measure(s1, s2);
	cout << r1 << " * " << r2 << " = " << myNumber(s1 / s3, s2 / s3) << endl;
	//除法
	if (r2 == "0") {
		cout << r1 << " / " << r2 << " = " << "Inf" << endl;
	}
	else
	{
		s1 = a * d;
		s2 = b * c;
		s3 = measure(s1, s2);
		cout << r1 << " / " << r2 << " = " << myNumber(s1 / s3, s2 / s3) << endl;
	}

	return 0;
}
string myNumber(long long num1, long long num2)
{
	string result;
	long long a = abs(num1) / abs(num2);//整数部分
	long long b = abs(num1) % abs(num2);//余数部分
	if ((num1 > 0 && num2 < 0) || (num1 < 0 && num2 > 0))//为负
	{
		if (a != 0)
		{
			result = "(-";
			result.append(to_string(a));
			if (b != 0) {//有余数
				result.append(" ");
				result.append(to_string(b));
				result.append("/");
				result.append(to_string(abs(num2)));
			}
			result.append(")");
			return result;
		}
		else
		{
			result = "(-";
			result.append(to_string(b));
			result.append("/");
			result.append(to_string(abs(num2)));
			result.append(")");
			return result;
		}

	}
	else//为正或0
	{
		if (a != 0)
		{
			result = to_string(a);
			if (b != 0) {//有余数
				result.append(" ");
				result.append(to_string(b));
				result.append("/");
				result.append(to_string(abs(num2)));
			}
			return result;
		}
		else if(b != 0)
		{
			result = to_string(b);
			result.append("/");
			result.append(to_string(abs(num2)));
			return result;
		}
		else
		{
			result = "0";
			return result;
		}

	}
}

