#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 100000
//1025 ��ת����
void Reverse_K(struct node Link_node[], int& addre_start, int k);
//��������
struct node
{
	int data;//�������
	int next;//��һ������ַ
}Link_node[MAXN];//�±�Ϊ��ǰ����ַ
int pta1025()
{
	int addre, n, k;//addreΪ�� 1 �����ĵ�ַ
	scanf("%d%d%d", &addre, &n, &k);//��һ������
	int address;//�ݴ�����ĵ�ַ
	for (int i = 0; i < n; i++) {
		scanf("%d", &address);//��ǰ����ַ
		//��ǰ������ݼ���һ������ַ
		scanf("%d%d", &Link_node[address].data, &Link_node[address].next);
	}
	int addre_start[2], addre_end;
	addre_start[0] = addre;
	int cou_n = 0;//ͳ����Ч�Ľ�����
	while (addre != -1) {
		cou_n++;
		addre = Link_node[addre].next;
	}
	int flag = 1;//��ǵ�һ�η�ת��ĵ�һ�����(��Ϊ����������ĵ�һ�����)
	for (int i = 0; i < cou_n / k; i++) {//��Ҫ����n / k�εķ�ת
		if (flag) {//��һ��k��������⴦��
			addre_end = addre_start[0];
			Reverse_K(Link_node, addre_start[0], k);
			addre = addre_start[0];
			flag = 0;
		}
		else {
			addre_start[0] = Link_node[addre_end].next;
			addre_start[1] = addre_start[0];//�ݴ浱ǰ������k�����ĵ�һ����㣬��ת���佫��Ϊ���һ�����
			Reverse_K(Link_node, addre_start[0], k);
			Link_node[addre_end].next = addre_start[0];
			addre_end = addre_start[1];
		}
	}
	while (addre != -1) {
		if (Link_node[addre].next != -1) {
			printf("%05d %d %05d\n", addre, Link_node[addre].data, Link_node[addre].next);
		}
		else {
			printf("%05d %d %d\n", addre, Link_node[addre].data, Link_node[addre].next);
		}
		addre = Link_node[addre].next;
	}
	return 0;
}
//ͷ�巨ʵ������ת��ͨ��C++������&������ֵ��addre_start����Ϊ
//��ǰ�������һ��k������еĵ�һ����㣬����Ϊ��ת��ĵ�һ�����
void Reverse_K(struct node Link_node[], int& addre_start, int k)
{
	int addre_s = addre_start;//�ݴ淴תǰ�ĵ�һ������ַ
	int p = Link_node[addre_start].next;//pָ����һ����㣬��ֹ����
	int q;//qָ��ǰ��������
	for (int i = 1;i < k; i++) {//k�����Ҫ����k-1�����ķ�ָ��
		q = p;
		p = Link_node[p].next;//pָ����һ����㣬��ֹ����
		Link_node[q].next = addre_start;//��ת
		addre_start = q;//��ǰ�ĵ�һ�����ĵ�ַ
	}
	Link_node[addre_s].next = p;//��ת���һ����������һ����㣬����ָ����һ�����ת���׽��
}
