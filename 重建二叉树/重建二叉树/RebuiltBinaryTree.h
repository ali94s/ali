#include<iostream>
using namespace std;
//����һ����������ǰ��������������������  �ؽ�������
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
};
BinaryTreeNode *RebuiltBinaryTreeNode(int *Prevorder, int *Inorder, int length);
BinaryTreeNode* BuiltProcess(int *StartPrevorder, int *EndPrevorder,
	int *StartInorder, int *EndInorder);

