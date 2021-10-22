#include "Tree.hpp"

void Tree::InsertNode(T key){

	Node *tmp = this->root;
	Node *node = this->NewNode(key);

	if (tmp == NIL) {
		root = node;
		root->colour = Black;
		return ;
	}

	while (tmp != NIL) {
		if (tmp->value > node->value)
		{
			if (tmp->Left == NIL) {
				tmp->Left = node;
				node->Parent = tmp;
				break;
			}
			tmp = tmp->Left;
		}
		else if (tmp->value < node->value)
		{
			if (tmp->Right == NIL) {
				tmp->Right = node;
				node->Parent = tmp;
				break;
			}
			tmp = tmp->Right;
		}
		else {
			delete node;
			break;
		}
	}
	FixInsertion(node);
}