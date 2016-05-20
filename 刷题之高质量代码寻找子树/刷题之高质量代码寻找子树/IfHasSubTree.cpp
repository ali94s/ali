#include<iostream>
using namespace std;
//��������
bool IfHasSubTree(BinaryTreeNode *SrcRoot, BinaryTreeNode *DstRoot);
bool IfSrcTreeHasDstTree(BinaryTreeNode *SrcRoot, BinaryTreeNode *DstRoot);
//Ѱ���Ƿ�������
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_letf;
	BinaryTreeNode *_right;
};
bool IfHasSubTree(BinaryTreeNode *SrcRoot,BinaryTreeNode *DstRoot)
{
	bool result = false;
	//������Դ����Ѱ�Һ�Ŀ�������ڵ���ͬ�Ľڵ�
	if (!SrcRoot&&!DstRoot)
	{
		if (SrcRoot->_value == DstRoot->_value)
			result = IfSrcTreeHasDstTree(SrcRoot, DstRoot);
		if (!result)
			//�൱�ڶ������ı���
			result = IfHasSubTree(SrcRoot->_right, DstRoot);
		if (!result)
			result = IfHasSubTree(SrcRoot->_right, DstRoot);
	}
	return result;
}
bool IfSrcTreeHasDstTree(BinaryTreeNode *SrcRoot, BinaryTreeNode *DstRoot)
{
	//Դ��û���ӽڵ� ��Ŀ���������ӽڵ�
	if (SrcRoot == NULL)
		return false;
	//Դ�������ӽڵ� Ŀ����û��
	if (DstRoot == NULL)
		return true;
	//��������ͬ�Ľڵ�  ���ؼ�
	if (SrcRoot->_value != DstRoot->_value)
		return false;
	else
		//���������ͬ�ڵ� ת��Ϊ���������Ѱ��
		return IfSrcTreeHasDstTree(SrcRoot->_letf, DstRoot->_letf) &&
		IfSrcTreeHasDstTree(SrcRoot->_right, DstRoot->_right);
}

int main()
{
	//no test����
	return 0;
}