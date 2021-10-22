#include "Tree.hpp"

int Tree::IamLeftOrRight(Node *node) {
	if (node && !node->Parent)
		return (ROOT);
	if (node && node->Parent && node->Parent->Left == node)
		return (LEFT);
	if (node && node->Parent && node->Parent->Right == node)
		return (RIGHT);
	return (NOTCHILD);
}

Node *Tree::Parent(Node *&node){
	if (node != NIL)
		return (node->Parent);
	else if (node->Parent == NIL)
		return (NIL);
	return (NIL);
}

Node *Tree::Grandfather(Node *&node){
	if (node != NIL && Parent(node))
		return (node->Parent->Parent);
	else
		return (NIL);
}

Node *Tree::Uncle(Node *&node) {
	Node *grand = Grandfather(node);
	if (grand == NIL)
		return (NIL);
	if (grand->Left == Parent(node))
		return grand->Right;
	else
		return grand->Left;
}