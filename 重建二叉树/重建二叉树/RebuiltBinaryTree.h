#include<iostream>
using namespace std;
//给定一个二叉树的前序遍历结果和中序遍历结果  重建二叉树
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
};
BinaryTreeNode *RebuiltBinaryTreeNode(int *Prevorder, int *Inorder, int length);
BinaryTreeNode* BuiltProcess(int *StartPrevorder, int *EndPrevorder,
	int *StartInorder, int *EndInorder);

