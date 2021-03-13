#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
//1054 求平均值
int pta1054()
{
	int n;
	cin >> n;
	int count = 0;
	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		char str[50];
		cin >> str;
		double temp = 0.0;
		sscanf_s(str, "%lf", &temp);
		char arr[50];
		sprintf_s(arr, "%.2f", temp);
		int flag = 0;
		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] != arr[j])
				flag = 1;
		}
		if (flag == 1 || temp < -1000 || temp > 1000) {
			printf("ERROR: %s is not a legal number\n", str);
			continue;
		}
		else {
			sum += temp;
			count++;
		}

	}
	if (count == 1)
		printf("The average of 1 number is %.2f", sum);
	else if (count > 1)
		printf("The average of %d numbers is %.2f", count, sum / count);
	else
		printf("The average of 0 numbers is Undefined");

	return 0;
}
