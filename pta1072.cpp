#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//pta1072 开学寄语

int pta1072()
{
	int N, M;
	cin >> N;//学生人数
	cin >> M;//需要被查缴的物品种类数
	int* p;
	p = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> p[i];
	}
	int num_stu = 0;//存在问题的学生的总人数
	int num_thing = 0;//被查缴物品的总数
	for (int i = 0; i < N; i++)
	{
		bool flag = false;//学生是否携带违禁品，false为未携带
		string name;//学生名
		cin >> name;
		int num;//物品总数
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int temp;
			cin >> temp;
			for (int k = 0; k < M; k++)
			{
				if (temp == p[k])
				{
					if (flag == false && num_stu == 0)//第一个违纪学生无需换行
					{
						cout << name << ":";
						num_stu++;
					}
					else if(flag == false && num_stu != 0)
					{
						cout << endl;
						cout << name << ":";
						num_stu++;
					}					
					flag = true;
					cout << " " << temp;
					num_thing++;
					break;
				}
			}
		}
	}
	cout << endl;
	cout << num_stu << " " << num_thing;

	delete[]p;
	return 0;
}


