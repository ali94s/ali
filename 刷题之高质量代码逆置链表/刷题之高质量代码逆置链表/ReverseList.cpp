#include<iostream>
using namespace std;
#include<list>
//将一个链表进行逆置
struct ListNode
{
	int _value;
	ListNode *_next;
};

//将一个链表进行逆置
ListNode *ReverseList(ListNode *phead)
{
	if (!phead)
		return NULL;
	//只有一个头结点
	if (phead->_next == NULL)
	{
		return phead;
	}
	ListNode *PrevNode = NULL;
	ListNode *CurNode = phead;
	ListNode *NextNode = CurNode->_next;
	while (NextNode->_next)
	{
		NextNode = CurNode->_next;
		CurNode->_next = PrevNode;
		PrevNode = CurNode;
		CurNode = NextNode;
	}
	NextNode->_next = CurNode;
	return NextNode;

}




//合并两个排序的链表  使得排序后的链表依然是排序的(假设是升序)
ListNode *MergeList(ListNode *phead1, ListNode *phead2)
{
	if (!phead1)
	{
		return phead2;
	}
	if (!phead2)
	{
		return phead1;
	}
	//新的头结点
	ListNode *NewHead = NULL;
	if (phead1->_value <= phead2->_value)
	{
		//如果phead1的头结点小雨等于phead2的头结点
		//新的头结点指向phead1 然后从phead1之后与phead2比较
		NewHead = phead1;
		NewHead->_next = MergeList(phead1->_next, phead2);
	}
	else
	{
		NewHead = phead2;
		NewHead->_next = MergeList(phead1, phead2->_next);
	}

	return NewHead;
}

int main()
{
	return 0;
}