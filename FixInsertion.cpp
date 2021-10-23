#include "Tree.hpp"

void Tree::FixInsertion(Node *node){
	
	if (Parent(node) == NIL) {
		node->colour = Black;
		return ;
	}
	while (Parent(node)->colour == Red)
	{		
		ClearTerm();
		std::cout << "Построение дерева" << std::endl;
		this->root = FoundRoot(node);
		this->PrintGraph(tumbler);
		this->PrintInfo();

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
		std::this_thread::sleep_for(std::chrono::milliseconds(SPEED));
	}
	ClearTerm();
	std::cout << "Построение дерева" << std::endl;
	this->root = FoundRoot(node);
	this->root->colour = Black;
	this->PrintGraph(tumbler);
	this->PrintInfo();
	ClearTerm();
}

Node *Tree::FoundRoot(Node *node){
	while (Parent(node) != NIL)
	{
		node = Parent(node);
	}
	return (node);
}