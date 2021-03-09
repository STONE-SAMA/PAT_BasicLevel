#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//pta 1071
int pta1071()
{
	int T, K;
	cin >> T;
	cin >> K;
	int x = T;
	//bool flag = true;
	for (int i = 0; i < K; i++)
	{	
		int num[4];
		for (int j = 0; j < 4; j++)
		{
			cin >> num[j];
		}
		if (x == 0)
		{
			cout << "Game Over.";
			return 0;
		}
		if (num[2] > x)
		{
			cout << "Not enough tokens.  Total = "<< x << "." << endl;
		}
		else if (num[1] == 0 && num[3] < num[0])//玩家赌小，正确
		{
			x += num[2];
			cout << "Win " << num[2] << "!  Total = " << x << "." << endl;
		}
		else if(num[1] == 1 && num[3] > num[0])//玩家赌大，正确
		{
			x += num[2];
			cout << "Win " << num[2] << "!  Total = " << x << "." << endl;
		}
		else//输钱
		{
			x -= num[2];
			cout << "Lose " << num[2] << ".  Total = " << x << "." << endl;
		}


	}

	return 0;
}