#include "Tree.hpp"
#include "Counter.hpp"

Tree::Tree(): leaf((Node){0, Black, NIL, 0, NIL}), root(NIL) {}


Tree::~Tree() { FreeTree(this->root); }

Node *Tree::NewNode(int value){
	Node * node = new Node();

	node->value = value;
	node->colour = Red;
	node->Left = NIL;
	node->Right = NIL;
	node->Parent = NIL;

	return (node);
}

const Node* Tree::Nil(){
        return (NIL);
}

const Node *Tree::Root(){
        return (this->root);
}

void Tree::FreeTree(Node *rootN) {

	if (rootN == NIL)
		return ;
	FreeTree(rootN->Left);
	FreeTree(rootN->Right);
        delete rootN;
}

void Tree::PrintGraph(bool tumbler)
{
        if (this->root == NIL)
        {
                return;
        }

        if (this->root->colour == Red) {
                 std::cout << RED << root->value << RESETCOLOR << std::endl;
         } else {
                 std::cout << BLACK << root->value << RESETCOLOR << std::endl;
         }
        PrintSubtree(this->root, "", tumbler);
        std::cout << std::endl;
}

void Tree::PrintSubtree(Node* root, const std::string& prefix, bool tumbler)
{
        if (root == NIL)
        {
                return;
        }
        bool hasLeft; 
        bool hasRight;
        
        if (tumbler) {
                hasLeft = (root->Left != NULL); // NIL - если не хочешь отображать листья
                hasRight = (root->Right != NULL);
        } else {
                hasLeft = (root->Left != NIL); // NIL - если не хочешь отображать листья
                hasRight = (root->Right != NIL);
        }

        if (!hasLeft && !hasRight)
        {
                return;
        }

        std::cout << GREEN << prefix << RESETCOLOR << std::flush;
        std::cout << BLUE << ((hasLeft  && hasRight) ? "├── " : "") << RESETCOLOR << std::flush;
        std::cout << BLUE <<  ((!hasLeft && hasRight) ? "└── " : "") << RESETCOLOR << std::flush;

        if (hasRight)
        {
                bool printStrand = (hasLeft && hasRight && (root->Right->Right != NULL || root->Right->Left != NULL));
                std::string newPrefix = prefix + (printStrand ? "│   " : "    ");
                if (root->Right == NIL){
                        std::cout << BLACK << "NIL" << RESETCOLOR << std::endl;
                } else if (root->Right->colour == Red) {
                        std::cout << RED << root->Right->value << RESETCOLOR << std::endl;
                } else {
                        std::cout << BLACK << root->Right->value << RESETCOLOR << std::endl;
                }
                PrintSubtree(root->Right, newPrefix, tumbler);
        }

        if (hasLeft)
        {
                std::cout << GREEN << (hasRight ? prefix : "") << "└── " << RESETCOLOR;
                if (root->Left == NIL){
                        std::cout << BLACK << "NIL" << RESETCOLOR << std::endl;
                }
                else if (root->Left->colour == Red) {
                        std::cout << RED << root->Left->value << RESETCOLOR << std::endl;
                } else {
                        std::cout << BLACK << root->Left->value << RESETCOLOR << std::endl;
                }
                PrintSubtree(root->Left, prefix + "    ", tumbler);
        }
}

void Tree::PrintInfo(){
       	Counter counter;
	counter.CountNode(root, 0, NIL);
	counter.InintHeight();
	counter.BlackHeight(root, 0, NIL);
        std::cout << YELLOW << std::flush;
	std::cout << "Информация о дереве:" << std::endl;
	counter.print_info(); 
        std::cout << RESETCOLOR << std::flush;
}