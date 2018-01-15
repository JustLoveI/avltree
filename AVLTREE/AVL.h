#ifndef __AVL__H
#define __AVL__H
#endif

template<class T>
struct node
{
	node(){ leftChild = NULL; rightChild = NULL; parent = NULL; nLevel = 0; }
	T* leftChild;
	T* rightChild;
	T* parent;
	T data;
	int nLevel;
};
template<class T>
class AVL_TREE
{
public:
	AVL_TREE(){ root = allocate(); }
	typedef node<T> value_type;
	typedef node<T>* iterator;
	typedef node<T>& reference;
	typedef size_t size_type;

	iterator root;
	iterator allocate()
	{
		iterator tmp = new node();
		tmp->data = T(0);
		return tmp;
	}
	iterator allocate(const T &item)
	{
		iterator tmp = new node();
		tmp->data = item;
		return tmp;
	}
	/*
	void push(const T &item)
	{
		iterator newItem = allocate(item);
		iterator curItem = root;
		while (true)
		{
			if (curItem->data <= newItem->data)
			{
				if (curItem->rightChild == NULL)
				{
					curItem->rightChild = newItem;
					break;
				}
				else
					curItem = curItem->rightChild;
			}
			else
			{
				if (curItem->leftChild == NULL)
				{
					curItem->leftChild = newItem;
					break;
				}
				else
					curItem = curItem->rightChild;
			}
		}
	}
	void dfs(iterator item)
	{
		printf("%d\n", item->data);
		if (item->leftChild == NULL && item->leftChild == NULL)
			return;
		if (item->leftChild)
		{
			printf("%c",'L');
			dfs(item->leftChild);
		}
		if (item->rightChild)
		{
			printf("%c", 'R');
			dfs(item->rightChild);

		}
	}
	*/
	void LL(iterator roatePoint)
	{
		if (roatePoint->rightChild != NULL)
		{
			roatePoint->parent->leftChild = roatePoint->rightChild;
			roatePoint->rightChild = roatePoint->parent;
		}
		else
		{
			roatePoint->rightChild = roatePoint->parent;
		}
	}

	void LR(iterator roatePoint)
	{
		
	}
	void RL(iterator roatePoint)
	{

	}

	void RR(iterator roatePoint)
	{
		if (roatePoint->leftChild != NULL)
		{
			roatePoint->parent->rightChild = roatePoint->leftChild;
			roatePoint->leftChild = roatePoint->parent;
		}
		else
		{
			roatePoint->leftChild = roatePoint->parent;
		}
	}
};