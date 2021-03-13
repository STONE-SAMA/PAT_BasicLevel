#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//1051 复数乘法 
//极坐标下的复数乘法法则是 模相乘，幅角相加
int pta1051()
{
	double R1, R2, P1, P2, R, P, A, B;
	scanf_s("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
	R = R1 * R2;
	P = P1 + P2;
	A = R * cos(P);
	B = R * sin(P);
	if (A > -0.005 && A < 0) A = 0;
	printf("%.2f", A);
	if (B > -0.005 && B < 0) printf("+0.00i\n");
	else if (B > 0) printf("+%.2fi\n", B);
	else printf("-%.2fi\n", -B);
	return 0;
}