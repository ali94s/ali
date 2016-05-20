#include<iostream>
using namespace std;

struct ListNode
{
	int _value;
	ListNode *_next;
};

//����˼·  ʱ�临�Ӷ���O(n)
//void DeleteListNode(ListNode **ListHead, ListNode *del)
//{
//	ListNode *tmp = *ListHead;
//	//ɾ������ͷ���
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
//	//û������ڵ�
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


//ʱ�临�Ӷ���O(1)�Ľⷨ

void DeleteListNode(ListNode **ListHead, ListNode *del)
{

	//Ҫɾ������β�ڵ�
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
	//ֻ��һ���ڵ������
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

