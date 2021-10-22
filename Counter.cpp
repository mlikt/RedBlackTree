#include "Counter.hpp"


Counter::Counter():count_node(0L), count_leaves(0L), levels(0), tmp(0), black_height(0) {}
void Counter::CountNode(Node *root, size_t i, Node *Nil){
	
	if (root == Nil) {
		
		if (i > levels)
			levels = i;
		return ;
	}
	count_node++;
	CountNode(root->Left, i + 1, Nil);
	CountNode(root->Right, i + 1, Nil);
	if (tmp < count_node) {
	tmp = count_node;
	count_leaves = count_node + 1;
	}
}

void Counter::InintHeight(){
	this->black_height = new size_t[count_leaves]();
	this->i = 0;
}

void Counter::BlackHeight(Node *root, size_t count_black, Node *Nil){
	if (root != Nil && root->colour == Black)
		count_black++;
	if (root != Nil && (root->Left == Nil || root->Right == Nil)) {
		if (root->Left == Nil){
			black_height[this->i] = count_black;
			this->i++;
		}
		if (root->Right == Nil){
			black_height[this->i] = count_black;
			this->i++;
		}
	}
	if (root == Nil)
		return ;
	BlackHeight(root->Left, count_black, Nil);
	BlackHeight(root->Right, count_black, Nil);

}
size_t Counter::get_count() const {
	return (count_node);
}
void Counter::print_info() const {
	bool check = false;
	std::cout << "Кол-во узлов         -> " << count_node << std::endl;
	std::cout << "Кол-во листьев       -> " << count_leaves << std::endl;
	std::cout << "Высота дерева        -> " << levels << std::endl;
	for (size_t i = 0; i < count_leaves; i++)
	{
		if (black_height[0] == black_height[i])
			check = true;
		else {
			check = false;
			break;
		}
	}
	if (check)
		std::cout << "Черная высота        -> " << black_height[0] << std::endl;
	else
		std::cout << "Черная высота нарушена" << std::endl;
}

Counter::~Counter(){
	delete [] black_height;
};
