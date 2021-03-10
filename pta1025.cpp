#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 100000
//1025 反转链表
void Reverse_K(struct node Link_node[], int& addre_start, int k);
//单链表结点
struct node
{
	int data;//结点数据
	int next;//下一个结点地址
}Link_node[MAXN];//下标为当前结点地址
int pta1025()
{
	int addre, n, k;//addre为第 1 个结点的地址
	scanf("%d%d%d", &addre, &n, &k);//第一行输入
	int address;//暂存输入的地址
	for (int i = 0; i < n; i++) {
		scanf("%d", &address);//当前结点地址
		//当前结点数据及下一个结点地址
		scanf("%d%d", &Link_node[address].data, &Link_node[address].next);
	}
	int addre_start[2], addre_end;
	addre_start[0] = addre;
	int cou_n = 0;//统计有效的结点个数
	while (addre != -1) {
		cou_n++;
		addre = Link_node[addre].next;
	}
	int flag = 1;//标记第一次反转后的第一个结点(即为整个单链表的第一个结点)
	for (int i = 0; i < cou_n / k; i++) {//需要进行n / k次的反转
		if (flag) {//第一组k个结点特殊处理
			addre_end = addre_start[0];
			Reverse_K(Link_node, addre_start[0], k);
			addre = addre_start[0];
			flag = 0;
		}
		else {
			addre_start[0] = Link_node[addre_end].next;
			addre_start[1] = addre_start[0];//暂存当前待处理k个结点的第一个结点，反转后其将变为最后一个结点
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
//头插法实现链表反转，通过C++的引用&来返回值，addre_start传入为
//当前待处理的一组k个结点中的第一个结点，返回为反转后的第一个结点
void Reverse_K(struct node Link_node[], int& addre_start, int k)
{
	int addre_s = addre_start;//暂存反转前的第一个结点地址
	int p = Link_node[addre_start].next;//p指向下一个结点，防止断链
	int q;//q指向当前待处理结点
	for (int i = 1;i < k; i++) {//k个结点要进行k-1次链的反指向
		q = p;
		p = Link_node[p].next;//p指向下一个结点，防止断链
		Link_node[q].next = addre_start;//反转
		addre_start = q;//当前的第一个结点的地址
	}
	Link_node[addre_s].next = p;//反转后第一个结点变成最后一个结点，让其指向下一组待反转的首结点
}
