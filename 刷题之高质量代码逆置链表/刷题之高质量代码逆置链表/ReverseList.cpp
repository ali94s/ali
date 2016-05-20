#include<iostream>
using namespace std;
#include<list>
//��һ�������������
struct ListNode
{
	int _value;
	ListNode *_next;
};

//��һ�������������
ListNode *ReverseList(ListNode *phead)
{
	if (!phead)
		return NULL;
	//ֻ��һ��ͷ���
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




//�ϲ��������������  ʹ��������������Ȼ�������(����������)
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
	//�µ�ͷ���
	ListNode *NewHead = NULL;
	if (phead1->_value <= phead2->_value)
	{
		//���phead1��ͷ���С�����phead2��ͷ���
		//�µ�ͷ���ָ��phead1 Ȼ���phead1֮����phead2�Ƚ�
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