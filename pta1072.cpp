#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//pta1072 ��ѧ����

int pta1072()
{
	int N, M;
	cin >> N;//ѧ������
	cin >> M;//��Ҫ����ɵ���Ʒ������
	int* p;
	p = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> p[i];
	}
	int num_stu = 0;//���������ѧ����������
	int num_thing = 0;//�������Ʒ������
	for (int i = 0; i < N; i++)
	{
		bool flag = false;//ѧ���Ƿ�Я��Υ��Ʒ��falseΪδЯ��
		string name;//ѧ����
		cin >> name;
		int num;//��Ʒ����
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int temp;
			cin >> temp;
			for (int k = 0; k < M; k++)
			{
				if (temp == p[k])
				{
					if (flag == false && num_stu == 0)//��һ��Υ��ѧ�����軻��
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


