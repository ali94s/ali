#include<iostream>
using namespace std;
#include<vector>

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
};
void FindEveryPath(BinaryTreeNode *root, int expectedSum, vector<int> &path, int currentSum);
void FindPath(BinaryTreeNode *root, int expectedSum);

void FindPath(BinaryTreeNode *root, int expectedSum)
{
	if (!root)
		return;
	vector<int> path;
	int currentSum = 0;
	FindEveryPath(root,expectedSum,path,currentSum);
}
//�������ô������vector����
void FindEveryPath(BinaryTreeNode *root,int expectedSum,vector<int> &path,int currentSum)
{
	currentSum += root->_value;
	path.push_back(root->_value);
	//�ҵ���Ҷ�ڵ�������ڵĺ͸պú�������ֵ��� ���ӡ����·��
	bool isLeaf = root->_left == NULL&&root->_right == NULL;
	if (isLeaf&&currentSum == expectedSum)
	{
		cout << "one path:";
		//ʹ�õ�����
		vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); iter++)
		{
			cout << *iter << "->";
		}
		cout << endl;
	}
	if (root->_left != NULL)
		FindEveryPath(root->_left, expectedSum, path, currentSum);
	if (root->_right != NULL)
		FindEveryPath(root->_right, expectedSum, path, currentSum);
	path.pop_back();
}

int main()
{

	return 0;
}