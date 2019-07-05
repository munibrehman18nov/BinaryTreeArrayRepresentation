#include<iostream>
using namespace std;
#include"BinaryTree.h"

int main()
{
	BinaryTree<int>T(4);
	T.setRoot(0);
	T.setLeftChild(0, 1);
	T.setRightChild(0, 9);
	T.setLeftChild(1, 11);
	T.setRightChild(1, 19);
	T.setLeftChild(9, 21);
	T.setRightChild(9, 29);
	T.setLeftChild(11, 31);
	T.setRightChild(11, 39);
	T.setLeftChild(21, 41);
	T.setRightChild(21, 49);
	T.setLeftChild(31, 51);
	T.setRightChild(31, 59);
	T.setLeftChild(29, 61);
	T.setRightChild(29, 69);
	//cout << T.getParent(21) << "\n";
	//T.diplayAncestors(41);
	//T.displayDescendents(9);
	//T.preOrder(); cout << "\n\n";
	T.levelOrder();
	//T.postOrder(); cout << "\n";
	//T.inOrder(); cout << "\n";
	//T.getParent(29);
	//cout << T.heightOfTree();
	//T.displayParenthesizedView();
}