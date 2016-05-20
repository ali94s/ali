#include"RebuiltBinaryTree.h"



//重建二叉树
BinaryTreeNode *RebuiltBinaryTreeNode(int *Prevorder, int *Inorder, int length)
{
	if (Prevorder == NULL || Inorder == NULL || length <= 0)
		return NULL;
	else
		return BuiltProcess(Prevorder, Prevorder + length - 1, Inorder, Inorder + length - 1);
}



BinaryTreeNode* BuiltProcess(int *StartPrevorder, int *EndPrevorder,
	int *StartInorder, int *EndInorder)
{
	int rootvalue = StartPrevorder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->_value = rootvalue;
	root->_right = root->_left = NULL;


	int *rootInorder = StartInorder;
	while (*rootInorder != rootvalue&&rootInorder <= EndInorder)
		rootInorder++;
	int leftlength = rootInorder - StartInorder;
	int *leftPrevoderEnd = StartPrevorder + leftlength;
	if (leftlength > 0)
	{
		//构建左树
		root->_left = BuiltProcess(StartPrevorder + 1, leftPrevoderEnd, StartInorder, rootInorder - 1);
	}
	if (leftlength < EndPrevorder - StartPrevorder)
	{
		//构建右树
		root->_right = BuiltProcess(leftPrevoderEnd + 1, EndPrevorder, rootInorder + 1, EndInorder);
	}
	return root;
}
int main()
{
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	RebuiltBinaryTreeNode(pre, in, sizeof(pre) / sizeof(pre[1]));
}