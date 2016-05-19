#ifndef _BINARYTREE_HPP
#define _BINARYTREE_HPP
#include<iostream>
#include<queue>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	T _value;
	BinaryTreeNode<T> *_left;
	BinaryTreeNode<T> *_right;
	BinaryTreeNode(const T &value = 0) :_value(value), _left(NULL), _right(NULL)
	{}
};
template<class T>
class BinaryTree
{
public:
	//Ĭ�Ϲ���
	BinaryTree() :_root(NULL)
	{}
	//���캯��	����Ϊ����Ӧ����const����
	BinaryTree(const T *a, const T &invalid)
	{
		_root = _CreateBinaryTree(a,invalid);
	}
	//��������
	BinaryTree(const BinaryTree<T> &b)
	{
		_root = _CopyBinaryTree(b._root);
	}
	//��ֵ�����(�����ִ�ʽд��)
	BinaryTree<T>& operator=(BinaryTree<T> b)
	{
		swap(_root, b._root);
		return _root;
	}
	//��������
	~BinaryTree()
	{
		_Destroy(_root);
		_root = NULL;
	}





public:
	//�������ı���
	//ǰ�����
	void PrevOrder()
	{
		_PrevOrder(_root);
	}
	//�������
	void InOrder()
	{
		_InOrder(_root);
	}
	//�������
	void PostOrder()
	{
		_PostOrder(_root);
	}
	//�������
	void LevelOrder()
	{
		_LevelOrder(_root);
	}
	//�������ڵ����
	size_t Size()
	{
		return _Size(_root);
	}
	//�����������
	size_t Depth()
	{
		return _Depth(_root);
	}
	//������Ҷ�ӽڵ�ĸ���
	size_t LeafSize()
	{
		return _LeafSize(_root);
	}
protected:

	//ǫ������ݹ�д��
	void _PrevOrder(BinaryTreeNode<T> *root)
	{
		if (root != NULL)
		{
			_Visit(root);
			_PrevOrder(root->_left);
			_PrevOrder(root->_right);
		}
	}
	//��������ݹ�д��
	void _InOrder(BinaryTreeNode<T> *root)
	{
		if (root != NULL)
		{
			_InOrder(root->_left);
			_Visit(root);
			_InOrder(root->_right);
		}
	}
	//��������ݹ�д��
	void _PostOrder(BinaryTreeNode<T> *root)
	{
		if (root != NULL)
		{
			BinaryTreeNode<T> *cur = root;
			_PostOrder(root->_left);
			if (cur->_right!=NULL)
				_PostOrder(root->_right);
			_Visit(root);
		}
	}
	//��һ��������������ɲ������
	void _LevelOrder(BinaryTreeNode<T> *root)
	{
		if (root != NULL)
		{
			queue<BinaryTreeNode<T> *>q;
			q.push(root);
			while (!q.empty())
			{
				BinaryTreeNode<T> *tmp = q.front();
				_Visit(tmp);
				q.pop();
				if (tmp->_left != NULL)
					q.push(tmp->_left);
				if (tmp->_right != NULL)
					q.push(tmp->_right);
			}
		}
	}

	size_t _Size(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
			return 0;
		//�������������ڵ�ĸ����ټ��ϸ��ڵ�
		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	size_t _Depth(BinaryTreeNode<T> *root)
	{
		if (root == NULL)
			return 0;
		size_t ld;
		size_t rd;
		ld = _Depth(root->_left);
		rd = _Depth(root->_right);
		//�����������֮���ټӸ��ڵ�
		return (ld > rd ? ld : rd) + 1;
	}

	size_t _LeafSize(BinaryTreeNode<T> *root)
	{
		//��������0
		if (root == NULL)
			return 0;
		//����û���ӽڵ㷵��1
		if (root->_left == NULL&&root->_right == NULL)
			return 1;
		return _LeafSize(root->_left) + _LeafSize(root->_right);
	}


	void _Visit(BinaryTreeNode<T> *node)
	{
		cout << node->_value << " ";
	}
protected:
	//���ַ��������������
	BinaryTreeNode<T> *_CreateBinaryTree(const T* &s,const T &invalid)
	{
		BinaryTreeNode<T> *NewNode = NULL;
		if ((*s) != '\0' && (*s) != invalid)
		{
			NewNode = new BinaryTreeNode<T>(*s);
			NewNode->_left = _CreateBinaryTree(++s,invalid);
			NewNode->_right = _CreateBinaryTree(++s,invalid);
		}
		return NewNode;
	}


	//��������
	BinaryTreeNode<T> *_CopyBinaryTree(BinaryTreeNode<T> *s)
	{
		BinaryTreeNode<T> *NewNode = NULL;
		if (s != NULL)
		{
			NewNode = new BinaryTreeNode<T>(s->_value);
			NewNode->_left = _CopyBinaryTree(s->_left);
			NewNode->_right = _CopyBinaryTree(s->_right);
		}
		return NewNode;
	}
	//�����������ٶ�����
	void _Destroy(BinaryTreeNode<T>* &root)
	{
		if (root != NULL)
		{
			_Destroy(root->_left);
			_Destroy(root->_right);
		}
		delete root;
	}
private:
	BinaryTreeNode<T> *_root;
};
#endif  //_BINARYTREE_HPP