#include<iostream>
using namespace std;

struct ListNode
{
	int _value;
	ListNode *_next;
};

//常规思路  时间复杂度是O(n)
//void DeleteListNode(ListNode **ListHead, ListNode *del)
//{
//	ListNode *tmp = *ListHead;
//	//删除的是头结点
//	if (del == *ListHead)
//	{
//		*ListHead = (*ListHead)->_next;
//		delete del;
//		del = NULL;
//	}
//	while (tmp->_next != del&&tmp->_next)
//	{
//		tmp = tmp->_next;
//	}
//	//没有这个节点
//	if (tmp->_next = NULL)
//	{
//		cout << "not have" << endl;
//	}
//	else
//	{
//		tmp->_next = del->_next;
//		delete del;
//		del = NULL;
//	}
//}
//


//时间复杂度是O(1)的解法

void DeleteListNode(ListNode **ListHead, ListNode *del)
{

	//要删除的是尾节点
	if (del->_next == NULL)
	{
		ListNode *cur = *ListHead;
		while (cur->_next != del&&cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = NULL;
		delete del;
		del = NULL;
	}
	//只有一个节点的链表
	if ((*ListHead)->_next == NULL)
	{
		if (*ListHead == del)
		{
			delete del;
			del = NULL;
		}
		else
		{
			cout << "not have" << endl;
		}
	}
	else
	{
		ListNode *tmp = del->_next;
		del->_next = tmp->_next;
		del->_value = tmp->_value;
		delete tmp;
		tmp = NULL;
	}

}

