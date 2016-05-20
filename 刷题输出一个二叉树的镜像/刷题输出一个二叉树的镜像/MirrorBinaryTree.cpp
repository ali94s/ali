#include<iostream>
#include<queue>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
};
//递归实现
void MirrorBinaryTreeNode(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	if (root->_left == NULL&&root->_right == NULL)
		return;
	//交换根的左右子树
	BinaryTreeNode *tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;
	//swap(root->_left, root->_right);
	//交换左子树的左右子树
	if (root->_left)
		MirrorBinaryTreeNode(root->_left);
	//交换右子树的左右子树
	if (root->_right)
		MirrorBinaryTreeNode(root->_right);
}

//非递归实现
void MirrorBinaryTreeNode(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	if (root->_left == NULL&&root->_right == NULL)
		return;
	//使用队列实现
	queue<BinaryTreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		//交换左右子树
		BinaryTreeNode *proot = q.front();
		BinaryTreeNode *tmp = proot->_left;
		proot->_left = proot->_right;
		proot->_right = tmp;
		//出队
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