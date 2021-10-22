#include "Tree.hpp"


void Tree::RotateLeft(Node *node) {
	if (node == NIL)
		return;
	Node	*right = node->Right;
	Node	*left = NIL;
	left = right->Left;
	if (right != NIL) 
		right->Parent = node->Parent;

	if (Parent(node) != NIL){

		if (IamLeftOrRight(node) == RIGHT) {
			Parent(node)->Right = right;
		}
		else if (IamLeftOrRight(node) == LEFT) {
			Parent(node)->Left = right;
		}
	}

	if (left != NIL)
		left->Parent = node;
	
	if (node != NIL) {
		node->Right		= left;
		node->Parent 	= right;
	}

	right->Left		= node;
}

void Tree::RotateRight(Node *node) {
	Node	*left = node->Left;
	Node	*right = NIL;
	right = left->Right; 
	if (left != NIL)
		left->Parent = node->Parent;

	if (Parent(node) != NIL){
		if (IamLeftOrRight(node) == RIGHT) {
			Parent(node)->Right = left;
		} else if (IamLeftOrRight(node) == LEFT) {
			Parent(node)->Left = left;
		}
	}

	if (right != NIL)
		right->Parent = node;

	if (node != NIL) {
		node->Left = right;
		node->Parent = left;
	}

	left->Right  = node;
}
