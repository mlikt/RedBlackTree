#include "Node.h"
#include <iostream>

class Counter {
	private:
		size_t count_node;
		size_t count_leaves;
		size_t levels;
		size_t tmp;
		size_t *black_height;
		int i;
	public:
	
	Counter();
	~Counter();
	void CountNode(Node *root, size_t i, Node *Nil);
	void InintHeight();
	void BlackHeight(Node *root, size_t count_black, Node *Nil);
	size_t get_count() const;
	void print_info() const ;

};