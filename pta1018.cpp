#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//1018 ���Ӽ�����
int match(char a, char b)//1Ϊ��ʤ,0Ϊƽ��-1Ϊ�׸�
{
	if (a =='C' && b=='J')
	{
		return 1;
	}
	else if (a == 'C' && b == 'B')
	{
		return -1;
	}
	else if (a == 'C' && b == 'C')
	{
		return 0;
	}
	else if (a == 'J' && b == 'C')
	{
		return -1;
	}
	else if (a == 'J' && b == 'J')
	{
		return 0;
	}
	else if (a == 'J' && b == 'B')
	{
		return 1;
	}
	else if (a == 'B' && b == 'C')
	{
		return 1;
	}
	else if (a == 'B' && b == 'J')
	{
		return -1;
	}
	else if (a == 'B' && b == 'B')
	{
		return 0;
	}
}
int findMax(int num[3])//0:B  1:C  2:J
{
	int temp = 0;
	if (num[1] > num[temp])
	{
		temp = 1;
	}
	else if(num[2] > num[temp])
	{
		temp = 2;
	}
	return temp;
}

int pta1018()
{
	int n;
	scanf_s("%d", &n);
	int a[3] = { 0,0,0 };//��¼�׵�ʤ��ƽ��������ֻ���������
	int b[3] = { 0,0,0 };//�׳�B��C��J��ʤ��
	int c[3] = { 0,0,0 };//�ҳ�B��C��J��ʤ��
	for (int i = 0; i < n; i++)
	{
		char m, n;
		cin >> m >> n;//�ס�������
		int result = match(m, n);
		if (result == 1)//��ʤ
		{
			a[0]++;
			if (m == 'B')
				b[0]++;
			else if (m == 'C')
				b[1]++;
			else
				b[2]++;
		}
		else if(result == 0)//ƽ
		{
			a[1]++;
		}
		else//�׸�
		{
			a[2]++;
			if (n == 'B')
				c[0]++;
			else if (n == 'C')
				c[1]++;
			else
				c[2]++;
		}

	}
	printf_s("%d %d %d\n", a[0], a[1], a[2]);
	printf_s("%d %d %d\n", a[2], a[1], a[0]);
	char k[3] = { 'B','C','J' };
	int r1,r2;
	r1 = findMax(b);
	r2 = findMax(c);
	printf("%c %c", k[r1], k[r2]);

	return 0;
}
