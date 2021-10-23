#include "Tree.hpp"

void Tree::InsertNode(T key){

	Node *tmp = this->root;
	Node *node = this->NewNode(key);

	if (tmp == NIL) {
		root = node;
		ClearTerm();
		std::cout << "Построение дерева" << std::endl;
		this->PrintGraph(tumbler);
		this->PrintInfo();
		std::this_thread::sleep_for(std::chrono::milliseconds(SPEED));
		root->colour = Black;
		ClearTerm();
		std::cout << "Построение дерева" << std::endl;
		this->PrintGraph(tumbler);
		this->PrintInfo();
		std::this_thread::sleep_for(std::chrono::milliseconds(SPEED));
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

	ClearTerm();
	std::cout << "Построение дерева" << std::endl;
	this->PrintGraph(tumbler);
	this->PrintInfo();
	std::this_thread::sleep_for(std::chrono::milliseconds(SPEED));
	FixInsertion(node);
}