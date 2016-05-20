#include<iostream>
using namespace std;
//找链表中倒数第k个节点
struct ListNode
{
	int _value;
	ListNode *_next;
};
ListNode *FindKNode(ListNode **phead,int k)
{
	//倒数第k个节点就是正着数第n-(k-1)个节点
	//我们可以通过遍历两次链表  第一次确定链表节点个数  第二次找倒数第k个节点
	//下面的方法只要遍历一遍即可
	if (*phead == NULL || k == 0)  //有效性的判断
		return NULL;
	ListNode *p1 = *phead;
	ListNode *p2 = *phead;
	int i = 0;
	while (p1->_next)
	{
		if (i < k - 1)
		{
			//首先让第一个指针先走k-1步
			p1 = p1->_next;
			i++;
		}
		//然后同时移动两个指针 
		//当第一个指针刚好到尾节点的时候第二个指针就在倒数第k个节点处
		else
		{
			p1 = p1->_next;
			p2 = p2->_next;
		}
	}
	//如果k比所有节点个数还大
	if (i < k - 1)
	{
		return NULL;
	}
	return p2;
}
