#include "BinaryTree.h"
#include"NotAllowed.h"
#include"Queue.h"
#include<iostream>
using namespace std;

template <class T>
BinaryTree<T>::BinaryTree()
{
	height = 0; maxNodes = pow(2.0, height) - 1; node = 0; nodeStatus = 0;
}


template <class T>
BinaryTree<T>::BinaryTree::~BinaryTree()
{
	if (!node)
		return;
	delete node;
	node = 0;
	delete nodeStatus;
	nodeStatus = 0;
}
template <class T>
BinaryTree<T>::BinaryTree(int h)
{
	height = h;
	maxNodes = pow(2.0, h) - 1;
	node = new T[maxNodes];
	nodeStatus = new BitArray(maxNodes);
}
template <class T>
void BinaryTree<T>::setRoot(T v)
{
	node[0] = v; nodeStatus->on(0);
}
template <class T>
bool BinaryTree<T>::isEmpty()
{
	if (!node)
		return true;
	return false;
}
template <class T>
void BinaryTree<T>::setHeight(T h)
{
	maxNodes = pow(2.0, h) - 1; height = h; nodeStatus = new BitArray(maxNodes); node = new T[pow(2.0, (double)h - 1)];
}
template <class T>
T BinaryTree<T>::getRoot()
{
	try
	{
		if (!node[0])
			throw NotAllowed("Root Not Exist");
		return node[0];
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
}
template <class T>
void BinaryTree<T>::setLeftChild(T parent, T child)
{
	int i = searchInd(parent);
	bool flag = false;
	if (i != -1 && (2 * i + 1) < maxNodes)
	{
		node[2 * i +1] = child;
		nodeStatus->on(2 * i +1);
		flag = true;
	}
	if (flag == false)
		return;
}
template <class T>
void BinaryTree<T>::setRightChild(T parent, T child)
{
	int i=searchInd(parent);
	bool flag = false;
	if (i != -1 && (2 * i + 1) < maxNodes)
	{
		node[2 * i +2] = child;
		nodeStatus->on(2 * i +2);
		flag = true;
	}
	if (flag == false)
		return;
}

template <class T>
int BinaryTree<T>::searchInd(T val)
{
	bool flag = false;
	int i = 0;
	while (flag != true && i < maxNodes)
	{
		if (node[i] == val)
		{
			flag = true;
		}
		i++;
	}
	if (flag == true)
		return i - 1;
	return -1;
}


template <class T>
T BinaryTree<T>::getParent(T nod)
{
	int i = -1;
	i = searchInd(nod);
	try
	{
		if (i == -1)
		{
			throw(NotAllowed("Not Found"));
		}
		if (i % 2 == 0)
			i = i / 2 - 1;
		else
			i = i / 2;
		return node[i];
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
}

template <class T>
void BinaryTree<T>::removeChilds(int i)
{
	if (2 * i + 1 < maxNodes && nodeStatus->checkBitStatus(2 * i + 1))
	{
		removeChilds(2 * i + 1);
		nodeStatus->off(2 * i + 1);
	}
	if (2 * i + 2 < maxNodes && nodeStatus->checkBitStatus(2 * i + 2))
	{
		removeChilds(2 * i + 2);
		nodeStatus->off(2 * i + 2);
	}

}
template <class T>
void BinaryTree<T>::remove(T nod)
{
	if (nod)
	{
		int index = searchInd(nod);
		removeChilds(index);
		nodeStatus->off(index);
	}
}

template <class T>
void BinaryTree<T>::ancestors(int i)
{
	if (i <= 0)
		return;
	if (i % 2 == 1 && (i - 1) / 2 > -1 && nodeStatus->checkBitStatus((i - 1) / 2))
	{
		cout << node[(i-1) / 2] << " ";
		ancestors((i - 1) / 2);
	}
	else if (i % 2 == 0 && (i - 2) / 2 > -1 && nodeStatus->checkBitStatus((i - 2) / 2))
	{
		cout << node[(i - 2) / 2] << " ";
		ancestors((i - 2) / 2);
	}
}
template <class T>
void BinaryTree<T>::diplayAncestors(T nod)
{
	int i = searchInd(nod);
	if (i > -1)
	{
		ancestors(i);
	}
}
template <class T>
void BinaryTree<T>::descendents(int i)
{
	if (2 * i + 1  <maxNodes && nodeStatus->checkBitStatus(2 * i + 1))
	{
		cout << node[2 * i + 1] << " ";
		descendents(2 * i + 1);
	}
	if (2 * i + 2 < maxNodes && nodeStatus->checkBitStatus(2 * i + 2))
	{
		cout << node[2 * i + 2] << " ";
		descendents(2 * i + 2);
	}
}

template <class T>
void BinaryTree<T>::displayDescendents(T nod)
{
	int i = searchInd(nod);
	if (i > -1)
	{
		descendents(i);
	}
}

template <class T>
int BinaryTree<T>::measureHeightOfTree(int i)
{
	if (node == 0)
		return 0;
	int h1 = 1, h2 = 1;
	if (2 * i + 1 < maxNodes && nodeStatus->checkBitStatus(2 * i + 1))
	{
		h1 = h1 + measureHeightOfTree(2 * i + 1);
	}
	if (2 * i + 2 < maxNodes && nodeStatus->checkBitStatus(2 * i + 2))
	{
		h2 = h2 + measureHeightOfTree(2 * i + 2);
	}
	return h1 > h2 ? h1 : h2;
}
template <class T>
int BinaryTree<T>::heightOfTree()
{
	return measureHeightOfTree(0);
}
template <class T>
void BinaryTree<T>::VLR(int i)
{
	if (!node)
		return;
	cout << node[i] << " ";
	if ((2*i+1 < maxNodes) && (nodeStatus->checkBitStatus(2 * i +1)))
	{
		VLR(2 * i +1);
	}
	if ((2 * i + 2 < maxNodes) && (nodeStatus->checkBitStatus(2 * i + 2)))
	{
		VLR(2 * i +2);
	}
}
template <class T>
void BinaryTree<T>::LRV(int i)
{
	if (!node)
		return;
	if ((2 * i + 1 < maxNodes) && (nodeStatus->checkBitStatus(2 * i + 1)))
	{
		LRV(2 * i + 1);
	}
	if ((2 * i + 2 < maxNodes) && (nodeStatus->checkBitStatus(2 * i + 2)))
	{
		LRV(2 * i + 2);
	}
	cout << node[i] << " ";
}
template <class T>
void BinaryTree<T>::LVR(int i)
{
	if (!node)
		return;
	if ((2 * i + 1 < maxNodes) && (nodeStatus->checkBitStatus(2 * i + 1)))
	{
		LVR(2 * i + 1);
	}
	cout << node[i] << " ";
	if ((2 * i + 2 < maxNodes) && (nodeStatus->checkBitStatus(2 * i + 2)))
	{
		LVR(2 * i + 2);
	}
}
template <class T>
void BinaryTree<T>::preOrder()
{
	VLR(0);
}
template <class T>
void BinaryTree<T>::postOrder()
{
	LRV(0);
}
template <class T>
void BinaryTree<T>::inOrder()
{
	LVR(0);
}

template <class T>
void BinaryTree<T>::levelOrder()
{
	if (!isEmpty())
	{
		Queue<T> q;
		int i = 0;
		q.enQueue(node[i]);
		while (!q.isEmpty())
		{
			cout << q.deQueue() << " ";
			if (nodeStatus->checkBitStatus(2 * i + 1))
			{
				q.enQueue(node[(2 * i) + 1]);
			}
			if (nodeStatus->checkBitStatus(2 * i + 2))
			{
				q.enQueue(node[(2 * i) + 2]);
			}
			i++;
		}
	}
	else
		throw exception();
}
template <class T>
void BinaryTree<T>::displayLevel(int levelNo)
{

}
template <class T>
int BinaryTree<T>::findLevelOfNode(T node)
{
	return 0;
}
template <class T>
void BinaryTree<T>::parenthesizedView(int i)
{
	if (i >= 0 && i < maxNodes)
	{
		i++;
		while (i < maxNodes)
		{
			for (int a = 1; a <= 11; a++)
			{
				cout << " ";
			}
			cout << "0" << endl;
			i++;

		}
		for (int a = 1; a <= 7; a++)
		{
			cout << " ";
		}
		cout << "/";
		//for (int a = 1; a <= 7; a++)
		{
			//	cout << " ";
		}
		cout << " \\ " << endl;
		i++;
	}
}
template <class T>
void BinaryTree<T>::displayParenthesizedView()
{
	parenthesizedView(0);
}
template <class T>
void BinaryTree<T>::displayExplorerView()
{

}
template BinaryTree<int>;