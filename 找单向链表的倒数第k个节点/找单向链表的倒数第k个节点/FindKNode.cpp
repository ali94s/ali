#include<iostream>
using namespace std;
//�������е�����k���ڵ�
struct ListNode
{
	int _value;
	ListNode *_next;
};
ListNode *FindKNode(ListNode **phead,int k)
{
	//������k���ڵ������������n-(k-1)���ڵ�
	//���ǿ���ͨ��������������  ��һ��ȷ������ڵ����  �ڶ����ҵ�����k���ڵ�
	//����ķ���ֻҪ����һ�鼴��
	if (*phead == NULL || k == 0)  //��Ч�Ե��ж�
		return NULL;
	ListNode *p1 = *phead;
	ListNode *p2 = *phead;
	int i = 0;
	while (p1->_next)
	{
		if (i < k - 1)
		{
			//�����õ�һ��ָ������k-1��
			p1 = p1->_next;
			i++;
		}
		//Ȼ��ͬʱ�ƶ�����ָ�� 
		//����һ��ָ��պõ�β�ڵ��ʱ��ڶ���ָ����ڵ�����k���ڵ㴦
		else
		{
			p1 = p1->_next;
			p2 = p2->_next;
		}
	}
	//���k�����нڵ��������
	if (i < k - 1)
	{
		return NULL;
	}
	return p2;
}
