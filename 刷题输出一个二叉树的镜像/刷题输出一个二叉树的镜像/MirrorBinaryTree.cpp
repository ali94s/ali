#include<iostream>
#include<queue>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
};
//�ݹ�ʵ��
void MirrorBinaryTreeNode(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	if (root->_left == NULL&&root->_right == NULL)
		return;
	//����������������
	BinaryTreeNode *tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;
	//swap(root->_left, root->_right);
	//��������������������
	if (root->_left)
		MirrorBinaryTreeNode(root->_left);
	//��������������������
	if (root->_right)
		MirrorBinaryTreeNode(root->_right);
}

//�ǵݹ�ʵ��
void MirrorBinaryTreeNode(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	if (root->_left == NULL&&root->_right == NULL)
		return;
	//ʹ�ö���ʵ��
	queue<BinaryTreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		//������������
		BinaryTreeNode *proot = q.front();
		BinaryTreeNode *tmp = proot->_left;
		proot->_left = proot->_right;
		proot->_right = tmp;
		//����
		q.pop();
		if (proot->_left)
			q.push(proot->_left);
		if (proot->_right)
			q.push(proot->_right);
	}
}
int main()
{

	return 0;
}