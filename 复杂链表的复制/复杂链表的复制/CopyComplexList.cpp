#include<iostream>
using namespace std;

struct ComplexListNode
{
	ComplexListNode(int value=0) :data(value), next(NULL), random(NULL)
	{}
	int data;
	ComplexListNode *next;
	ComplexListNode *random;
};
void CloneNode(ComplexListNode *phead);
void LinkRandom(ComplexListNode *phead);
ComplexListNode *SeparateList(ComplexListNode *phead);
ComplexListNode *CopyComplexList(ComplexListNode *phead)
{
	if (phead == NULL)
		return NULL;
	CloneNode(phead);
	LinkRandom(phead);
	return SeparateList(phead);
}
void CloneNode(ComplexListNode *phead)
{
	ComplexListNode *node = phead;
	while (node != NULL)
	{
		//创建一个新的节点
		ComplexListNode *newnode = new ComplexListNode();

		//新节点是现在的节点的拷贝
		newnode->data = node->data;
		newnode->next = node->next;
		newnode->random == NULL;

		node->next = newnode;
		node = newnode->next;
	}
}

void LinkRandom(ComplexListNode *phead)
{
	ComplexListNode *tmp = phead;
	while (tmp != NULL)
	{
		//当random为空时一定要单独处理  要不就会访问到空指针导致程序崩溃
		if (tmp->random == NULL)
			tmp->next->random = NULL;
		//赋值的节点的随机指针是指向原节点的随机指针指向的下一个节点
		else
			tmp->next->random = tmp->random->next;
		tmp = tmp->next->next;
	
	}
}

ComplexListNode *SeparateList(ComplexListNode *phead)
{
	ComplexListNode *newhead = phead->next;
	ComplexListNode *newtmp = newhead;
	ComplexListNode *tmp = phead;
	while (newtmp->next != NULL)
	{
		tmp->next = newtmp->next;
		tmp = tmp->next;
		newtmp->next = tmp->next;
		newtmp = newtmp->next;
	}
	tmp->next = NULL;
	return newhead;
}
int main()
{
	ComplexListNode *p1 = new ComplexListNode(1);
	ComplexListNode *p2 = new ComplexListNode(2);
	ComplexListNode *p3 = new ComplexListNode(3);
	ComplexListNode *p4 = new ComplexListNode(4);
	ComplexListNode *p5 = new ComplexListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	p1->random = p3;
	p2->random = p1;
	p3->random = NULL;
	p4->random = p2;
	p5->random = p1;
	ComplexListNode *newheap = CopyComplexList(p1);
	return 0;
}