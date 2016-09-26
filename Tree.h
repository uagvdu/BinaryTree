#include<iostream>
#include<queue>
using namespace std;

template <class T>
struct BNode
{
	T _value;
	BNode<T>* _leftTree;
	BNode<T>* _rightTree;
	BNode(T value = T())
		: _value(value)
		, _leftTree(NULL)
		, _rightTree(NULL)
	{}
};
template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:_root(NULL)
		, _sz(0)
	{}
	BinaryTree(T* a, size_t sz, const T& invalue)
	{
		size_t id = 0;
		_root = CreatTree(a, sz, invalue, id);
	}
	~BinaryTree()
	{}
public:
	void PrevOrder()
	{
		_prevorder(_root);
	}
	void InOrder()
	{
		_inorder(_root);
	}
	void PostOrder()
	{
		_postorder(_root);
	}
	/*void LevelOrder()
	{
		
		
		_levelorder(_root);
	}*/

	void  Size()
	{
		cout << _size(_root) << endl;
	}

	void Depth()
	{
		cout << _depth(_root) << endl;
	}
protected:
	BNode<T>* CreatTree(T*& a, size_t sz, const T& invalue, size_t& index)
	{
		if (a == NULL || a[index] == invalue||index >= sz)
		{
			return NULL;
		}
		else
		{
			if (index < sz)
			{
				BNode<T>* cur = new BNode<T>(a[index]);
				index++;
				cur->_leftTree = CreatTree(a, sz, invalue, index);
				index++;
				cur->_rightTree = CreatTree(a, sz, invalue, index);
				return cur;
			}

		}
	}

	void _prevorder( BNode<T>*& root)
	{
		if (root == NULL)
		{
			return   ;
		}
		else
		{
			cout << root->_value << " ";
			_prevorder(root->_leftTree);
			_prevorder(root->_rightTree);
		}
	}

	void _inorder( BNode<T>*& root)
	{
		BNode<T>* cur = root;
		if (cur == NULL)
		{
			return  ;

		}
		else
		{
			_inorder(cur->_leftTree);
			cout << cur->_value<<" " ;
			_inorder(cur->_rightTree);
		}
	}

	void _postorder(BNode<T>* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			_postorder(root->_leftTree);
			_postorder(root->_rightTree);
			cout << root->_value << " ";
		}
	}

	size_t _size(BNode<T>* root)
	{
		size_t count = 0;
		if (root == NULL)
			return 0;
		else
		{
			count++;
			count += _size(root->_leftTree);
			count += _size(root->_rightTree);
			return count;
		}
	}
	size_t _depth(BNode<T>* root)
	{
		size_t count = 1;
		size_t dp = 1;
		if (root == NULL)
			return 0;
		else
		{
			count += _depth(root->_leftTree);
			dp += _depth(root->_rightTree);
			
			return (dp > count ?dp :count);
		}
	}

protected:
	BNode<T>* _root;
	size_t _sz;
	size_t _invalue;
};
void test() //前中后层序遍历
{
	int arr[] = {1, 2, 3, '#',7, '#', 4, '#', '#', 5, 6 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	BinaryTree<int> bt(arr, sz, '#');
	bt.PrevOrder();//1237456
	cout << endl;
	bt.InOrder();//3742651
	cout << endl;
	bt.PostOrder();
	cout << endl;
	bt.Size();
	cout << endl;
	bt.Depth();
	cout << endl;
}
