#include<iostream>
using namespace std;
#include<queue>
//�������Ĳ������
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
	//�����������һ��������ʵ��(�Ƚ��ȳ�)
	queue<BinaryTreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		BinaryTreeNode *tmp = q.front();
		cout << tmp->_value << " ";
		q.pop();
		//��������ǰ�����ϵ���ÿ��������ҷ���
		//�������ø��ڵ����  ������������Ӻ��к���
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