#ifndef BINARYTREE_H
#define BINARYTREE_H
#include"BitArray.h"

template<class T>
class BinaryTree
{
	int height;
	T*node;
	BitArray*nodeStatus;
	int maxNodes;
//	T searchParent(T key, int ind);
//	int searchParentInd(T);
	void removeChilds(int i);
	void ancestors(int);
	void descendents(int);
	int measureHeightOfTree(int);
	void VLR(int i);
	void LRV(int i);
	void LVR(int i);
	void parenthesizedView(int);
public:
	
	BinaryTree();
	BinaryTree(int h);
	void setRoot(T v);
	bool isEmpty();
	void setHeight(T h);
	T getRoot();
	void setLeftChild(T parent, T child);
	void setRightChild(T parent, T child);
	T getParent(T node);
	int searchInd(T val);
	void remove(T nod);
	void diplayAncestors(T nod);
	void displayDescendents(T nod);
	int heightOfTree();
	void preOrder();
	void postOrder();
	void inOrder();
	void levelOrder();
	void displayLevel(int levelNo);
	int findLevelOfNode(T nod);
	void displayParenthesizedView();
	void displayExplorerView();

	~BinaryTree();
};

#endif
