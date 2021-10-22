#ifndef __TREE_H_
	#define __TREE_H_
#include "Node.h"
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>

#define LEFT		1
#define RIGHT		2
#define ROOT		0
#define NOTCHILD	3
#define NIL &(this->leaf)

#define ON	true
#define OFF	false

extern int SPEED;
extern bool tumbler;

class Tree {
	private:
		Node leaf;
		Node *root;
		Node *NewNode(int value);
		void PrintSubtree(Node* root, const std::string& prefix, bool tumbler);
		
		//Родственики
		Node *Parent(Node *&node);
		Node *Grandfather(Node *&node);
		Node *Uncle(Node *&node);

		// Младший или старший ребенок (Левый или Правый)
		int IamLeftOrRight(Node *node);

		//Повороты дерева
		void RotateLeft(Node *node);
		void RotateRight(Node *node);

		//Балансировака после вставки
		void FixInsertion(Node *node);
		// После удаления
		void FixDelete(Node *x);

		//Поиск корня
		Node *FoundRoot(Node *node);
		void FreeTree(Node *rootN);

	public:
		Tree();
		~Tree();

		void InsertNode(T key);
		void DeleteNode(T key);
		
		void PrintGraph(bool tumbler);

		Node *FoundNode(T key);
		Node *Max(Node *rootN);
		const Node *Max(void) const;
		Node *Min(Node *rootN);
		const Node *Min(void) const;

		const Node *Nil();
		const Node *Root();

		void PrintInfo();



};

void ClearTerm();

#endif