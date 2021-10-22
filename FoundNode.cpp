#include "Tree.hpp"

Node *Tree::FoundNode(T key) {
	Node *end = this->root;

	while (end != NIL) {
		if (end->value > key)
			end = end->Left;
		else if (end->value < key)
			end = end->Right;
		else
			return (end);
	}
	return (NIL);
}

Node *Tree::Max(Node * const rootN) {
	if (rootN == NIL)
		return (rootN);
	Node *tmp = rootN;
	while (tmp->Right != NIL)
		tmp = tmp->Right;
	return (tmp);
}

Node *Tree::Min(Node *const rootN) {
	if (rootN == NIL)
		return (rootN);
	Node *tmp = rootN;
	while (tmp->Left != NIL)
		tmp = tmp->Left;
	return (tmp);
}

const Node *Tree::Max(void) const {
	Node *tmp = this->root;
	while (tmp->Right != NIL)
	{
		tmp = tmp->Right;
	}
	return (tmp);
}
