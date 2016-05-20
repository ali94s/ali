#include<iostream>
using namespace std;
//函数声明
bool IfHasSubTree(BinaryTreeNode *SrcRoot, BinaryTreeNode *DstRoot);
bool IfSrcTreeHasDstTree(BinaryTreeNode *SrcRoot, BinaryTreeNode *DstRoot);
//寻找是否含有子树
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_letf;
	BinaryTreeNode *_right;
};
bool IfHasSubTree(BinaryTreeNode *SrcRoot,BinaryTreeNode *DstRoot)
{
	bool result = false;
	//首先在源树中寻找和目标树根节点相同的节点
	if (!SrcRoot&&!DstRoot)
	{
		if (SrcRoot->_value == DstRoot->_value)
			result = IfSrcTreeHasDstTree(SrcRoot, DstRoot);
		if (!result)
			//相当于二叉树的遍历
			result = IfHasSubTree(SrcRoot->_right, DstRoot);
		if (!result)
			result = IfHasSubTree(SrcRoot->_right, DstRoot);
	}
	return result;
}
bool IfSrcTreeHasDstTree(BinaryTreeNode *SrcRoot, BinaryTreeNode *DstRoot)
{
	//源树没有子节点 而目标数还有子节点
	if (SrcRoot == NULL)
		return false;
	//源树还有子节点 目标数没有
	if (DstRoot == NULL)
		return true;
	//遇到不相同的节点  返回假
	if (SrcRoot->_value != DstRoot->_value)
		return false;
	else
		//如果遇到相同节点 转换为子问题继续寻找
		return IfSrcTreeHasDstTree(SrcRoot->_letf, DstRoot->_letf) &&
		IfSrcTreeHasDstTree(SrcRoot->_right, DstRoot->_right);
}

int main()
{
	//no test！！
	return 0;
}