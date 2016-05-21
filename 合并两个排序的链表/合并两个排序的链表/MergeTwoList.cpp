#include<iostream>
using namespace std;
//合并两个排序的链表  使得新的链表也是排序的
struct ListNode
{
	int _value;
	ListNode *_next;
	ListNode(int value) :_value(value), _next(NULL)
	{}
};

ListNode* MergeTwoList(ListNode *phead1, ListNode *phead2)
{
	//边界条件的考虑
	if (phead1 == NULL)
		return phead2;
	if (phead2 == NULL)
		return phead1;


	//创建一个节点  每次将链表中小的节点给它
	ListNode *NewHead = NULL;


	if (phead1->_value < phead2->_value)
	{
		//拿到小的节点
		NewHead = phead1;
		//递归进去找下一个小的节点    
		NewHead->_next = MergeTwoList(phead1->_next, phead2);
	}
	else
	{
		NewHead = phead2;
		NewHead->_next = MergeTwoList(phead1, phead2->_next);
	}
	return NewHead;
}

int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(4);
	ListNode *p4 = new ListNode(6);
	p1->_next = p2;
	p2->_next = p3;
	p3->_next = p4;
	p4->_next = NULL;
	ListNode *s1 = new ListNode(3);
	ListNode *s2 = new ListNode(5);
	ListNode *s3 = new ListNode(7);
	ListNode *s4 = new ListNode(9);
	s1->_next = s2;
	s2->_next = s3;
	s3->_next = s4;
	s4->_next = NULL;
	ListNode *newhead;
	newhead = MergeTwoList(p1, s1);
	return 0;
}