#include<iostream>
using namespace std;
#include<queue>
//二叉树的层序输出
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;

};
void SequencePrintBinaryTree(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	//层序输出借助一个队列来实现(先进先出)
	queue<BinaryTreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		BinaryTreeNode *tmp = q.front();
		cout << tmp->_value << " ";
		q.pop();
		//层序遍历是按层从上到下每层从左向右访问
		//所以先让根节点入队  遍历完后入左孩子和有孩子
		if (tmp->_left != NULL)
			q.push(tmp->_left);
		if (tmp->_right != NULL)
			q.push(tmp->_right);
	}
}




int main()
{

	return 0;
}