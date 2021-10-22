#include "Tree.hpp"

void Tree::FixInsertion(Node *node){
	
	if (Parent(node) == NIL) {
		node->colour = Black;
		return ;
	}

	while (Parent(node)->colour == Red)
	{
		if (IamLeftOrRight(Parent(node)) == LEFT){
			if (Uncle(node)->colour == Red){
				Parent(node)->colour = Black;
				Uncle(node)->colour = Black;
				Grandfather(node)->colour = Red;
				node = Grandfather(node);
			} else {
					if (IamLeftOrRight(node) == RIGHT){
						node = Parent(node);
						RotateLeft(node);
					}
				Parent(node)->colour = Black;
				Grandfather(node)->colour = Red;
				RotateRight(Grandfather(node));
			}
		} else if (IamLeftOrRight(Parent(node)) == RIGHT) {
			if (Uncle(node)->colour == Red) {
				Parent(node)->colour = Black;
				Uncle(node)->colour = Black;
				Grandfather(node)->colour = Red;
				node = Grandfather(node);
			} else {
					if (IamLeftOrRight(node) == LEFT) {
						node = Parent(node);
						RotateRight(node);
					}
				Parent(node)->colour = Black;
				Grandfather(node)->colour = Red;
				RotateLeft(Grandfather(node));
			}
		}
	}

	this->root = FoundRoot(node);
	this->root->colour = Black;
	
}

Node *Tree::FoundRoot(Node *node){
	while (Parent(node) != NIL)
	{
		node = Parent(node);
	}
	return (node);
}