#include<iostream>
using namespace std;

//����һ����������������ת��Ϊһ�������˫������
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
};
void CreateDList(BinaryTreeNode *root, BinaryTreeNode **tail);
BinaryTreeNode* SearchBinaryTreeToDList(BinaryTreeNode *root)
{
	//ָ��˫�������β�ڵ�
	BinaryTreeNode *tail = NULL;
	CreateDList(root, &tail);
	BinaryTreeNode *pheadOfList = tail;
	//��Ҫ����˫�������ͷ���
	while (pheadOfList != NULL&&pheadOfList->_left != NULL)
		pheadOfList = pheadOfList->_left;
	return pheadOfList;
}
//����������Ľ��
//�����ҵ������ӽڵ���Ϊ˫�������ͷ���
//ԭ���ڵ�ָ����������ָ������ָ��ǰһ���ڵ�
//ԭ���ڵ�ָ����������ָ������ָ���һ���ڵ�
void CreateDList(BinaryTreeNode *root, BinaryTreeNode **tail)
{
	//�������ת��
	if (root == NULL)
		return;
	//��¼��ǰ�ڵ�
	BinaryTreeNode *pcurrent = root;
	//Ѱ������ڵ�  ����˫�������ͷ���
	if (pcurrent->_left != NULL)
		CreateDList(pcurrent->_left, tail);

	pcurrent->_left = *tail;
	if (*tail != NULL)
		(*tail)->_right = pcurrent;
	*tail = pcurrent;


	if (pcurrent->_right != NULL)
		CreateDList(pcurrent->_right, tail);
}
int main()
{


	return 0;
}