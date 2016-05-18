#include<iostream>
using namespace std;

//输入一个二叉搜索树将它转换为一个有序的双向链表
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
};
void CreateDList(BinaryTreeNode *root, BinaryTreeNode **tail);
BinaryTreeNode* SearchBinaryTreeToDList(BinaryTreeNode *root)
{
	//指向双向链表的尾节点
	BinaryTreeNode *tail = NULL;
	CreateDList(root, &tail);
	BinaryTreeNode *pheadOfList = tail;
	//需要返回双向链表的头结点
	while (pheadOfList != NULL&&pheadOfList->_left != NULL)
		pheadOfList = pheadOfList->_left;
	return pheadOfList;
}
//按中序遍历的结果
//首先找到最左子节点作为双向链表的头结点
//原来节点指向左子树的指针现在指向前一个节点
//原来节点指向右子树的指针现在指向后一个节点
void CreateDList(BinaryTreeNode *root, BinaryTreeNode **tail)
{
	//中序遍历转换
	if (root == NULL)
		return;
	//记录当前节点
	BinaryTreeNode *pcurrent = root;
	//寻找最左节点  就是双向链表的头结点
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